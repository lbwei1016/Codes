/*
***1 to v, v to V
formosa (tag: Introduction to Algorithms 2021 Fall, Kai-Chiang Wu)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAX_V = 1e5+5, INF = 1e9;
struct Edge {
    ll to, cost, dec;
};
ll V, E;
vector<Edge> G[MAX_V], revG[MAX_V];
vector<pair<ll, ll> > seq; // record the sequence of edges
vector<ll> d_from_1(MAX_V), d_from_N(MAX_V);

struct PQ {
    ll v, dis;
    bool operator < (const PQ &p) const {
        return dis > p.dis;
    } 
};

void dij(ll st, vector<Edge> G[], vector<ll> &dis) {
    priority_queue<PQ> pq;
    fill(dis.begin(), dis.end(), INF);
    pq.push(PQ{st, dis[st]=0});

    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        ll at = p.v, d = p.dis;

        if(dis[at] < d) continue;

        for(auto e: G[at]) {
            if(dis[e.to] > d+e.cost) {
                dis[e.to] = d + e.cost;
                pq.push(PQ{e.to, dis[e.to]});
            }
        }
    }
}

void solve(ll sh_pa, vector<ll> &df1, vector<ll> &dfN) {
    for(ll i=1; i<=V; ++i) {
        if(df1[i] == INF) continue;
        for(auto &e: G[i]) {
            if(dfN[e.to] == INF) continue;
            ll diff = sh_pa - df1[i] - dfN[e.to];
            if(diff >= 0) e.dec = e.cost - diff; // must be greater than 0
        }
    }
}

int main() {
    cin >> V >> E;
    seq.reserve(E);
    for(ll i=0; i<E; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        seq.emplace_back(u, G[u].size()); // who, which
        G[u].push_back(Edge{v, w, -1});
        revG[v].push_back(Edge{u, w, -1});
    }    
    dij(1, G, d_from_1); dij(V, revG, d_from_N);
    // printf("shortest path len: %d\n", d_from_1[V]);
    solve(d_from_1[V], d_from_1, d_from_N);
    for(ll i=0; i<E; ++i) {
        cout << G[seq[i].first][seq[i].second].dec << '\n';
    }
    return 0;
}