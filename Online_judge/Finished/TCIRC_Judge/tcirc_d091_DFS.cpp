/*
***Graph*** 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+5;
vector<int> G[N];
bool visit[N];
int val[N];

int dfs(int s) {
    visit[s] = true;
    int w = val[s];
    for(int v : G[s]) {
        if(!visit[v]) {
            w += dfs(v);
        }
    }
    return w;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &val[i]);
    }
    for(int i=0; i<m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int mx = 0;
    for(int i=0; i<n; i++) {
        if(!visit[i]) 
            mx = max(mx, dfs(i));
    }
    printf("%d\n", mx);
    return 0;
}