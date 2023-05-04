/*
***Maximum s-t Flow / Minimum s-t cut*** 
                            -- Ford-Fulkerson Algorithm
    Description: 
        Keep searching for (DFS) augmenting pathes until no flow.

    O(F * (V + E))
        F: Max flow
        V: number of vertices
        E: number of edges

    WARNING: 
        這裡的 G 是無向圖!!! 
        所以 add_edge() 中 G[v] 的 capacity 是 "cap"!!!!
*/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;
using ll = long long;

const int MAX_V = 105;
const ll INF = 1e18 + 5;

struct edge { ll to, cap, rev; };
vector<edge> G[MAX_V]; // adjacent list for graph
bool vis[MAX_V]; // visited

void add_edge(ll from, ll to, ll cap) {
    G[from].push_back((edge){to, cap, (ll)G[to].size()}); // (to, cap, rev)
    G[to].push_back((edge){from, cap, (ll)G[from].size() - 1}); 
}

// search for augmenting path
int dfs(ll v, ll t, ll f) {
    if(v == t) return f;
    vis[v] = true; // visited, no loop is permitted, for it wastes cap.

    // traverse edges of "v"
    for (auto &e: G[v]) {
        if (!vis[e.to] && e.cap > 0) {
            ll d = dfs(e.to, t, min(f, e.cap)); // flow to next vertex 
            if (d > 0) {
                e.cap -= d; // capacity left
                G[e.to][e.rev].cap += d; // the capacity for reverse flow
                return d;
            }
        }
    }
    return 0; // if no flow
}

ll max_flow(ll s, ll t) {
    ll flow = 0;
    while (true) {
        memset(vis, 0, sizeof(vis));
        ll f = dfs(s, t, INF);
        if (f == 0)
            return flow;
        flow += f;
    }
}

// print the minimum cut
void min_cut(ll n) {
    for (int u=0; u<n; ++u) {
        if (vis[u]) {
            for (auto e: G[u]) {
                if (!vis[e.to]) {
                    cout << u << ' ' << e.to << '\n';
                }
            }
        }
    }
}

int main() {
    io;
    ll n, m;
    ll s, t;
    cin >> n >> m >> s >> t;
    for (int i=0; i<m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    ll F = max_flow(s, t);
    cout << F << '\n';
    min_cut(n);

    return 0;
}