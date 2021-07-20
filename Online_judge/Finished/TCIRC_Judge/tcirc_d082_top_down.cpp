/*
***DP***
    O(m^2 * n^2)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 30;
int m, n;
int G[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][MAX_N][MAX_N]; //left, top, right, button

int rec(int l, int t, int r, int b) {
    if(dp[l][t][r][b] >= 0) return dp[l][t][r][b];

    int c0 =  0, c1 = 0, c;
    int sum = 0, mincost = 1e9;
    for(int x=t; x<=b; x++) {
        G[x][l] == 0 ? c0++ : c1++;
    }
    c = rec(l+1, t, r, b) + min(c0, c1);
    mincost = min(mincost, c);

    c0 = c1 = 0;
    for(int x=t; x<=b; x++) {
        G[x][r] == 0 ? c0++ : c1++;
    }
    c = rec(l, t, r-1, b) + min(c0, c1);
    mincost = min(mincost, c);

    c0 = c1 = 0;
    for(int y=l; y<=r; y++) {
        G[t][y] == 0 ? c0++ : c1++;
    }
    c = rec(l, t+1, r, b) + min(c0, c1);
    mincost = min(mincost, c);

    c0 = c1 = 0;
    for(int y=l; y<=r; y++) {
        G[b][y] == 0 ? c0++ : c1++;
    }
    c = rec(l, t, r, b-1) + min(c0, c1);
    mincost = min(mincost, c);

    return dp[l][t][r][b] = mincost;
}
int main() {
    scanf("%d%d", &m, &n);
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    for(int l=0; l<n; l++) {
        for(int r=l; r<n; r++) {
            for(int t=0; t<m; t++) {
                for(int b=t; b<m; b++) {
                    dp[l][t][r][b] = (l==r || t==b) ? 0 : -1;
                }
            }
        }
    }
    printf("%d\n", rec(0, 0, n-1, m-1));
    return 0;
}