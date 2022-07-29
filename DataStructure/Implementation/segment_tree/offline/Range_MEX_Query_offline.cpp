/*
***Off-line*** -- Segment Tree
    Description:
        輸出每個查詢區間 [l, r] 內最小沒出現過的非負整數；離線。
    Solution:
        首先觀察，前綴的 mex 是單調的(非遞減)，於是若可以解決前綴
        查詢，或可以在短時間內完成區間查詢；先預處理計算前綴 mex，
        並且將查詢區間依照左界排序(小到大)。接著想，從 [l, r] 到
        [l+1, r] 需要進行甚麼處理 ? 如果 a[l] 在 [l+1, r] 內皆不會
        出現，那麼 [l+1, r] 的 mex 值就有可能是 a[l]；更廣泛來說，
        若 a[i] = a[j], i < j，a[i] 這個數值在 [i+1, j) 之間都有
        可能是區間 mex。於是我們要維護 next[i]，紀錄 a[i] 這個值下
        次出現在甚麼地方。

        依據上述想法，利用線段樹紀錄前綴 mex，並維護一左界: 當左界
        L 移動至 L+1 時更新線段樹，使得 [L+1, next[L]) 的 mex 皆
        小於等於 mex。[l, r] 的區間 mex 於是等同 [1, r] 的答案
        (以上可由區間修改、單點查詢達成)。
    Complexity:
        O(qlog(q) + nlog(n))
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int MEM = 6e6 + 5;
const int INF = 2e9 + 1;
struct Node {
    static Node mem[MEM];
    static Node *ptr;
    Node *lc, *rc;
    int mex;
    Node(int _m = INF): lc(nullptr), rc(nullptr), mex(_m) {}
    void push() {
        if (mex != INF) {
            lc->mex = min(mex, lc->mex);
            rc->mex = min(mex, rc->mex);
            mex = INF;
        }
    }
};
Node Node::mem[MEM], *ptr;
Node *root;

struct Que {
    int l, r, id;
    bool operator<(Que q) const {
        return l < q.l;
    }
};

Node* build(int l, int r, vector<int> &prefix_mex) {
    Node *node = new(ptr++) Node;
    if (r - l == 1) {
        node->mex = prefix_mex[l];
        return node;
    }
    int mid = (l + r) / 2;
    node->lc = build(l, mid, prefix_mex);
    node->rc = build(mid, r, prefix_mex);
    return node;
}

void update(Node *at, int l, int r, int ul, int ur, int val) {
    if (ul <= l && r <= ur) {
        at->mex = min(at->mex, val);
        return;
    }
    at->push();
    int mid = (l + r) / 2;
    if (ur <= mid) update(at->lc, l, mid, ul, ur, val);
    else if (ul >= mid) update(at->rc, mid, r, ul, ur, val);
    else {
        update(at->lc, l, mid, ul, ur, val);
        update(at->rc, mid, r, ul, ur, val);
    }
}

int query(Node *at, int l, int r, int pos) {
    if (r - l == 1) return at->mex;
    at->push();
    int mid = (l + r) / 2;
    if (pos < mid) return query(at->lc, l, mid, pos);
    else return query(at->rc, mid, r, pos);
}

int main() {
    io;    
    ptr = Node::mem;

    int n, m; cin >> n >> m;
    vector<int> v(n), prefix_mex(n);
    vector<bool> vis(n+5, false);
    vector<Que> Q(m);
    unordered_map<int, vector<int>> num_pos;
    int cur_mex = 0;
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        if (v[i] > n) v[i] = n + 1;
        vis[v[i]] = true;
        while (vis[cur_mex]) ++cur_mex;
        prefix_mex[i] = cur_mex;

        num_pos[v[i]].push_back(i);
    }
    for (int i=0; i<m; ++i) {
        int l, r; cin >> l >> r;
        --l; --r;
        Q[i] = {l, r, i};
    }

    vector<int> nxt(n+5);
    for (auto &p: num_pos) {
        auto &pos = p.second; 
        int sz = pos.size();
        pos.push_back(n);
        for (int i=1; i<=sz; ++i) {
            nxt[pos[i-1]] = pos[i];
        }
    }
    
    root = build(0, n, prefix_mex);
    sort(Q.begin(), Q.end());

    int at = 0;
    vector<int> res(m);
    for (int i=0; i<n; ++i) {
        auto q = Q[i];
        while (at < q.l) {
            if (at + 1 < nxt[at])
                update(root, 0, n, at+1, nxt[at], v[at]);
            ++at;
        }
        res[q.id] = query(root, 0, n, q.r);
    }

    for (auto x: res) cout << x << '\n';
    return 0;
}