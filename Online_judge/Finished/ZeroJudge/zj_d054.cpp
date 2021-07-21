/*
***DP***
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t, n;
ll dp[45];
int main() {
    dp[0] = dp[1] = 1, dp[2] = 5;
    for(int i=3; i<=40; i++) {
        dp[i] = dp[i-1] + dp[i-2]*4LL + dp[i-3]*2LL;
    }
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}