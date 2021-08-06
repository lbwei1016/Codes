/*
***Graph*** -- TSP on tree / diameter of tree
    Solution:
        Only one path can be traveled only once；to minimize the cost, 
        the path should be the longest -- the diameter.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 50000+5;
struct E { int to, w; };
int n, W, D, h[N];
vector<E> G[N];

void dfs(int v, int p) {
    for(auto e : G[v]) {
        int u = e.to, w = e.w;
        if(u == p) continue;
        dfs(u, v);
        D = max(D, h[u]+w+h[v]);
        h[v] = max(h[v], h[u]+w);
    }
    return;
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        G[a].push_back({b, w});
        G[b].push_back({a, w});
        W += w;
    }
    //find the diameter
    dfs(0, 0);
    //total cost: 1*diameter + 2*(other edges)
    printf("%d\n", 2*W-D);
    return 0;
}