/*
***DP***
*/
#include <bits/stdc++.h>
using namespace std;

long long dp[80];
// [2, n+1]
int rec(int n, int pos) {
    if(dp[pos] > 0) return dp[pos];
    if(pos > n+1) return 0;
    else if(pos == n+1 || pos == n) return dp[pos] = 1;

    for(int i=2; i<=3; i++) {
        dp[pos] += rec(n, pos+i);
    }
    return dp[pos];
}
int main() {
    rec(76, 0);
    rec(76, 1);
    int n;
    while(scanf("%d", &n) == 1) {
        if(n == 1) {
            puts("1");
            continue;
        }
        printf("%lld\n", dp[76-n]);
    }
    return 0;
}