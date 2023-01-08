/*
***Persistent Segment Tree (RMexQ)*** -- 陣列寫法
    Note:
        程式碼較指標版稍短(尤其不需 build())，但整體好處不大。
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e6+5;
const int MEM = 3e7+5; // O(nlog(n))
struct Node {
    int lc, rc, val;
    static int ptr;
};
Node seg[MEM]; // 存放線段樹資料的地方
int Node::ptr = 0;
int root[N]; // n 棵線段樹的根

void update(int &at, int old, int l, int r, int pos, int val) {
    at = ++Node::ptr;
    if (r - l == 1) {
        seg[at].val = val;
        return;
    }
    seg[at].lc = seg[old].lc; seg[at].rc = seg[old].rc;
    int mid = (l + r) / 2;
    if (pos < mid) update(seg[at].lc, seg[old].lc, l, mid, pos, val);
    else update(seg[at].rc, seg[old].rc, mid, r, pos, val);
    seg[at].val = min(seg[seg[at].lc].val, seg[seg[at].rc].val);
}

int query(int at, int l, int r, int val) {
    if (r - l == 1) return l;
    int mid = (l + r) / 2;
    if (seg[seg[at].lc].val < val) 
        return query(seg[at].lc, l, mid, val);
    else 
        return query(seg[at].rc, mid, r, val);
}

int main() {
    io;
    int n, m; cin >> n >> m;
    int nn = n + 2;
    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        if (x > n) x = n + 1;
        update(root[i], root[i-1], 0, nn, x, i);
    }
    for (int i=0; i<m; ++i) {
        int l, r; cin >> l >> r;
        cout << query(root[r], 0, nn, l) <<'\n';
    }
    return 0;
}