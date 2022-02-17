/*
***Graph*** Shortest Path + Potential
    Solution:
        The concept of potential: every edge is increased by h[i] - h[j]
            if h[i] > h[j]:
                i->j: h[i]-h[j] + (h[i]-h[j]) = 0
                j->i: -2(h[i]-h[j]) + (h[i]-h[j]) = -(h[i]-h[j]) < 0
            vice versa
        Hence, all the edges are negative; we then put a negative sign on
        each edge, and we can obtain the answer by Dijkstra!! (all edges are positive)
    O()
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+5;
const ll INF = 1e18;
struct E {
    ll to, w;
};
vector<E> G[N];

ll dis[N];

struct PQ {
    ll id, d;
    bool operator<(PQ p) const {
        return d > p.d;
    }
};

ll dij(int n, vector<ll> &h) {
    fill(dis, dis+N, INF);
    dis[1] = 0;
    priority_queue<PQ> pq;
    pq.push(PQ{1, 0});
    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        ll id = p.id, d = p.d;
        if(dis[id] < d) continue;

        for(auto e: G[id]) {
            if(d + e.w < dis[e.to]) {
                dis[e.to] = d + e.w;
                pq.push(PQ{e.to, dis[e.to]});
            }
        } 
    }
    ll mx = 0;
    for(int i=1; i<=n; ++i) {
        mx = max(mx, -(dis[i]-(h[1]-h[i])));
    }
    return mx;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> h(n+1);
    for(int i=1; i<=n; ++i) cin >> h[i];

    // convert to negative for shortest path
    for(int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        ll diff = h[u] - h[v];
        if(diff < 0) {
            G[u].push_back(E{v, -diff});
            G[v].push_back(E{u, 0});
        }
        else {
            G[u].push_back(E{v, 0});
            G[v].push_back(E{u, diff});
        }
    }
    cout << dij(n, h) << '\n';
    return 0;
}