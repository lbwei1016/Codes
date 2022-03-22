#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int MOD = 1e9+7, X = 1e6+5;
int n, x;
vector<int> coin;
int dp[X];

// recursive version gets TLE, for small value coins is repeatedly counted
// int rec(int sum) {
//     if (sum == x) return 1;
//     for (auto p: coin) {
//         if (p + sum > x) continue;
//         if (dp[p+sum]) {
//             dp[sum] += dp[p+sum];
//             dp[sum] %= MOD;
//         }
//         else {
//             dp[sum] += rec(p+sum);
//             dp[sum] %= MOD;
//         }
//     }
//     return dp[sum];
// }

int main() {
    io;
    cin >> n >> x;
    coin.resize(n);
    for (auto &r: coin) {
        cin >> r;
        dp[r] = 1;
    }
    sort(coin.begin(), coin.end());
    // // for (auto x: coin) cout << x << ' ';
    // cout << rec(0);
    
    for (int i=coin[0]; i<=x; ++i) {
        for (auto p: coin) {
            if (i-p < 0) break;
            dp[i] += dp[i-p];
            dp[i] %= MOD;
        }
    }
    cout << dp[x] << '\n';
    return 0;
}