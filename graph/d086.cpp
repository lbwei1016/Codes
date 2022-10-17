#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
using ll = long long;

const int N = 17, INF = 1e9+7;
int dp[1 << N][N];
int d[N][N];
int n, m;

void tsp(int G, int at) {
    if (G == (1<<n) - 1) return;
    // if (dp[G][at] != INF) return;
    for (int i=0; i<n; ++i) {
        if (!((G >> i) & 1)) {
            if (dp[G | (1 << i)][i] == INF)
                tsp(G | (1 << i), i);
            else cout << "cool\n";
            dp[G][at] = min(dp[G][at], dp[G | (1 << i)][i] + d[at][i]);
        }
    }
}

int main() {
    io;
    cin >> n >> m;
    for (int i=0; i<(1<<n); ++i) {
        for (int j=0; j<n; ++j) {
            dp[i][j] = INF;
        }
    }
    // for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) d[i][j] = INF;
    for (int i=0; i<m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
    }
    // for (int i=0; i<n; ++i) {
    //     for (int j=0; j<n; ++j) {
    //         cin >> d[i][j];
    //     }
    // }
    dp[(1<<n) - 1][0] = 0;
    tsp(0, 0);
    // int back = INF;
    // for (int i=0; i<n; ++i) {
    //     back = min(back, dp[0][i] + d[i][0]);
    // }
    cout << dp[0][0]<< '\n';
    // for (int i=0; i<(1<<n); ++i) {
    //     for (int j=0; j<n; ++j) {
    //         printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
    //     }
    // }
    return 0;
}
/*
7 12
0 1 6
0 4 5
0 2 2
0 6 9
0 5 7
1 2 7
2 4 6
2 3 3
3 4 8
3 6 4
1 5 9
6 4 3
*/