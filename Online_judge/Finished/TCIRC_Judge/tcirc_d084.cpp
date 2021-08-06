/*
***DP***
*/
#include <bits/stdc++.h>
using namespace std;

int n, K, x;
int dp[100005];

int main() {
    scanf("%d%d", &n, &K);
    for(int i=1; i<=n; i++) {
        scanf("%d", &x);
        if(i < K+1) dp[i] = max(x, dp[i-1]);
        //只需檢查 dp[i-1]，因為前面已經將最大值推至 dp[i-1]
        else dp[i] = max(dp[i-K-1] + x, dp[i-1]);
    }
    printf("%d\n", dp[n]);
    return 0;
}