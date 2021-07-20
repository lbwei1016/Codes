/*
***Graph*** 
*/
#include <bits/stdc++.h>
using namespace std;

int dfs(int v, int prec, vector<int> G[], int col[]) {
    col[v] = prec ^ 1;
    int c = 0;
    for(int u : G[v]) {
        if(col[u] == -1) {
            c |= dfs(u, col[v], G, col);
            if(c) break;
        }
        else if(col[u] == col[v]) return 1;
    }
    return c;
}
int main() {
    int t, n, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        vector<int> G[n];
        int col[n];
        memset(col, -1, sizeof(col));
        for(int i=0; i<m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int c = 0;
        for(int i=0; i<n; i++) {
            if(col[i] == -1) {
                c |= dfs(i, 0, G, col);
                if(c) break;
            }
        }
        if(c) printf("no\n");
        else printf("yes\n");
    }
    return 0;
}