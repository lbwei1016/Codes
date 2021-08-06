/*
***Graph*** -- Shortest path
    Solution:
        找出最小的符合條件的兩條路徑。
        1. 全點對路徑
        2. 窮舉所有可能的 path1, path2 重疊的 i, j 路徑，使總路徑數最小化
    O(V^2 + V^2) = O(V^2)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
int n, m, d[N][N];
vector<int> G[N];
bitset<N> vis;

void bfs(int st) {
    vis.reset();
    queue<int> que;
    d[st][st] = 0;
    que.push(st);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        if(vis[v]) continue;
        vis[v] = 1;
        for(int u : G[v]) {
            if(d[st][u] > d[st][v] + 1) {
                d[st][u] = d[st][v] + 1;
                que.push(u);
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<=n; ++i) fill(d[i], d[i]+N, (int)1e9);
    for(int i=0; i<m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1; i<=n; ++i) bfs(i); // 全點對路徑長
    int s1, s2, t1, t2, l1, l2;
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
    if(d[s1][t1] > l1 || d[s2][t2] > l2) {
        puts("-1"); return 0;
    }
    int mn = d[s1][t1] + d[s2][t2];
    // 找出使總路徑長最小的重疊路線 i<->j
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            // 因道路為雙向，且一次比較兩種路線 (d1, d2)，因此需同時考慮 i->j 和 j->i 
            int d1 = min(d[s1][i]+d[i][j]+d[j][t1], d[t1][i]+d[i][j]+d[j][s1]);
            int d2 = min(d[s2][i]+d[i][j]+d[j][t2], d[t2][i]+d[i][j]+d[j][s2]);
            if(d1 > l1 || d2 > l2) continue;
            mn = min(mn, d1+d2-d[i][j]);
        }
    }
    printf("%d\n", m-mn);
    return 0;
}