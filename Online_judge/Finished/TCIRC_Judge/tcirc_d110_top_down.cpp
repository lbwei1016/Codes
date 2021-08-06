/*
***Ggraph / DP*** 
    Solution:
        d1[v]: v is chosen
        d00[v]: neither v nor its children is chosen
        d01[v]: v isn't chosen, while at least one of its children is chosen

    =>  for all u is the child of v
        d1[v] = sum(min(d00[u], d1[u])) (since d00[u] <= d01[u], no comparison is needed)
        d00[v] = sum(min(d01[u], d1[u]))
        d01[v] = sum(min(d01[u], d1[u])) + min_diff；min_diff = max(0, min(d1[u] - d01[u]))
            d01[v] must be dominated by at least one of its children, but "sum(...)"
            alone does not guarantee that (it's why d00[v] is equal to that value).
            Hence, "min_diff" represents "replace a d01[u] with d1[0] that increase the 
            least cost"；if "d1[u] - d01[u] < 0", it means that d1[u] < d01[u] and that 
            d1[u] has already been chosen, and thus no addition("0") is needed.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+4;
int n, w[N], d1[N], d00[N], d01[N];
vector<int> G[N];

void dfs(int v, int p) {
    d1[v] = w[v], d00[v] = 0, d01[v] = 1e9;
    for(int u : G[v]) {
        if(u == p) continue;
        dfs(u, v);
        d1[v] += min(d00[u], d1[u]);
        d00[v] += min(d01[u], d1[u]);
        d01[v] = min(d01[v], d1[u] - d01[u]);
    }
    d01[v] = d00[v] + max(0, d01[v]);
    return;
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
    dfs(1, 0);
    printf("%d\n", min(d1[1], d01[1]));
    return 0;
}