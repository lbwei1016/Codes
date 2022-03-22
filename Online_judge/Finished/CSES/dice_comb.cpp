#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int MOD = 1e9+7, N = 1e6+5;
int n;
ll dp[N];

ll rec(int sum) {
    if (sum == n) return 1;
    for (int i=1; i<=6; ++i) {
        if (sum + i > n) break; 
        if (dp[sum + i] > 0) {
            dp[sum] += dp[sum + i];
            dp[sum] %= MOD;
            continue;
        }
        dp[sum] += rec(sum + i);
        dp[sum] %= MOD;
    }
    return dp[sum];
}

int main() {
    io;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    cout << rec(0) << '\n'; 
    return 0;
}