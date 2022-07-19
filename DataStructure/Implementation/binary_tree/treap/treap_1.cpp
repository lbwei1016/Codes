/*
***Treap*** (Cartesian Tree 變體)
    Description:
        每一節點存兩個值(如同笛卡爾平面的 x, y): a, b。a 為一般 BST 的 key，b 則是
        可以維持 BST 平衡的值(隨機數)。若單看 a，treap 就是一棵 BST；若單看 b，則是一 
        heap。
    Application:
        保持 BST 不退化, etc.
    Operation:
        build(with heapify): O(n)
        merge: O(log n)
        split: O(log n)
        insert, erase 可由 merge, split 實現: O(log n)
    Note:
        此處實作的是 merge-split treap，常數大但易於實作。
*/
#include <bits/stdc++.h>
using namespace std;

mt19937 mt(time(NULL));

struct treap {
    int key, pri;
    treap *l, *r;
    treap(int _k, int _p): key(_k), pri(_p) {}
};

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

// build a balanced BST from a sorted list "v" (inorder of a BST)
// with heapify(): O(n) + O(n) = O(n)
treap* build(vector<int> &v, int n, int off) {
    if (n == 0) return nullptr;
    int mid = n / 2, k = mid + off;
    treap *at = new treap(v[k], mt());
    at->l = build(v, mid, 0);
    at->r = build(v, n-mid-1, mid+1);
    heapify(at);
    return at;
}

// merge two treap (depends on priority)
// default: a->key < b->key (or say "a" must be on the left of "b")
treap* merge(treap *a, treap *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->pri > b->pri) {
        a->r = merge(a->r, b);
        return a;
    }
    b->l = merge(a, b->l);
    return b;
}    

// split treap "at" from key "k" into "a" and "b" (大於等於 k 和小於 k 的兩樹)
void split(treap *at, const int k, treap *&a, treap *&b) {
    if (!at) a = b = nullptr;
    else if (at->key <= k) {
        a = at;
        split(at->r, k, a->r, b);
    }
    else {
        b = at;
        split(at->l, k, a, b->l);
    }
}

// insert "key" into "at"
treap* insert(treap *at, const int key) {
    treap *a = new treap(key, mt());
    treap *l = nullptr, *r = nullptr;
    split(at, a->key, l, r);
    at = merge(l, a); 
    at = merge(at, r);
    return at;
}

// erase key
void erase(treap *at, const int key) {
    if (at->key == key) {
        treap *tmp = at;
        merge(at->l, at->r);
        delete at;
    }
    else {
        if (key > at->key) erase(at->r, key);
        else erase(at->l, key);
    }
}

int main() {

    return 0;
}