/*
***DP*** -- Local alignment
    Description:
        Given two sequences, determine the "similarity" of them by comparing
        the consecutive characters¡Fhowever, we can arbituarily put "spaces"
        in the sequences to make a "gap".The "similarity" is determined by
        the "weight" three conditions:
            s[i] = t[j]: +8
            s[i] != t[j]: -5 or -3(space)

    O(n * m)
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    char s1[505], s2[505];
    int dp[505][505];
    int mx = 0;
    scanf("%s%s", s1, s2);
    int n = strlen(s1), m = strlen(s2);
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 8;
            } else {
                //"0" is for "local" alignment, for we can decide not to choose any subsequences
                dp[i][j] = max(0, max(dp[i-1][j]-3, max(dp[i][j-1]-3, dp[i-1][j-1]-5)));
            }
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx << '\n';
    return 0;
}