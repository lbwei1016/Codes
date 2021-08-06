/*
***DP***
    Solution:
        x+2y+2z=n => x+2(y+z)=n
        先算 x + y'= n 的方法數，再求 y + z = y'
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
int n;
long long dp[N];

int main() {
    dp[0] = dp[1] = 1;
    for(int i=2; i<N; i++) {
        if(i & 1) dp[i] = dp[i-1];
        else dp[i] = dp[i-2] + i/2 + 1;
    }
    while(scanf("%d", &n) == 1) {
        printf("%lld\n", dp[n]);
    }
    return 0;
}