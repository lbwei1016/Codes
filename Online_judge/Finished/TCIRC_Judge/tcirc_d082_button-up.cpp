/*
***DP***
    O(m^2 * n^2)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int m, n;
int G[N][N];
int dp[N][N][N][N]; //height, width, top, left

//以下兩函式為刪除邊界的成本
int row_cost(int row, int left, int right) {
    int sum = 0, i;
    for(i=left; i<=right; i++) {
        sum += G[row][i];
    }
    i = right - left + 1;
    if(sum <= i/2) return sum;
    else return i - sum;
}
int col_cost(int col, int top, int but) {
    int sum = 0, i;
    for(i=top; i<=but; i++) {
        sum += G[i][col];
    }
    i = but - top + 1;
    if(sum <= i/2) return sum;
    else return i - sum;
}

int main() {
    scanf("%d%d", &m, &n);
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    //高、寬由小到大；上界、左界遞增
    for(int h=1; h<=m; h++) for(int w=1; w<=n; w++) {
        for(int t=0; t+h<=m; t++) for(int l=0; l+w<=n; l++) {
            if(h == 1 || w == 1) {
                dp[h][w][t][l] = 0;
                continue;
            }
            int mc = dp[h-1][w][t][l] + row_cost(t+h-1, l, l+w-1);
            int cost = dp[h-1][w][t+1][l] + row_cost(t, l, l+w-1);
            mc = min(mc, cost);
            cost = dp[h][w-1][t][l] + col_cost(l+w-1, t, t+h-1);
            mc = min(mc, cost);
            cost = dp[h][w-1][t][l+1] + col_cost(l, t, t+h-1);
            mc = min(mc, cost);
            dp[h][w][t][l] = mc;
        }
    }
    printf("%d\n", dp[m][n][0][0]);
    return 0;
}