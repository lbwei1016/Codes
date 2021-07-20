/*
***Graph***
*/
#include <bits/stdc++.h>
using namespace std;

int n, res;
vector<int> G[50004], tour;

void dfs(int p, int v) {
    tour.push_back(v);
    for(int u : G[v]) {
        if(u == p) continue;
        dfs(v, u);
        tour.push_back(v);
    }
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n-1; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(v);
        G[v].push_back(u);
        res += w + w;
    }
    for(int i=0; i<n; i++) {
        sort(G[i].begin(), G[i].end());
    }
    dfs(-1, 0);
    printf("%d\n", res);
    for(int i=0, len=tour.size(); i<len; i++) {
        printf("%d%c", tour[i], i==len-1 ? '\n' : ' ');
    }
    return 0;
}