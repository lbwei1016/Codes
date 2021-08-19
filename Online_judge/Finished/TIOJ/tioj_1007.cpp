/*
***DP***
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 15+1, M = 90+1;
ll dp[M][N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    dp[1][0] = dp[1][1] = 1;
    // pos: 0 ~ m
    for(int i=2; i<=m; ++i) {
        for(int j=1; j<=n&&j<=i; ++j) {
            dp[i][j] = dp[i-1][j-1];
        }
        for(int j=0; j<=n&&j<=i; ++j) dp[i][0] += dp[i-1][j];
    }
    ll res = 0;
    for(int i=0; i<=n; ++i) res += dp[m][i];
    printf("%lld\n", res);
    return 0;
}