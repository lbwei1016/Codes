#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
struct P {
    int x, y, d;
    // bool operator < (const P &p) const {
    //     return d > p.d;
    // }
};
int N, M;
char G[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
queue<P> cons[26];
int d[26];

int search(int co) {
    while(!cons[co].empty()) {
        auto p = cons[co].front(); 
        cons[co].pop();

        // if(vis[p.x][p.y]) continue;
        // vis[p.x][p.y] = true; 

        for(int i=0; i<8; ++i) {
            int nx = p.x + dx[i], ny = p.y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M) {
                if(G[nx][ny] == co || vis[nx][ny]) continue;
                vis[nx][ny] = true;
                if(G[nx][ny] == 'W'-'A') {
                    d[co] = min(d[co], p.d);
                    continue;
                };
                int ds = p.d;
                if(G[p.x][p.y] != G[nx][ny]) ++ds;
                cons[co].push(P{nx, ny, ds});
            }
        }
    }
    return d[co];
}

int main() {
    scanf("%d %d\n", &N, &M);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            scanf("%c", &G[i][j]);
            G[i][j] -= 'A';
            if(G[i][j] == 'W'-'A') continue;
            cons[int(G[i][j])].push(P{i, j, 0});
        }
        getchar();
    }
    for(int i=0; i<26; ++i) {
        if(cons[i].size() == 0 || i=='W'-'A') continue;
        memset(vis, 0, sizeof(vis));
        d[i] = 1e9;
        int res = search(i);
        printf("%c %d\n", ('A'+i), res); 
    }
    return 0;
}
