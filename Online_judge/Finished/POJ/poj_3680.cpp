/*
***Minimum Cost s-t Flow*** --Dijkstra

    Solution:
        Convert the initial "Range problem" into "MCF". This technique is
        quite sophisticated, please refer to Book: p.250.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> P;
const int MAX_N = 200+5;
const int INF = 1e9;
const int MAX_V = 2 * MAX_N+5;
struct edge { int to, cap, cost, rev; };

int N, K;
int a[MAX_N], b[MAX_N], w[MAX_N];

//for minimum-cost-flow
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
        priority_queue<P, vector<P>, greater<P> > pq;
        fill(dist, dist+V, INF);
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

        if(dist[t] == INF) return -1;

        for(int i=0; i<V; i++) {
            h[i] += dist[i];
        }

        int d = f;
        for(int v=t; v!=s; v=prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * h[t];
        //printf("d is: %d\n", d);
        for(int v=t; v!=s; v=prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            //printf("from: %d to: %d, cap become: %d\n", prevv[v], e.to, e.cap);
            G[v][e.rev].cap += d;
        }
        //printf("--------------\n");
    }
    return res;
}

void solve() {
    vector<int> x;
    for(int i=0; i<N; i++) {
        //put two endpoints of a range into vector 
        x.push_back(a[i]);
        x.push_back(b[i]);
    }
    sort(x.begin(), x.end());
    //erase duplicate onces
    x.erase(unique(x.begin(), x.end()), x.end());

    int m = x.size();
    int s = m, t = s + 1;
    V = t + 1;
    int res = 0;
    add_edge(s, 0, K, 0);
    add_edge(m-1, t, K, 0);
    for(int i=0; i+1<m; i++) {
        //adjacent vertices
        add_edge(i, i+1, INF, 0);
    }
    //the most importtant part!!!
    for(int i=0; i<N; i++) {
        int u = find(x.begin(), x.end(), a[i]) - x.begin();
        int v = find(x.begin(), x.end(), b[i]) - x.begin();
        add_edge(v, u, 1, w[i]);
        add_edge(s, v, 1, 0);
        add_edge(u, t, 1, 0);
        res += w[i];
    }
    res -= min_cost_flow(s, t, K+N);
    printf("%d\n", res);
}

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d", &N, &K);
        for(int i=0; i<2*N+5; i++) {
            G[i].clear();
        }
        for(int i=0; i<N; i++) {
            scanf("%d%d%d", &a[i], &b[i], &w[i]);
        }
        solve();
    }
    
    return 0;
}
/*
test1:
    3 1
    1 2 2
    2 3 4
    3 4 8
test2:
    3 1
    1 3 2
    2 3 4
    3 4 8
test3:
    3 2
    1 100000 100000
    1 150 301
    100 200 300
*/