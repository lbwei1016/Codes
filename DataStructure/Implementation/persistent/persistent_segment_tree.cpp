/*
***Persistent Data Structure (segment tree)*** -- plus BIT
    Description:
        求區間第 k 小，離線單點修改。
    Solution:
        靜態部分:
        首先考慮 "求前綴第 k 小"。建構一棵線段樹，維護每個數出現的次數:
            設序列 S = {1, 1, 2, 2, 2, 3, 4} => {(1, 2), (2, 3), (3, 1), (4, 1)}，
            此時線段樹存的資訊為:
                            [2 + 3 + 1 + 1]
                           /               \
                       [2 + 2]           [1 + 1]
                      /       \         /       \
                    [2]       [2]      [1]      [1]
            查詢時，只要當前的左子樹區間和 (at->lch->sum) >= k，就往左走，
            反之往右 (同時 k -= lch->sum)；最終走到的 leaf 就是答案。
            (以上即為 "在線段樹上二分搜")
        解區間版本時，可以利用 "用前綴和求區間和" 的想法；維護 n 棵線段樹，第 i 棵線段樹
        維護前綴 [1, i]。查詢 [l, r] 時同時考慮第 (l-1) 和第 r 棵樹，同步在這兩棵樹上二分搜。

        如何同時存 n 棵線段樹? 由於 i-th 和 (i+1)-th 棵線段樹的葉節點只有一個不同，因此只有
        O(log n) 個節點需要更新，也就是 (i+1)-th 棵樹只要比 i-th 棵多存這新的 O(log n) 
        個節點即可 (持久化的精隨)。於是所需空間為 O(nlog n)

        動態部分:
        說到動態前綴和，BIT 非常好用。BIT 的每單位是一棵線段樹，對於任何修改，更新相依的節點
        (如同一般 BIT)，查詢時再加上 BIT 的影響即可。

        重要技巧:
        這裡用到兩個重要技巧:
            1. pseudo pointer (for segment tree)
            2. discretization
        1.  偽指標
            預先配置 memory pool: Node::mem[MEM] 以免去 delete 的麻煩，只需重置 memory pool 
            指標。
        2.  離散化
            因為這裡線段樹儲存的下標並不是 A[i] 的 i，而是 A[i] 這個值本身，且 A[i] 可大至
            INT_MAX，因此確定所有執行中會遇到的數值，並將他們離散化 (重新編號) 可以確保不會
            MLE。
    Complexity:
        Time: 
            O(nlog n + m(log n)(log c)), "log c" 和 BIT 有關
        Space: 
            O(m + nlog n)
    Note:
        另有 "整體二分" 的解法，敬請期待。
*/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

const int MAX_N = 6e4 + 6;
const int MEM = 4e6 + 6;
const int MAX_M = 1e4 + 6;

struct Node {
    static Node mem[MEM]; // memory pool
    static Node *ptr;
    Node *lc, *rc;
    int sum;
    Node(): lc(nullptr), rc(nullptr), sum(0) {}
    Node(Node *_node): lc(_node->lc), rc(_node->rc), sum(_node->sum) {}
    void pull() {
        sum = lc->sum + rc->sum;
    }
};
Node Node::mem[MEM], *ptr = Node::mem; // remember to declare static variable

Node* build(int l, int r) {
    Node *node = new(ptr++) Node();
    if (r - l == 1) return node;
    int mid = (l + r) / 2;
    node->lc = build(l, mid);
    node->rc = build(mid, r);
    return node;
}

// create & copy a node
Node* copy(Node *old) {
    return new(ptr++) Node(old);
}

// persistent (single point update)
// modify 出一條鍊: O(log n)
void modify(Node *at, Node *old, int l, int r, int pos, int val) {
    if (r - l == 1) {
        at->sum += val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos < mid) {
        at->lc = copy(old->lc); // 因為要更新的節點在左邊，所以左邊開點就好
        modify(at->lc, old->lc, l, mid, pos, val);
    }
    else {
        at->rc = copy(old->rc);
        modify(at->rc, old->rc, mid, r, pos, val);
    }
    at->pull();
}

int query(Node *Ltree, Node *Rtree, vector<Node*> &bitL, vector<Node*> &bitR, int l, int r, int k) {
    if (r - l == 1) return l;
    int lsum = Ltree->lc->sum;
    int rsum = Rtree->lc->sum;
    // 考慮修改後 (BIT 的影響)
    for (auto &x: bitL) lsum += x->lc->sum;
    for (auto &x: bitR) rsum += x->lc->sum;

    int mid = (l + r) / 2;
    if (k <= rsum - lsum) {
        // BIT 也要移動
        for (auto &x: bitL) x = x->lc;
        for (auto &x: bitR) x = x->lc;
        return query(Ltree->lc, Rtree->lc, bitL, bitR, l, mid, k);
    }
    else {
        for (auto &x: bitL) x = x->rc;
        for (auto &x: bitR) x = x->rc;
        return query(Ltree->rc, Rtree->rc, bitL, bitR, mid, r, k-(rsum-lsum));
    }
}

struct Query {
    int type, a, b, c;
    void input() {
        cin >> type >> a >> b;
        if (type == 1) cin >> c;
    }
};

Query q[MAX_M]; // off-line
int A[MAX_N];
Node *seg_root[MAX_N]; // segment tree
Node *bit_root[MAX_N]; // BIT

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        ptr = Node::mem; // reallocate
        int n, m; cin >> n >> m; 

        vector<int> v; // all possible values; stored for discretization
        for (int i=1; i<=n; ++i) {
            cin >> A[i]; // 1-indexed
            v.push_back(A[i]);
        }
        for (int i=1; i<=m; ++i) {
            q[i].input();
            // value to be changed
            if (q[i].type == 2) v.push_back(q[i].b);
        }

        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        for (int i=1; i<=n; ++i) {
            // discretize (1-indexed)
            A[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin() + 1;
        }
        for (int i=1; i<=m; ++i) {
            // discretize
            if (q[i].type == 2) 
                q[i].b = lower_bound(v.begin(), v.end(), q[i].b) - v.begin() +1;
        }

        int nn = v.size() + 1; // 左閉右開
        seg_root[0] = build(1, nn); // initial segment tree (cover no elements)
        for (int i=1; i<=n; ++i) {
            seg_root[i] = copy(seg_root[i-1]);
            modify(seg_root[i], seg_root[i-1], 1, nn, A[i], 1); // A[i] 記數 + 1 (自前一棵線段樹更新)
            bit_root[i] = copy(seg_root[0]);
        }
        for (int j=1; j<=m; ++j) {
            if (q[j].type == 3) cout << "7122\n"; // 見題述
            else if (q[j].type == 1) {
                int l = q[j].a, r = q[j].b, k = q[j].c;
                vector<Node*> bitL; // (l-1) 前綴
                vector<Node*> bitR; // r 前綴
                for (int i=r; i>0; i-=(i&(-i))) {
                    bitR.push_back(bit_root[i]);
                }
                for(int i=l-1; i>0; i-=(i&(-i))) {
                    bitL.push_back(bit_root[i]);
                }
                int res = query(seg_root[l-1], seg_root[r], bitL, bitR, 1, nn, k);
                cout << v[res-1] << '\n'; // "v" is 0-indexed
            }
            else if (q[j].type == 2) { 
                int pos = q[j].a, val = q[j].b;
                int del = A[pos]; // 現在變成誰 (離散化後)
                for (int i=pos; i<=n; i+=(i&(-i))) {
                    modify(bit_root[i], bit_root[i], 1, nn, del, -1);
                }
                for (int i=pos; i<=n; i+=(i&(-i))) {
                    modify(bit_root[i], bit_root[i], 1, nn, val, 1);
                }
                A[pos] = q[j].b; // update
            }
        }
    }
    return 0;
}