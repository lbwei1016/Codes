#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
#define LC(v) (2*(v)+1)
#define RC(v) (2*(v)+2)
using namespace std;
using ll = long long;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int N;

void update(int v, int l, int r, int at, int val, vector<int> &seg, int f(int, int)) {
    if (r-l == 1) {
        seg[v] = val;
        return;
    }
    int mid = (l+r) / 2;
    if (at < mid) update(LC(v), l, mid, at, val, seg, f);
    else update(RC(v), mid, r, at, val, seg, f);

    seg[v] = f(seg[LC(v)], seg[RC(v)]);
}

int query(int v, int l, int r, int ql, int qr, vector<int> &seg, int f(int, int)) {
    if (ql <= l && r <= qr) return seg[v];

    int mid = (l+r) / 2;
    if (qr <= mid)
        return query(LC(v), l, mid, ql, qr, seg, f);
    else if (ql >= mid)
        return query(RC(v), mid, r, ql, qr, seg, f);
    else 
        return f(query(LC(v), l, mid, ql, qr, seg, f), query(RC(v), mid, r, ql, qr, seg, f));
}

int fun(vector<int> &v, vector<int> &pmax, vector<int> &pmin, map<int, int> &mp) {
    int at = 0, cnt = 0, n = v.size();
    while (true) {
        int i;
        int mx = query(0, 0, N, at, n, pmax, max);
        int mn = query(0, 0, N, at, n, pmin, min);
        if (v[at] == mx) {
            i = mp[mn];
        }
        else if (v[at] == mn) {
            i = mp[mx];
        }
        else i = at+1;
        update(0, 0, N, at, 0, pmax, max);
        update(0, 0, N, at, 1e9+7, pmin, min);

        at = i;
        ++cnt;
        if (at == n-1) return cnt;
    }
}

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        N = 1;
        int n;
        cin >> n;
        vector<int> arr(n);
        while (N < n) N *= 2;
        vector<int> pmax(2*N+5), pmin(2*N+5, 1e9+7);
        map<int, int> mp;
        for (int i=0; i<n; ++i) {
            cin >> arr[i];
            update(0, 0, N, i, arr[i], pmax, max);
            update(0, 0, N, i, arr[i], pmin, min);
            mp[arr[i]] = i;
        }

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        int ans = fun(arr, pmax, pmin, mp);
        cout << ans << '\n';
    }    
    return 0;
}