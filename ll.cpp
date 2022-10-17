#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

ll n, m, x, y;

int main() {
    io;
    cin >> n >> m >> x >> y;
    vector<ll> hol(m+1);
    for (int i=1; i<=m; ++i) cin >> hol[i];
    hol.push_back(n+1);
    ll cnt = 0, unit = (y + 2);
    ll pmod = 0;
    for (int i=1; i<=m+1; ++i) {
        ll seg = hol[i] - hol[i-1] - 1;
        ll mod = seg % (unit);
        cnt += 2 * (seg / unit);

        ll diff = y - x;
        ll s = max(0LL, pmod - diff);
        if (mod > x - s) {
            cnt++;
            mod -= ((x - s)+1);
        }
        pmod = mod;
    }
    cout << cnt;
    return 0;
}