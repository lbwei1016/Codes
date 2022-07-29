/*
***Persistent Segment Tree***
    Description:
        輸出每個查詢區間 [l, r] 內最小沒出現過的非負整數；離線。
    Solution:
        類似查詢區間第 K 小: 維護 N 棵線段樹，第 i 棵維護出現在前綴 [0, i] 的數值的資訊。
        (注意，如同區間第 K 小，這裡線段樹儲存的下標是整個值域 [0, N+1]，並非區間 index)
        每棵線段樹的葉節點紀錄該數值最後一次出現在序列的哪個位置(最右方)，而其他節點則記錄
        其所轄的區間(值域區間)的最小值(min(last[i]), for all i in [l, r))。
        
        更新為單點更新，把代表該數值的葉節點更新後，再 pull 即可；查詢 [l, r] 時，
        則是查找第 r 棵線段樹中小於 l 的值出現的最左方位置(樹的最左方，因為越左越小，
        而題目求的正是最小)。
    Complexity:
        Time: O((n+q)log(n))
        Space: O(nlog(n))
            這要特別注意，MEM 不可開太小。
    Note:
        可以參考 tioj_1840.cpp
    Comparison:
        本問題共有三種解法:
            (1) Mo's
            (2) off-line segment tree
            (3) persistent segment tree
        時間複雜度: (1) > (2) = (3) (實際時間: (2) < (3))
        空間複雜度: (1) < (2) < (3)
        程式複雜度: (1) < (2) = (3)
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int MEM = 4e7 + 5; // 要夠大!!!
const int N = 2e6 + 5;
const int INF = 2e9 + 7;

struct Node {
    static Node mem[MEM];
    static Node *ptr;
    int val;
    Node *lc, *rc;
    Node(): lc(nullptr), rc(nullptr), val(-1) {}
    Node(Node *_n): lc(_n->lc), rc(_n->rc), val(_n->val) {}
    void pull() {
        val = min(lc->val, rc->val);
    }
};
Node Node::mem[MEM], *ptr = Node::mem;

Node* build(int l, int r) {
    Node *node = new(ptr++) Node;
    if (r - l == 1) return node;
    int mid = (l + r) / 2;
    node->lc = build(l, mid);
    node->rc = build(mid, r);
    return node;
}

Node* copy(Node *old) {
    return new(ptr++) Node(old);
}

void update(Node *at, Node *old, int l, int r, int pos, int val) {
    if (r - l == 1) {
        at->val = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos < mid) {
        at->lc = copy(old->lc);
        update(at->lc, old->lc, l, mid, pos, val);
    }
    else {        
        at->rc = copy(old->rc);
        update(at->rc, old->rc, mid, r, pos, val);
    }
    at->pull();
}

int query(Node *at, int l, int r, int val) {
    if (r - l == 1) return l; // leaf
    int mid = (l + r) / 2;
    // 優先往左
    if (at->lc->val < val) return query(at->lc, l ,mid, val);
    else return query(at->rc, mid, r, val);
}

Node *seg[N];

int main() {
    io;
    ptr = Node::mem;
    int n, m; cin >> n >> m;
    int nn = n + 2;
    seg[0] = build(0, nn);
    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        if (x > n) x = n + 1;
        seg[i] = copy(seg[i-1]);
        update(seg[i], seg[i-1], 0, nn, x, i);
    }
    for (int i=0; i<m; ++i) {
        int l, r; cin >> l >> r;
        cout << query(seg[r], 0, nn, l) << '\n';
    }
    return 0;
}