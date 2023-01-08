/*
***Graph*** --Tarjan's BCC algorithm (biconnected component)
    Description:
        找出所有割點（找割邊也是用同一個演算法，只要稍微修改）。移除所有割點之後，
        所有的 compoenet 都是 2-connected component；移除所有割邊後，所有 component
        都是 2-edge-connected component（也就是 biconnected）。
    Solution:
        重點在於 low 函數！
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e5 + 5, INF = 1e9 + 7;
vector<int> G[N];
int n, m;
vector<int> low(N); // low[v]: v 和他的子孫可以經由一條回邊走到深度最小的點的深度
vector<int> dep(N, -1);
set<int> cutv; // the set of cut vertices

// find all cut vertices
int dfs_vertex(int v, int d, int par) {
    low[v] = dep[v] = d;
    int chl = 0;
    for (auto u: G[v]) {
        if (u == par) continue;
        if (dep[u] != -1) {
            low[v] = min(low[v], dep[u]);
            continue;
        }
        ++chl;
        dfs_vertex(u, d + 1, v);
        low[v] = min(low[v], low[u]);
    }
    if (par != 1 && (low[v] == dep[v] || low[v] == dep[par])) {
        cutv.insert(par);
    }
    return chl;
}

stack<int> S; // 當前遍歷過，但還沒形成 bcc 的點。當 DFS 結束後，S 內的所有點自成一 bcc。
int bcc[N]; // 如果 u, v 在同一 bcc，則 bcc[u] = bcc[v]

// find all 2-edge-connected components
void dfs_edge(int v, int d, int par) {
    S.push(v);
    low[v] = dep[v] = d;
    for (auto u: G[v]) {
        if (u == par) continue;
        if (dep[u] != -1) {
            low[v] = min(low[v], dep[u]);
            continue;
        }
        dfs_edge(u, d + 1, v);
        low[v] = min(low[v], low[u]);
    }
    // bridge found
    if (low[v] == dep[v]) {
        int at;
        do {
            bcc[at = S.top()] = v;
            S.pop();
        } while (at != v);
    }
}

int main() {
    io;
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int chl = dfs_vertex(1, 0, 0);
    // If the root of the DFS tree has more than one subtree, it must be a cut vertex.
    if (chl > 1) cutv.insert(1);
    cutv.erase(0); // no such vertex

    cout << cutv.size() << '\n';
    for (auto x: cutv) cout << x << ' ';
    return 0;
}