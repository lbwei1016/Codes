/*
***Graph / DP** -- similar to "Maximum Sum of Subarray"
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+4;
int n;
int w[N], p[N], deg[N];
bool visit[N];
vector<int> G[N];
//make the tree have root
void dfs(int v) {
    visit[v] = true;
    for(int u : G[v]) {
        if(!visit[u]) {
            p[u] = v; deg[v]++;
            dfs(u);
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &w[i]);
    }
    for(int i=1; i<n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    queue<int> que;
    for(int i=1; i<=n; i++) {
        if(deg[i] == 0)
            que.push(i);
    }
    int res = 0;
    while(!que.empty()) {
        int v = que.front(); que.pop();
        if(w[v] > 0) w[p[v]] += w[v];
        res = max(res, w[v]);
        if(--deg[p[v]] == 0) que.push(p[v]);
    }
    printf("%d\n", res);
    return 0;
}