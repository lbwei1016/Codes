/*
***Minimum Cost s-t Flow*** --Dijkstra

    TLE

    Another method for this problem is searching whether "negative circuits"(負的閉路)
    exist, using Bellman-Ford or Floyd-Warshall
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> Pii; //(dist, vertex)
const int MAX_V = 200+5;
const int INF = 1e9;
struct edge { int to, cap, cost, rev; };

int N, M;
int X[MAX_V], Y[MAX_V], B[MAX_V];
int P[MAX_V], Q[MAX_V], C[MAX_V];
int E[MAX_V][MAX_V]; //given plan

int V;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});
}

int min_cost_flow(int s, int t, int f) {
    int res = 0;
    fill(h, h+V, 0);
    while(f > 0) {
        priority_queue<Pii, vector<Pii>, greater<Pii> > pq;
        fill(dist, dist+V, INF);
        dist[s] = 0;
        pq.push(Pii(0, s));
        while(!pq.empty()) {
            Pii p = pq.top(); pq.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(int i=0; i<G[v].size(); i++) {
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    pq.push(Pii(dist[e.to], e.to));
                }
            }
        }

        if(dist[t] == INF) return -1;

        for(int v=0; v<V; v++) {
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

void solve() {
    /*
        0 ~ N-1: Buildings
        N ~ N+M-1: Shelters
    */
    int s = N + M, t = s + 1;
    V = t + 1;
    int cost = 0; //the cost of the given plan
    int F = 0; //total people
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int dis = abs(X[i] - P[j]) + abs(Y[i] - Q[j]) + 1;
            add_edge(i, N+j, INF, dis);
            cost += E[i][j] * dis;
        }
    }
    for(int i=0; i<N; i++) {
        add_edge(s, i, B[i], 0);
        F += B[i];
    }
    for(int i=0; i<M; i++) {
        add_edge(N+i, t, C[i], 0);
    }

    if(min_cost_flow(s, t, F) < cost) {
        printf("SUBOPTIMAL\n");
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                printf("%d%c", G[N+j][i].cap, j==M-1 ? '\n' : ' ');
            }
        }
    }
    else {
        printf("OPTIMAL\n");
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) {
        scanf("%d%d%d", &X[i], &Y[i], &B[i]);
    }
    for(int i=0; i<M; i++) {
        scanf("%d%d%d", &P[i], &Q[i], &C[i]);
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d", &E[i][j]);
        }
    }
    solve();
    return 0;
}