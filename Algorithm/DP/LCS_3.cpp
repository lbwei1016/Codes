/*
***LCS*** -- reduce momory
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    char s1[1005], s2[1005];
    int dp[1005];
    while(scanf("%s%s", s1, s2) != EOF) {
        int mx = 0;
        memset(dp, 0, sizeof(dp));
        for(int i=0, l1=strlen(s1); i<l1; i++) {
            int p = 0;
            for(int j=1, l2=strlen(s2); j<=l2; j++) {
                int tmp = dp[j];
                if(s1[i] == s2[j-1]) dp[j] = p + 1;
                else dp[j] = max(dp[j], dp[j-1]);
                mx = max(mx, dp[j]);
                p = tmp;
            }
        }
        printf("%d\n", mx);
    }
    
    return 0;
}