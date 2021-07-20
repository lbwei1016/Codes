/*
***Graph*** 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int G[N][N];
int visit[N][N];
int si, sj;
int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};

void bfs() {
    int res = 0;
    while(true) {
        res += G[si][sj];
        visit[si][sj] = true;
        int mn = 1e9, ti = -1, tj = -1;
        for(int k=0; k<4; k++) {
            int ni = si + di[k], nj = sj + dj[k];
            if(!visit[ni][nj] && G[ni][nj] < mn) {
                ti = ni, tj = nj;
                mn = G[ni][nj];
            }
        }
        if(ti == -1) break;
        si = ti; sj = tj;
    }
    printf("%d\n", res);
}
int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int mn = 1e9;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &G[i][j]);
            if(G[i][j] < mn) {
                si = i;
                sj = j;
                mn = G[i][j];
            }
        }
    }
    for(int i=0; i<=m+1; i++) {
        visit[i][0] = visit[i][n+1] = true;
    }
    for(int j=0; j<=n+1; j++) {
        visit[0][j] = visit[m+1][j] = true;
    }
    bfs();
    return 0;
}