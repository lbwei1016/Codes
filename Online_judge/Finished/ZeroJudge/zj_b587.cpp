/*
***DP***
    Solution:
        n = 2，有 3 種排法；n > 2，只有上下對稱兩種 (由水平放置的方塊橫跨達到無法切割為更小矩形的目的)
*/
#include <bits/stdc++.h>
using namespace std;

int dp[31];
int main() {
    dp[0] = 1, dp[2] = 3;
    for(int i=4; i<=30; i+=2) {
        dp[i] = 4*dp[i-2] - dp[i-4];
    }
    int n;
    while(scanf("%d", &n)) {
        if(n == -1) break;
        printf("%d\n", dp[n]);
    }    
    return 0;
}