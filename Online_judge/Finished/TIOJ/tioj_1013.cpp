/*
***Graph*** -- BFS
    Solution:
        先以起火點 BFS，找出各點最早著火時間，再讓人 BFS。
        注意判斷是否人在開始之前就被燒死了。
*/
#include <bits/stdc++.h>
using namespace std;

char G[15][20] = {
    {"*****************"},
    {"*...*.......**..*"},
    {"**..*....*.*.*..*"},
    {"*......*.**.**.**"},
    {"*..**...**..**.**"},
    {"**.....**..*.*..*"},
    {"*....*..........*"},
    {"*.....****.*...**"},
    {"****.*.*........*"},
    {"*****************"}
};
struct P { int x, y, t; };
int fx, fy, t, sx, sy, ex, ey;
int fire[15][20], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int bfs() {
    for(int i=0; i<15; ++i) for(int j=0; j<20; ++j) fire[i][j] = 1e9;
    queue<P> que;
    fire[fx][fy] = 1;
    que.push({fx, fy, 0});
    while(!que.empty()) {
        auto p = que.front(); que.pop();
        int x = p.x, y = p.y;
        for(int i=0; i<4; ++i) {
            int nx = x+dx[i], ny = y+dy[i];
            if(G[nx][ny]=='*' || fire[nx][ny]!=1e9) continue;
            if(nx == ex && ny == ey) continue; // 避難所不會著火
            fire[nx][ny] = fire[x][y] + 1;
            que.push({nx, ny, 0});
        }
    }
    // 如果在開始之前就被燒死了
    if(fire[sx][sy] <= t) return -1;
    que.push({sx, sy, t}); G[sx][sy] = '*';
    while(!que.empty()) {
        auto p = que.front(); que.pop();
        int x = p.x, y = p.y;
        if(x == ex && y == ey) return p.t - t;
        for(int i=0; i<4; ++i) {
            int nx = x+dx[i], ny = y+dy[i];
            if(G[nx][ny]=='*' || fire[nx][ny]<=p.t+1) continue;
            que.push({nx, ny, p.t+1});
            G[nx][ny] = '*'; // 避免重複拜訪
        }
    }
    return -1;
}
int main() {
    scanf("%d%d", &fx, &fy);
    scanf("%d", &t);
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    int res = bfs();
    if(res < 0) puts("Help!");
    else printf("%d\n", res);
    return 0;
}