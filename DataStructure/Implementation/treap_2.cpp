/*
***Treap*** (zj_a063)
    Description:
        給定一序列及 M 次修改，每次修改給兩數 l, r，並反轉位於 [l, r] 的子序列 。
        求 M 次操作後的序列。
    Solution:
        每次反轉可看作從 treap 上拆出一棵子樹、交換該子樹根的左右子樹、最後合併回去。

        由於操作過程中牽涉交換子樹，用 key 值存節點在序列中的位置顯得不恰當(BST 性質被破壞)，
        但這並不會造成困擾，因為這棵 treap 實際上正是一棵笛卡爾樹，也就是一次 
        inorder traversal 就可以由左至右遍歷序列元素；於是樹與序列的對應改為從數的大小著手。

        由於是笛卡爾樹，某點的左子樹大小即代表序列中在該點左方的元素數量，右方亦然；因此在拆分
        treap 時看的正是左(右)子樹大小來決定切割點。

        這裡用到了延遲標記(mark)，標示區間是否應反轉而未反轉，並在 merge、split、trav 之前
        都先向下 push。
    Time Complexity:
        Build treap: O(n)
        Query: O(log n)
        Total: O(n + mlog n)
*/
#include <bits/stdc++.h>
using namespace std;

mt19937 mt(time(NULL));

struct treap {
    int val, pri, sz;
    bool mark;
    treap *l, *r;
    treap(int _v, int _p): sz(1), val(_v), pri(_p) {
        mark = 0;
    }
};

int getSize(treap *at) {
    if (!at) return 0;
    else return at->sz;
}

void calcSize(treap *at) {
    at->sz = getSize(at->l) + getSize(at->r) + 1;
}

void heapify(treap *at) {
    if (at == nullptr) return;
    treap *mx = at;
    if (at->l != nullptr && at->l->pri > mx->pri)
        mx = at->l;
    if (at->r != nullptr && at->r->pri > mx->pri)
        mx = at->r;
    if (mx != at) {
        swap(at->pri, mx->pri);
        heapify(mx);
    }
}

treap* build(int n, int off) {
    if (n == 0) return nullptr;
    int mid = n / 2, k = mid + off;
    treap *at = new treap(k+1, mt());
    at->l = build(mid, off);
    at->r = build(n-mid-1, off+mid+1);
    calcSize(at);
    heapify(at);
    return at;
}

void push(treap *at) {
    if (at->mark) {
        if (at->l) at->l->mark ^= 1;
        if (at->r) at->r->mark ^= 1;
        swap(at->l, at->r);
        at->mark = false;
    }
}

treap* merge(treap *a, treap *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->pri > b->pri) {
        push(a);
        a->r = merge(a->r, b);
        calcSize(a);
        return a;
    }
    push(b);
    b->l = merge(a, b->l);
    calcSize(b);
    return b;
}    

void split(treap *at, const int k, treap *&a, treap *&b) {
    if (!at) {
        a = b = nullptr;
        return;
    }
    push(at); // 要先 push 才能正確算出 getSize(at->l) !!!
    if (getSize(at->l) < k) {
        a = at;
        split(at->r, k-getSize(at->l)-1, a->r, b);
        calcSize(a);
    }
    else {
        b = at;
        split(at->l, k, a, b->l);
        calcSize(b);
    }
}

treap* update(treap *at, int l, int r) {
    treap *lt, *rt, *tmp;
    split(at, l-1, lt, rt);
    split(rt, r-l+1, at, tmp); // result is in *at
    at->mark ^= 1;
    at = merge(lt, at); at = merge(at, tmp);
    return at;
}

void trav(treap *at) {
    if (!at) return;
    push(at);
    trav(at->l);
    printf("%d ", at->val);
    trav(at->r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    treap *at = build(n, 0);
    while (q--) {
        int l, r;
        cin >> l >> r; 
        at = update(at, l, r);
    }
    trav(at);
    return 0;
}