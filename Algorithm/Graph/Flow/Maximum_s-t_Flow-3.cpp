/*
***Maximum s-t Flow / Minimum s-t cut*** 
                            -- Ford-Fulkerson Algorithm, with capacity scalling
    Description: 
        Keep searching for (DFS) augmenting pathes until no flow.
        The first DFS search for a flow of size D = MAX_CAPACITY. 
        Divide D by 2 after max_flow() call.

    O(log F * E^2),
        F: Max flow
        E: number of edges
    since there are O(log F) target flows, and each target flow may be searched
    O(E) times, O(E) per DFS.

    WARNING: 
        這裡的 G 是無向圖!!! 
        所以 add_edge() 中 G[v] 的 capacity 是 "cap"!!!!
*/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;
using ll = long long;

const int MAX_V = 505;
const ll INF = 1e18 + 5;

struct edge { ll to, cap, rev; };
vector<edge> G[MAX_V]; // adjacent list for graph
bool vis[MAX_V]; // visited

void add_edge(ll from, ll to, ll cap) {
    G[from].push_back((edge){to, cap, (ll)G[to].size()}); // (to, cap, rev)
    G[to].push_back((edge){from, cap, (ll)G[from].size() - 1}); 
}

// search for augmenting path
bool dfs(ll v, ll t, ll f) {
    if(v == t) return true;
    vis[v] = true; // visited, no loop is permitted, for it wastes cap.

    // traverse edges of "v"
    for(auto &e: G[v]) {
        if(!vis[e.to] && e.cap >= f) {
            if (dfs(e.to, t, f)) { // flow to next vertex 
                e.cap -= f; // capacity left
                G[e.to][e.rev].cap += f; // the capacity for reverse flow
                return true;
            }
        }
    }
    return false; // if no flow
}

ll max_flow(ll s, ll t, ll D) {
    ll flow = 0;
    while(true) {
        memset(vis, 0, sizeof(vis));
        if(!dfs(s, t, D))
            return flow;
        flow += D;
    }
}

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
    ll n, m, s, t;
    cin >> n >> m >> s >> t;

    ll D = 0, F = 0;
    for (int i=0; i<m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        D = max(D, w);
    }

    while (D) {
        F += max_flow(s, t, D);
        D /= 2;
    }
    cout << F << '\n';
    min_cut(n);

    return 0;
}