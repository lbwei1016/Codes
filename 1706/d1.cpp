#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i<n; ++i) cin >> v[i];

    int mmn = 1e9;
    for (int r=0; r<=v[0]; ++r) {
        int mn = r, mx = r;
        for (int i=0; i<n; ++i) {
            int p;
            if (r == 0) {
                p = k;
            }
            else p = min(k, v[i]/r);
            mx = max(mx, v[i]/p);
            mn = min(mn, v[i]/p);
        }
        if (mx-mn < mmn) {
            mmn = mx - mn;
            // cout << "mx: " << mx << "\nmn: " << mn << '\n';
        }
    }
    cout << mmn << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}