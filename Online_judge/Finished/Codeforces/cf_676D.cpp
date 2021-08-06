/*
***BFS***
    Solution:
        For each position, record their "x, y coordinate, distance, facing status".
        Using four number to represent four directions: 
            0: up；1: right；2: down；3: left (clockwise)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
struct P { int x, y, d, status; }; // status: 0 ^, 1 >, 2 V, 3 < (face which direction)
int n, m;
/* 
    G[x][y][d]: door of "d" direction exists；
    visit[x][y][s]: on (x, y), facing "s" direction is visited
*/
bool G[N][N][4], visit[N][N][4]; // ^, >, V, <
int xt, yt, xm, ym, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int bfs() {
    queue<P> que;
    que.push({xt, yt, 0, 0});
    visit[xt][yt][0] = true;
    while(!que.empty()) {
        auto p = que.front(); que.pop();
        int x = p.x, y = p.y, d = p.d, st = p.status;
        if(x == xm && y == ym) return d;
        // rotate clockwise
        int next = (st+1) % 4;
        if(!visit[x][y][next]) {
            visit[x][y][next] = true;
            que.push({x, y, d+1, next});
        } 
        for(int i=0; i<4; ++i) {
            //if a door for dirction "i" after rotation "st" exists (point!!!)
            if(G[x][y][(i-st+4) % 4]) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx<1 || nx>n || ny<1 || ny>m) continue;
                // the opposite side of current door, to go into the next room
                int inverse = (i-st+6) % 4; 
                if(G[nx][ny][inverse] && !visit[nx][ny][st]) {
                    visit[nx][ny][st] = true;
                    que.push({nx, ny, d+1, st});
                }
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    char c;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            cin >> c;
            // transform into bool (or use bit operation)
            if(c == '+') G[i][j][0] = G[i][j][1] = G[i][j][2] = G[i][j][3] = 1;
            else if(c == '-') G[i][j][1] = G[i][j][3] = 1;
            else if(c == '|') G[i][j][0] = G[i][j][2] = 1;
            else if(c == '^') G[i][j][0] = 1;
            else if(c == '>') G[i][j][1] = 1;
            else if(c == 'v') G[i][j][2] = 1;
            else if(c == '<') G[i][j][3] = 1;
            else if(c == 'U') G[i][j][1] = G[i][j][2] = G[i][j][3] = 1;
            else if(c == 'R') G[i][j][0] = G[i][j][2] = G[i][j][3] = 1;
            else if(c == 'D') G[i][j][0] = G[i][j][1] = G[i][j][3] = 1;
            else if(c == 'L') G[i][j][0] = G[i][j][1] = G[i][j][2] = 1;
        }
    }
    cin >> xt >> yt >> xm >> ym;
    cout << bfs() << '\n';
    return 0;
}