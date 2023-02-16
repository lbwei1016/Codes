#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353; // prime, recite it.
const int N = 2000 + 5;

// two precalculated hash function
ll hash1[N], hash2[N]; 

void precalc() {
    hash1[0] = hash2[0] = 1;
    for (int i=1; i<N; ++i) {
        // 10007 is prime, while 20007 is not.
        hash1[i] = hash1[i-1] * 10007LL % MOD1;
        hash2[i] = hash2[i-1] * 20007LL % MOD2;
    }
}

int main() {
    io;
    precalc();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> edge(n), val(n);
        for (int i=0; i<n; ++i){
            int u, v; cin >> u >> v;
            if (u > v) swap(u, v); // canonical
            val[i] = (2*n + 1)*u + v; // hashing
            edge[i] = val[i];
        }
        sort(edge.begin(), edge.end());
        edge.resize(unique(edge.begin(), edge.end()) - edge.begin());

        // discretization
        for (int i=0; i<n; ++i) {
            val[i] = lower_bound(edge.begin(), edge.end(), val[i]) - edge.begin();
        }

        ll res = 0;
        // If two graphs are to be isomorphic, they must share the number of edges.
        for (int sz=1; sz<=n; ++sz) {
            unordered_map<ll, ll> mp;
            ll sum1 = 0, sum2 = 0;
            for (int i=0; i<sz; ++i) {
                sum1 += hash1[val[i]];
                sum1 %= MOD1;
                sum2 += hash2[val[i]];
                sum2 %= MOD2;
            }
            mp[sum1 * MOD2 + sum2]++;
            for (int i=sz, j=0; i<n; ++i, ++j) {
                // add one edge and delete the other edge
                sum1 += hash1[val[i]] - hash1[val[j]] + MOD1;
                sum1 %= MOD1;
                sum2 += hash2[val[i]] - hash2[val[j]] + MOD2;
                sum2 %= MOD2;
                mp[sum1 * MOD2 + sum2]++;
            }

            for (auto &p: mp) {
                auto cnt = p.second;
                res += cnt * (cnt - 1) / 2;
            }
        }
        cout << res << '\n';
    }
    return 0;
}