/*
***Graph / Hash*** (*)
    Solution:
        原先使用 std::unordered_set 來儲存路徑上的數字，但 SE，因此
        放棄容器，自己做 hash table
*/
#include <bits/stdc++.h>
using namespace std;

const int M = 8;
int n, m, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int G[M][M], mx;
bool vis[M*M];

void dfs(int x, int y, int d) {
    vis[G[x][y]] = 1;
    mx = max(mx, d);
    for(int i=0; i<4; ++i) {
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0 || nx>=m || ny<0 || ny>=m || vis[G[nx][ny]]) continue;
        dfs(nx, ny, d+1);
    }
    vis[G[x][y]] = 0;
}

int main() {
    scanf("%d", &n);
    while(n--) {
        mx = 0;
        int tmp[64] = {0};
        scanf("%d", &m);
        for(int i=0; i<m; ++i) {
            for(int j=0; j<m; ++j) {
                scanf("%d", &G[i][j]);
                tmp[i*m+j] = G[i][j];
            }
        }
        // mapping
        sort(tmp, tmp+m*m);
        int hash[64] = {0}, diff = 1;
        hash[tmp[0]] = 0;
        for(int i=1; i<m*m; ++i) {
            if(tmp[i] != tmp[i-1]) {
                hash[tmp[i]] = diff++;
            }
        }
        for(int i=0; i<m; ++i) {
            for(int j=0; j<m; ++j) {
                G[i][j] = hash[G[i][j]];
            }
        }

        for(int i=0; i<m; ++i) {
            for(int j=0; j<m; ++j) {
                dfs(i, j, 1);
            }
        }
        printf("%d\n", mx);
    }
    return 0;
}