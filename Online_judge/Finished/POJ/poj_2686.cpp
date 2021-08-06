/*
***Shortest Path (with limitations) / 位元 DP****

    O(2^n * n^2 * m)
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 8+3; //tickets
const int MAX_M = 30+3; //cities
const int INF = 1e9;

int n, m, p, a, b;
int t[MAX_N]; //horses of tickets
int d[MAX_M][MAX_M]; //adjacent matrix for graph；1-indexed

/*
    dp[S][v]: 
        minimum cost of time
    (S: remaining tickets；v: current position)
*/
double dp[1 << MAX_N][MAX_M];

void solve() {

    for(int i=0; i<(1 << n); i++)
        fill(dp[i]+1, dp[i]+m+1, INF);

    dp[(1 << n) - 1][a] = 0; //1-indexed
    double res = INF;

    for(int S=(1 << n)-1; S>=0; S--) {
        //no matter how many tickets left, take the minimum cost
        res = min(res, dp[S][b]); 
        for(int v=1; v<=m; v++) { //city
            for(int i=0; i<n; i++) { //ticket
                //if still have that ticket
                if(S >> i & 1) {
                    for(int u=1; u<=m; u++) { //city
                        if(d[v][u] >= 0) {
                            dp[S & ~(1 << i)][u] = 
                                min(dp[S & ~(1 << i)][u], dp[S][v] + (double)d[v][u]/t[i]);
                        }
                    }
                }
            }
        }
    }
    if(res == INF)
        printf("Impossible");
    else 
        printf("%.3lf", res);
}

int main() {
    
    int flag = 0;
    while(scanf("%d%d%d%d%d", &n, &m, &p, &a, &b)) {
        if (n == 0)
            break;
        if(flag++)
            printf("\n");

        //if two cities aren't connected, -1
        for(int i=1; i<=m; i++)
            for(int j=1; j<=m; j++)
                d[i][j] = -1;

        for(int i=0; i<n; i++)
            scanf("%d", &t[i]);
        for(int i=0; i<p; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            d[x][y] = d[y][x] = z;
        }

        solve();
    }

    return 0;
}