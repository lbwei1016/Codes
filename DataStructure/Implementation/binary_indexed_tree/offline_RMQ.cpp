/*
***Offline RMQ*** -- BIT
    Solution:
        設要查詢的序列為 {ai}。
        先將所有查詢區間 [l, r] 讀進來，並依照左界(l)由大到小排。
        令
            bi = { -INF, i < l
                 {  ai,  i >= l
        從左界大的開始查詢，就相當於查詢 {bi} 的前綴最大值。每當左界將減少 1 時，
        使 bl = al，代表涵蓋該值。
    Complexity:
        Time: O(mlogm + nlogn + mlogn)
        Space: O(n + m)
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;

struct P {
    int l, r, id;
    bool operator<(P &p) const {
        return l == p.l ? r > p.r : l > p.l;
    }
};

vector<int> bit;

void update(int n, int i, int val) {
    while (i <= n) {
        bit[i] = max(bit[i], val);
        i += (i & -i);
    }
}

int query(int i) {
    int mx = 0;
    while (i > 0) {
        mx = max(mx, bit[i]);
        i -= (i & -i);
    }
    return mx;
}

int main() {
    io;
    int n, m; cin >> n;
    bit.assign(n+1, -INT_MAX);
    vector<int> A(n+1);
    for (int i=1; i<=n; ++i) cin >> A[i];
    
    cin >> m;
    vector<P> que(m);
    for (int i=0; i<m; ++i) {
        int l, r; cin >> l >> r;
        if (l > r) swap(l, r);
        que.push_back(P{l, r, i});
    }
    sort(que.begin(), que.end());

    P pre = {n, n, -1};
    vector<int> B(n+1), res(m);
    for (int i=0; i<m; ++i) {
        auto p = que[i];
        while (pre.l >= p.l) {
            B[pre.l] = A[pre.l];
            update(n, pre.l, B[pre.l]);
            --pre.l;
        }
        res[p.id] = query(p.r);
        pre = p;
    }
    for (auto x: res) cout << x << '\n';
    return 0;
}