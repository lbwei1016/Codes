/*
***DP*** -- tcirc_d086
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int a[55], dp[55][55]; // dp[i][j]: min cost in range [i, j]
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for(int len=2; len<n; len++) {
        for(int i=0; i+len<n; i++) {
            int j = i+len, mn = 1e9;
            // k is the last position of multiplication
            for(int k=i+1; k<j; k++) {
                mn = min(mn, dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
            }
            dp[i][j] = mn;
        }
    }
    printf("%d\n", dp[0][n-1]);
    return 0;
}