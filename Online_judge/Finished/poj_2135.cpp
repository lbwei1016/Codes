/*
***Minimum Cost s-t Flow*** --Dijkstra

    Description:
        Find two shortest pathes from s to t, where there isn't 
        any road(edge) traveled twice.
    
    Solution:
        The answer is the minimum cost of a two-unit flow (for go to and back).
    
    O(F * E * logV) or O(F * V^2)
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> P; //first: dist, second: vertex
const int MAX_N = 1000+5;
const int INF = 1e9;

struct edge { int to, cap, cost, rev; };
int N, M;
vector<edge> G[MAX_N];
int h[MAX_N];
int dist[MAX_N];
int prevv[MAX_N], preve[MAX_N];

void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});
}

int min_cost_flow(int s, int t, int f) {
    int res = 0;
    fill(h, h+N, 0);
    while(f > 0) {
        priority_queue<P, vector<P>, greater<P> > pq;
        fill(dist, dist+N, INF);
        dist[s] = 0;
        pq.push(P(0, s));
        while(!pq.empty()) {
            P p = pq.top(); pq.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(int i=0; i<G[v].size(); i++) {
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    pq.push(P(dist[e.to], e.to));
                }
            }
        }

        if(dist[t] == INF) {
            return -1;
        }

        for(int v=0; v<N; v++) {
            h[v] += dist[v];
        }

        int d = f;
        for(int v=t; v!=s; v=prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * h[t];
        for(int v=t; v!=s; v=prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++) {
        int u, v, cost;
        scanf("%d%d%d", &u, &v, &cost);
        add_edge(u-1, v-1, 1, cost);
        add_edge(v-1, u-1, 1, cost);
    }

    printf("%d\n", min_cost_flow(0, N-1, 2));

    return 0;
}