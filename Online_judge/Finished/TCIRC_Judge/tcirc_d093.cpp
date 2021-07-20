/*
***Graph*** 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 505;
char G[N][N];
int d[N][N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int bfs(int m, int n) {
    memset(d, -1, sizeof(d));
    queue<pair<int, int> > Q;
    Q.push({1, 1});
    d[1][1] = 0;
    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            while(G[nx][ny] != '1') {
                if(d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    Q.push({nx, ny});
                }
                nx += dx[i]; ny += dy[i];
            }
        }
    }
    if(d[m][n] > 0) d[m][n]--;
    return d[m][n];
}
int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; i++) {
        scanf("%s", G[i]+1);
    }
    for(int i=0; i<=m+1; i++) {
        G[i][0] = G[i][n+1] = '1';
    }
    for(int j=0; j<=n+1; j++) {
        G[0][j] = G[m+1][j] = '1';
    }
    printf("%d\n", bfs(m, n));
    return 0;
}