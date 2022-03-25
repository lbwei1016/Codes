#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
int dp[int(1e6+5)];

int main() {
    // io;
    int n, x, c;
    cin >> n >> x;
    dp[0] = 1;
    for (int i=0; i<n; ++i) {
        cin >> c;
        for (int j=0; j+c<=x; ++j) {
            dp[j+c] += dp[j];
            dp[j+c] %= MOD;
        } 
    }
    cout << dp[x];
    return 0;
}