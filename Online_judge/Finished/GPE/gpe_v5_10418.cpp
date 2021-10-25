#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int main() {
    int n, m;
    char G[N][N];
    for(int cnt=1; scanf("%d%d", &n, &m); ++cnt) {
        if(n == 0) break;
        if(cnt > 1) puts("");
        for(int i=0; i<n; ++i) scanf("%s", G[i]);
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(G[i][j] != '*') {
                    if(G[i][j] == '.') G[i][j] = '0';
                    continue;
                } 
                for(int k=0; k<8; ++k) {
                    int x = i+dx[k], y = j+dy[k];
                    if(0<=x && x<n && 0<=y && y<m) {
                        if(G[x][y] == '*') continue;
                        if(G[x][y] == '.') G[x][y] = '0';
                        ++G[x][y];
                    }
                }
            }
        }
        printf("Field #%d:\n", cnt);
        for(int i=0; i<n; ++i) puts(G[i]);
    }
    return 0;
}