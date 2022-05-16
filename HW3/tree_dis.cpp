#include <bits/stdc++.h>
using namespace std;

const int N = 100;

void shortest_path(int v, int par, vector<int> &dis, vector<int> G[]) {
    for (auto u: G[v]) {
        if (u == par) continue;
        dis[u] = dis[v] + 1;
        shortest_path(u, v, dis, G);
    }
}

int main() {
    vector<int> G[N];
    int n;
    cin >> n;
    for (int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int v = 0;
    vector<int> dis(N, 1e9);
    dis[0] = 0;
    shortest_path(v, -1, dis, G);
    return 0;
}