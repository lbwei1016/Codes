#include <bits/stdc++.h>
using namespace std;

const int N = 17;
int n, m;
int d[N][N];
int dp[1 << N][N];
pair<int, int> pre[1 << N][N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) d[i][j] = 1e9;
    for (int i=0; i<m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        d[u][v] = d[v][u] = w;
    }
    int S = (1 << n) - 1;
    for(int i=0; i<=S; i++) {
        fill(dp[i], dp[i]+n, 1e9);
        for (int j=0; j<N; ++j) pre[i][j] = {-1, -1};
    }
    dp[S][0] = 0;
    for(S=(1<<n)-2; S>=0; S--) {
        for(int v=0; v<n; v++) {
            for(int u=0; u<n; u++) {
                if(!(S >> u & 1)) {
                    if (dp[S][v] > dp[S | (1<<u)][u] + d[v][u]) {
                        dp[S][v] = dp[S | (1<<u)][u] + d[v][u];
                        pre[S][v] = {S | (1 << u), u};
                    }
                    // dp[S][v] = min(dp[S][v], dp[S | (1<<u)][u] + d[v][u]);
                }
            }
        }
    }
    // printf("%d\n", dp[0][0]);
    // for (int i=0; i<(1<<n); ++i) {
    //     for (int j=0; j<n; ++j) {
    //         printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
    //     }
    // }

    int i = 0, j = 0;
    while (true) {
        cout << i << ' ' << j << '\n';
        int t1 = i;
        i = pre[i][j].first;
        j = pre[t1][j].second;
        if (j == -1) break;
    }
    return 0;
}