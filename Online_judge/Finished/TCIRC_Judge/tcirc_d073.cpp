/*
***DP*** -- 二維最大子矩陣
    Solution:
        先求各行的前綴和，再對列進行列舉 (用 i, j 去夾的範圍)

    O(n * m^2)
*/
#include <bits/stdc++.h>
using namespace std;

int m, n;
int dp[205][205]; //第 k 行第 i 列到第 j 列

int main() {
    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &dp[i][j]);
            dp[i][j] += dp[i-1][j]; //prefix sum
        }
    }
    int mx = 0;
    for(int i=0; i<m; i++) {
        for(int j=i+1; j<=m; j++) {
            int sum = 0;
            for(int k=1; k<=n; k++) { 
                sum += dp[j][k] - dp[i][k];
                sum = max(0, sum);
                mx = max(mx, sum);
            }
        }
    }
    printf("%d\n", mx);
    return 0;
}