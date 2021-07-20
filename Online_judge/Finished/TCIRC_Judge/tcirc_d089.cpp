/*
***DP*** -- TSP
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 17;
int n, m;
int d[N][N];
int dp[1 << N][N];
int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &d[i][j]);
        }
    }
    int S = (1 << n) - 1;
    for(int i=0; i<=S; i++) {
        fill(dp[i], dp[i]+n, 1e9);
    }
    dp[S][0] = 0;
    for(S=(1<<n)-2; S>=0; S--) {
        for(int v=0; v<n; v++) {
            for(int u=0; u<n; u++) {
                if(!(S >> u & 1))
                    dp[S][v] = min(dp[S][v], dp[S | (1<<u)][u] + d[v][u]);
            }
        }
    }
    printf("%d\n", dp[0][0]);
    return 0;
}