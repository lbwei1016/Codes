/*
***DP***
*/
#include <bits/stdc++.h>
using namespace std;

//其實 i, j 順序交換比較好寫
long long dp[10][20]; //0~9 / 18 digits
int main() {
    char s[20];
    int len, i;
    scanf("%s", s);
    len = strlen(s);
    for(int i=0; i<len; i++) 
        s[i] -= '0';
    dp[0][1] = 0;
    for(i=1; i<10; i++) {
        dp[i][1] = 1;
    }
    for(int j=1; j<=len; j++) {
        dp[9][j] = 1;
    }
    for(i=8; i>=0; i--) {
        for(int j=2; j<=len; j++) {
            dp[i][j] = dp[i+1][j] + dp[i][j-1];
        }
    }
    long long ans = 0;
    for(i=0; i<s[0]; i++) {
        ans += dp[i][len];
    }
    for(i=1; i<len; i++) {
        if(s[i] < s[i-1]) break;
        for(int j=s[i-1]; j<s[i]; j++) {
            ans += dp[j][len-i];
        }
    }
    if(i == len) ans++;
    printf("%lld\n", ans);
    return 0;
}