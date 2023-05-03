/*
***Minimum Vertex Cover*** -- Kőnig's Theorem
try other implementations
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 505;
vector<int> G[N], match(N, -1);
bitset<N> vis; // visited vertices (for "only one" dfs)

bool dfs(int v, set<int> &X, vector<int> &S) {
    if (X.count(v)) S.push_back(v);
    for (auto u: G[v]) {
        if (vis[u]) continue;
        vis[u] = 1;
        if (match[u] == -1 || dfs(match[u], X, S)) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int matching(int n, set<int> &X, vector<int> &S) {
    int res = 0;
    S.clear();
    for (auto v: X) {
        if (match[v] == -1) {
            vis.reset();
            // S.clear();
            if (dfs(v, X, S)) ++res;
        }
    }
    return res;
}

/*
Calculate distances between nodes.
(To distinguish "v" being at which side of the partite.)
*/ 
void disCalc(int v, vector<int> &dis, vector<int> &nodes) {
    vis[v] = true;
    for (auto u: G[v]) {
        if (vis[u]) continue;
        dis[u] = dis[v] + 1;
        nodes.push_back(u);
        disCalc(u, dis, nodes);
    }
}

vector<int> minimum_vertex_cover(set<int> &X, vector<int> &S) {
    vector<int> VC; // VC = (X\S) \union T (T is matched by a subset of S)
    bitset<N> vis;
    for (auto u: S) vis[u] = 1;
    for (auto u: X) {
        if (!vis[u]) VC.push_back(u);
        else if (match[u] != -1) 
            VC.push_back(match[u]);
    }
    return VC;
}

int main() {
    io;
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // two partites: X and Y
    set<int> X, Y;
    vector<int> dis(n, 0);
    vis.reset();
    for (int v=0; v<n; ++v) {
        if (vis[v]) continue;
        X.insert(v);

        vector<int> nodes;
        disCalc(v, dis, nodes);
        for (auto u: nodes) {
            if (dis[u] % 2 == 0) X.insert(u);
            else Y.insert(u);
        }
    }

    vector<int> S; // visited vertices in X (for the whole matching() process)
    int res = matching(n, X, S);
    vector<pair<int, int>> matches;
    for (auto u: X) {
        if (match[u] != -1) 
            matches.push_back({u, match[u]});
    }

    // This is necessary!!! To obtain the visited vertices (S) in the "last run".
    matching(n, X, S);
    
    auto C = minimum_vertex_cover(X, S);

    cout << res << '\n';
    for (auto p: matches) cout << p.first << ' ' << p.second << '\n';
    cout << res << '\n';
    for (auto u: C) cout << u << ' ';
    return 0;
}
/*
Q:
8 8
0 6
1 4
1 5
1 6
1 7
2 6
2 7
3 6

A:
3
0 6
1 4
2 7
3
1 2 6
*/