/*
***Maximum Bipartite Matching*** -- Hopcroft-Karp Algorithm
    credit: https://judge.yosupo.jp/submission/52112

    Time: O(E * sqrt(V))
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 505;
vector<int> G[N];
vector<int> match(N, -1), dis(N);

void bfs(vector<int> &X) {
    queue<int> que;
    for (auto u: X) {
        if (match[u] == -1) {
            que.push(u);
            dis[u] = 0;
        }
        else dis[u] = -1;
    }

    while (que.size()) {
        int u = que.front(); que.pop();
        for (auto v: G[u]) {
            if (match[v] != -1 && dis[match[v]] == -1) {
                dis[match[v]] = dis[u] + 1;
                que.push(match[v]);
            }
        }
    }
}

bool dfs(int u) {
    for (auto v: G[u]) {
        if (match[v] == -1) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    for (auto v: G[u]) {
        if (dis[match[v]] == dis[u] + 1 && dfs(match[v])) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int matching(vector<int> &X) {
    int res = 0;
    while (true) {
        bfs(X);
        int augment = 0;
        for (auto u: X) 
            if (match[u] == -1) augment += dfs(u);
        if (!augment) break;
        res += augment;
    }
    return res;
}

vector<pair<int, int>> get_edges(vector<int> &X) {
    vector<pair<int, int>> edges;
    for (auto u: X) {
        if (match[u] != -1) {
            edges.emplace_back(u, match[u]);
        }
    }
    return edges;
}

vector<int> get_min_vertex_cover(vector<int> &X) {
    vector<int> VC;
    for (auto u: X) {
        if (dis[u] == -1) VC.push_back(u);
        else if (match[u] != -1) VC.push_back(match[u]);
    }
    return VC;
}

// for partitioning given graph
void disCalc(int v, vector<int> &dis, vector<int> &nodes, bitset<N> &vis) {
    vis[v] = true;
    for (auto u: G[v]) {
        if (vis[u]) continue;
        dis[u] = dis[v] + 1;
        nodes.push_back(u);
        disCalc(u, dis, nodes, vis);
    }
}

int main() {
    io;
    int n, m; cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // two partites: X and Y
    vector<int> X, Y, dis(n, 0);
    bitset<N> vis;
    for (int v=0; v<n; ++v) {
        if (vis[v]) continue;
        X.emplace_back(v);

        vector<int> nodes;
        disCalc(v, dis, nodes, vis);
        for (auto u: nodes) {
            if (dis[u] % 2 == 0) X.emplace_back(u);
            else Y.emplace_back(u);
        }
    }

    int res = matching(X);
    cout << res << '\n';
    return 0;
}