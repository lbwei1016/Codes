/*
***Graph***
    Solution:
        被 ring(n) 碰到的就是 ring(n+1) 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

struct P { int x, y, val; };
int n, m, ring;
char G[N][N];
queue<P> que;

void solve() {
    int cnt = 0;
    while(!que.empty()) {
        P p = que.front(); que.pop();
        int x = p.x, y = p.y, val = p.val;
        for(int i=0; i<4; ++i) {
            int nx = x+dx[i], ny = y+dy[i];
            if(G[nx][ny] == 'T') {
                que.push(P{nx, ny, val+1});
                ring = max(ring, val+1);
                G[nx][ny] = val + 1;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    memset(G, 0, sizeof(G)); // omit
    for(int i=1; i<=n; ++i) {
        scanf("%s", G[i]+1);
        for(int j=1; j<=m; ++j) {
            if(G[i][j] != 'T') {
                G[i][j] = 0;
                que.push(P{i, j, 0});
            } 
        }
    } 
    for(int j=1; j<=m; ++j) {
        if(G[1][j] == 'T') que.push(P{1, j, G[1][j] = 1});
        if(G[n][j] == 'T') que.push(P{n, j, G[n][j] = 1});
    } 
    for(int i=1; i<=n; ++i) {
        if(G[i][1] == 'T') que.push(P{i, 1, G[i][1] = 1});
        if(G[i][m] == 'T') que.push(P{i, m, G[i][m] = 1});
    } 
    solve();
    int pad = 2 + (ring>=10);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(G[i][j] == 0) {
                for(int k=0; k<pad; ++k) putchar('.');
            }
            else {
                if(G[i][j] < 10) {
                    for(int k=0; k<pad-1; ++k) putchar('.');
                    printf("%d", (int)G[i][j]);
                }
                else {
                    putchar('.');
                    printf("%d", (int)G[i][j]);
                }
            }
        }
        puts("");
    }
    return 0;
}