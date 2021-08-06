/*
***DP*** -- top-down
    Solution:
        以矩陣為主體。
        在範圍 [i, j] 內，選擇 for all k such that i<=k<j，該 k 即是代表最後
        一次乘法發生的位置，將乘法鍊拆成兩半，也就是說，這個遞迴式是倒著做的：
        不斷試驗乘法鍊的可能最後一次乘法結果，再取最小值。

    O(n^3)
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int p[205];
int dp[205][205];
int f(int i, int j) {
    if(dp[i][j] >= 0) return dp[i][j];
    int mn = 1e9;
    for(int k=i; k<j; k++) {
        //point!!!
        //p[i]*p[k+1]*p[j+1]: row(i) * col(k) * col(j)
        mn = min(mn, f(i, k)+f(k+1, j)+p[i]*p[k+1]*p[j+1]);
    }
    return dp[i][j] = mn;
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n+1; i++) {
        scanf("%d", &p[i]);
    }
    memset(dp,-1, sizeof(dp));
    for(int i=0; i<n; i++) {
        dp[i][i] = 0;
    }
    printf("%d\n", f(0, n-1));
    return 0;
}