#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int MAXN = 1e6+5;
const double EPS = 1e-7;
bool is_prime[MAXN];
vector<ll> prime;

void sieve() {
    // memset(is_prime+2, 1, sizeof(is_prime));
    fill(is_prime+2, is_prime+MAXN, 1);
    for (int i=2; i<MAXN; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j=2*i; j<MAXN; j+=i) {
                is_prime[int(j)] = false;
            }
        }
    }
}

int main() {
    // io;
    sieve();

    ll N; cin >> N;
    ll res = 0;
    int sz = prime.size();
    for (int i=sz-1; i>0; --i) {
        ll cube = prime[i] * prime[i] * prime[i];
        if (cube >= N) continue;
        double tmp = N;
        tmp /= cube;

        res += upper_bound(prime.begin(), prime.begin()+i, tmp) - prime.begin();
    }
    cout << res << '\n';
    return 0;
}