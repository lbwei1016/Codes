/*
***Graph*** 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+4;
vector<int> G[N];
int col[N];

int bfs(int v) {
    queue<int> Q;
    Q.push(v);
    col[v] = 0;
    while(!Q.empty()) {
        int p = Q.front(); Q.pop();
        for(int u : G[p]) {
            if(col[u] == -1) {
                col[u] = col[p] ^ 1;
                Q.push(u);
            } else if(col[u] == col[p]){
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int t, n, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i=0; i<n; i++) {
            G[i].clear();
        }
        memset(col, -1, sizeof(col));
        for(int i=0; i<m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int t = 0;
        for(int i=0; i<n; i++) {
            if(col[i] == -1) {
                t = bfs(i);
                if(t) break;
            }
        }
        if(t) printf("no\n");
        else printf("yes\n");
    }
    return 0;
}