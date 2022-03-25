#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int X = 1e6+5;
int dp[X];

int main() {
    io;
    int n, x;
    cin >> n >> x;
    vector<int> coin(n);
    for (auto &x: coin) cin >> x;
    sort(coin.begin(), coin.end());

    fill(dp, dp+X, 1e9);
    dp[0] = 0;
    for (int i=coin[0]; i<=x; ++i) {
        for (int j=0; j<n; ++j) {
            if (coin[j] > i) break;
            dp[i] = min(dp[i], dp[i-coin[j]] + 1);
        }
    }
    if (dp[x] == 1e9) puts("-1");
    else 
        cout << dp[x] << '\n';
    return 0;
}