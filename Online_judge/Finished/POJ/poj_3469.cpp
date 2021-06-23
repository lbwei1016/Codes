/*
***Maximum s-t Flow*** -- Dinic Algorithm

    Unknown reason TLE, but other code (below) similar to this AC

    O((N+M) * N^2)
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 20000;
const int MAX_M = 200000;
const int INF = 1e9;

struct edge { int to, cap, rev; };
vector<edge> G[MAX_N];
int level[MAX_N];
int iter[MAX_N];

int N, M, s, t;

inline void add_edge(int u, int v, int cap) {
    G[u].push_back((edge){v, cap, (int)G[v].size()});
    G[v].push_back((edge){u, 0, (int)G[u].size()-1});
}
inline void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> Q;
    level[s] = 0;
    Q.push(s);
    while(!Q.empty()) {
        int v = Q.front(); Q.pop();
        for(int i=0; i<G[v].size(); i++) {
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                Q.push(e.to);
            }
        }
    }
}
inline int dfs(int v, int t, int f) {
    if(v == t) return f;
    for(int &i = iter[v]; i<G[v].size(); i++) {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t) {
    int flow = 0;
    while(true) {
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);

    s = N, t = s + 1;
    for(int i=0; i<N; i++) {
        int A, B;
        scanf("%d%d", &A, &B);
        add_edge(i, t, A);
        add_edge(s, i, B);
    }
    for(int i=0; i<M; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        add_edge(a-1, b-1, w);
        add_edge(b-1, a-1, w);
    }

    printf("%d\n", max_flow(s, t));
    return 0;
}
/*
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// ===== Declaration of DinicGraph =====
struct Edge {
    int to, cap, rev;
};
struct DinicGraph {
    const static int INF = 0x3f3f3f3f;
    int V;
    vector< vector<Edge> > g;
    vector<int> iter;
    vector<int> level;
    DinicGraph();
    DinicGraph(int v);
    void add_edge(int u, int v, int cap);
    void bfs(int s);
    int dfs(int v, int t, int f);
    int max_flow(int s, int t);
};
// ===== end of Declaration =====

DinicGraph g;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    g = DinicGraph(N + 2);

    int A = N;
    int B = N + 1;

    for (int i = 0; i < N; i++) {
        int a, b; scanf("%d %d", &a, &b);
        g.add_edge(A, i, a);
        g.add_edge(i, B, b);
    }
    for (int i = 0; i < M; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        a--; b--;
        g.add_edge(a, b, w);
        g.add_edge(b, a, w);
    }

    printf("%d\n", g.max_flow(A, B));

    return 0;
}

// ===== Implementation of DinicGraph =====
DinicGraph::DinicGraph() {
    ;
}

DinicGraph::DinicGraph(int v): V(v) {
    g = vector< vector<Edge> >(V, vector<Edge>());
    iter = vector<int>(V, 0);
    level = vector<int>(V, 0);
}

void DinicGraph::add_edge(int u, int v, int cap) {
    g[u].push_back((Edge){v, cap, (int)g[v].size()});
    g[v].push_back((Edge){u, 0, (int)g[u].size() - 1});
}

void DinicGraph::bfs(int s) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;

    level[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 0; i < int(g[v].size()); i++) {
            const Edge& e = g[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}

int DinicGraph::dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int& i = iter[v]; i < int(g[v].size()); i++) {
        Edge& e = g[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int DinicGraph::max_flow(int s, int t) { // dinic
    int flow = 0;
    for (;;) {
        bfs(s);
        if (level[t] < 0) return flow;
        fill(iter.begin(), iter.end(), 0);
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}
*/