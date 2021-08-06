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
int n, root, W, d[N];
vector<E> G[N];

int bfs(int r) {
    int mx = 0, r2;
    memset(d, -1, sizeof(d));
    queue<int> que;
    d[r] = 0;
    que.push(r);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(auto e : G[v]) {
            int u = e.to, w = e.w;
            if(d[u] >= 0) continue;
            d[u] = d[v] + w;
            if(d[u] > mx) {
                mx = d[u];
                r2 = u;
            }
            que.push(u);
        }
    }
    return r2;
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
    int len = d[bfs(bfs(0))];
    //total cost: 1*diameter + 2*(other edges)
    printf("%d\n", 2*W-len);

    return 0;
}