#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
ll dp[11][1000005];

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=9; ++i) dp[i][1] = 1;
    for (int len=2; len<=n; ++len) {
        for (int j=1; j<=9; ++j) {
            dp[j][len] += dp[j-1][len-1] + dp[j+1][len-1] + dp[j][len-1];
            dp[j][len] %= MOD;
        }
    }    
    ll sum = 0;
    for (int i=1; i<=9; ++i) {
        sum += dp[i][n];
        sum %= MOD;
    }
    cout << sum << '\n';
    return 0;
}