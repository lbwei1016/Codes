#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    multiset<ll> S;
    int q;
    cin >> q;
    while (q--) {
        int c;
        ll x; 
        cin >> c >> x;
        if (c > 1) {
            int k; cin >> k;
            // auto it = S.upper_bound(x);
            multiset<ll>::iterator it;
            if (c == 2) {
                it = S.upper_bound(x);
                while (it != S.begin() && k > 0) {
                    --it;
                    --k;
                }
            }
            else {
                it = S.lower_bound(x);
                --k;
                while (it != S.end() && k > 0) {
                    ++it;
                    --k;
                }
            }
            if (k > 0 || it == S.end()) puts("-1");
            else cout << (*it) << '\n';
        }
        else {
            S.insert(x);
        }
    }
    return 0;
}