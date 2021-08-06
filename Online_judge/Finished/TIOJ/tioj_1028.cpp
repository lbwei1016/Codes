/*
***位元 DP / Graph*** -- Shortest path (*)
*/
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const int N = 14, INF = 1e18;
struct E { int to, w; }; // graph
int n, m, k, st, des; // destination
// dp[i][j]: 目前在 i，而 j 是還沒去過的地方的集合
int pre[N][1 << N]; // 記錄在 i 點且 j 還沒去過的最短路徑下的前一點
ll dp[N][1 << N];
vector<E> G[N];
// pq
struct DJ {
    int id; ll dis;
    bool operator < (const DJ &a) const {
        return dis > a.dis;
    }
};
ll d[N]; // 暫存最段距離
bitset<N> vis;

int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    scanf("%d", &k);
    for(int i=0; i<k; ++i) {
        int t; scanf("%d", &t);
        if(i == 0) st = t;
        des |= (1<<t);
    }
    int S = 1 << n;
    for(int i=0; i<n; ++i) for(int j=0; j<S; ++j)
        dp[i][j] = INF;
    for(int i=0; i<n; ++i) dp[i][0] = 0;
    // 從小更新到大；       當 i ? des 時才嘗試更新距離
    for(int i=1; i<S; ++i) if(i == (des&i)) {
        fill(d, d+n, INF); vis.reset();
        priority_queue<DJ> pq;
        for(int j=0; j<n; ++j) if(i & (1<<j)) {
            d[j] = dp[j][i ^ (1<<j)]; // 目前到各點的最小距離
            pq.push({j, d[j]});
        }
        // Dijkstra 更新各點距離
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int v = p.id;
            if(vis[v]) continue;
            vis[v] = 1;
            for(auto e : G[v]) {
                int u = e.to, w = e.w;
                if(d[u] > d[v] + w) {
                    d[u] = d[v] + w;
                    pre[u][i] = v;
                    pq.push({u, d[u]});
                }
                // 字典最小順序
                else if(d[u] == d[v]+w && pre[u][i] > v) {
                    pre[u][i] = v;
                }
            }
        }
        for(int j=0; j<n; ++j) if(!(i & (1<<j))) {
            dp[j][i] = d[j]; // 更新距離
        }
    }
    printf("Minimum travel distance: %d\n", dp[st][des ^ (1<<st)]);
    printf("Travel route:");
    int now = st; 
    while(true) {
        printf(" %d", now);
        if(des & (1<<now)) // 可能會經過不在 des 上的景點 (路過)
            des ^= (1 << now);
        if(!des) break;
        now = pre[now][des];
    }
    puts("");
    return 0;
}