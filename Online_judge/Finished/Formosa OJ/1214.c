#include <stdio.h>
#define N 22

typedef struct { int x, y; } P;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const int INF = 1e9;

int n, m, G[N][N];
int sx, sy, tx, ty;

int bfs() {
    P que[4*N*N];
    int head = 0, tail = 0, d[N][N];
    que[tail++] = (P){.x=sx, .y=sy};

    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) d[i][j] = INF;
    d[sx][sy] = 0;

    while(head < tail) {
        P p = que[head++];
        int x = p.x, y = p.y;
        if(x == tx && y == ty) return d[tx][ty];
        for(int i=0; i<4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<m) {
                if(G[nx][ny] == -1) continue;
                if(d[nx][ny] > d[x][y]+1) {
                    d[nx][ny] = d[x][y] + 1;
                    que[tail++] = (P){.x=nx, .y=ny};
                }
            }
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            scanf("%d", &G[i][j]);
            if(G[i][j] == -2) sx = i, sy = j;
            else if (G[i][j] == -3) tx = i, ty = j;
        }
    }
    printf("%d\n", bfs());
    return 0;
}