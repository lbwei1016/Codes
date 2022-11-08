/*
***Segment Tree*** -- range assignment & range increment & range sum
    Solution:
        重點有三：
        (1) ass 和 add 分開存，比較好實作。
        (2) push() 要先判斷 assigned，再來才判斷 added。
            因為假如有某個區間先被 add 再被 assign，先前 add 的效果
            會被覆蓋，因此只剩 assign。於是任意區間只可能出現 
            assigned、added、assigned and then added 三種情況，因此 
            不論如何 assigned 先判斷才會正確。
        (3) push() 和 pull() 都要做。
*/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define LC(v) (2*(v) + 1)
#define RC(v) (2*(v) + 2)
using ll = long long;
using namespace std;

struct Seg {
    ll val; // range sum
    ll add; // added value
    ll ass; // assigned value
    ll sz; // # of elements in current segment

    bool assigned;
    bool added;
} seg[1 << 20];

vector<ll> vec;

void push(int v) {
    auto &lc = seg[LC(v)], &rc = seg[RC(v)];
    // 先判斷 assigned 再 added
    if (seg[v].assigned) {
        lc.ass = rc.ass = seg[v].ass;
        lc.assigned = rc.assigned = true;
        lc.added = rc.added = false;

        lc.val = rc.val = lc.add = rc.add = 0;

        seg[v].ass = 0;
        seg[v].assigned = false;
    }
    if (seg[v].added) {
        lc.add += seg[v].add;
        rc.add += seg[v].add;
        lc.added = rc.added = true;

        seg[v].added = false;
        seg[v].add = 0;
    }
}

void pull(int v) {
    seg[v].val = seg[LC(v)].val + seg[RC(v)].val;
    seg[v].val += (seg[LC(v)].add + seg[LC(v)].ass) * seg[LC(v)].sz + \
                (seg[RC(v)].add + seg[RC(v)].ass) * seg[RC(v)].sz;
}

void build(int v, int l, int r) {
    seg[v].sz = r - l;
    if (r - l == 1) {
        seg[v].val = vec[l];
        return;
    }
    int mid = (l + r) / 2;
    build(LC(v), l, mid);
    build(RC(v), mid, r);
    pull(v);
}

void update(int v, int l, int r, int ul, int ur, ll val, int op) {
    if (ul <= l && r <= ur) {
        // assign
        if (op == 1) {
            seg[v].assigned = true;
            seg[v].added = false;
            seg[v].ass = val;
            seg[v].val = seg[v].add = 0;
        }
        else {
            seg[v].added = true;
            seg[v].add += val;
        }
        return;
    }

    int mid = (l + r) / 2;
    push(v);
    if (ur <= mid) {
        update(LC(v), l, mid, ul, ur, val, op);
    }
    else if (ul >= mid) {
        update(RC(v), mid, r, ul, ur, val, op);
    }
    else {
        update(LC(v), l, mid, ul, ur, val, op);
        update(RC(v), mid, r, ul, ur, val, op);
    }
    pull(v);
}

ll query(int v, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return seg[v].val + (seg[v].add + seg[v].ass) * seg[v].sz;
    }
    push(v);

    ll res = 0;
    int mid = (l + r) / 2;
    if (qr <= mid) {
        res += query(LC(v), l, mid, ql, qr);
    }
    else if (ql >= mid) {
        res += query(RC(v), mid, r, ql, qr);
    }
    else {
        res += query(LC(v), l, mid, ql, qr) + query(RC(v), mid, r, ql, qr);
    }
    pull(v);
    return res;
}

int main() {
    io;
    int n, q;
    cin >> n >> q;
    vec.resize(n);
    for (int i=0; i<n; ++i) {
        cin >> vec[i];
    } 
    build(0, 0, n);

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        --l;
        // query
        if (op == 3) {
            cout << "The sum is: " << query(0, 0, n, l, r) << '\n';
        }
        else {
            ll val;
            cin >> val;
            // op = 1: add; op = 2: assign
            update(0, 0, n, l, r, val, op-1);
        }
    }
    return 0;
}