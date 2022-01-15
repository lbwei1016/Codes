#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, a[N];
    cin >> t;
    while(t--) {
        ll pow2cnt = 0, sum = 0;
        cin >> n;
        for(int i=0; i<n; ++i) {
            cin >> a[i];
            while(a[i] % 2 == 0) {
                a[i] /= 2;
                ++pow2cnt;
            }
        }
        sort(a, a+n);
        a[n-1] *= pow(2, pow2cnt);
        for(int i=0; i<n; ++i) {
            sum += a[i];
        }
        cout << sum << '\n';
    }
    return 0;
}