#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 82, INF = 1e9 + 7;
struct Edge {
    int to, cap, rev;
};
vector<Edge> G0[N], G[N];
vector<int> level(N), iter(N);
int n, m;

void add_edge(int u, int v, int cap) {
    G0[u].push_back(Edge{v, cap, (int)G0[v].size()});
    G0[v].push_back(Edge{u, 0, (int)G0[u].size()-1});
}

void bfs(int s) {
    level.assign(N, -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (que.size()) {
        int v = que.front(); que.pop();
        for (auto &e: G[v]) {
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int &i=iter[v]; i<G[v].size(); ++i) {
        auto &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(e.cap, f));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    while (true) {
        bfs(s);
        if (level[t] < 0) return flow;

        iter.assign(N, 0);

        int f;
        while (true) {
            f = dfs(s, t, INF);
            if (f <= 0) break;
            flow += f;
        }
    }
    return flow;
}

int solve() {
    int mn = INF;
    for (int i=1; i<=n; ++i) {
        for (int j=i+1; j<=n; ++j) {
            for (int k=1; k<=n; ++k) G[k] = G0[k];
            mn = min(mn, maxflow(i, j));
        }
    }
    return mn;
}

int main() {
    io;
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v, 1);
        add_edge(v, u, 1);
    }
    int res = solve();
    cout << res << '\n';
    return 0;
}