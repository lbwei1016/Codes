#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int V = 100;
vector<int> G[V]; // adjacency list
bool vis[V]; // true if visited 

void bfs(int st) {
    queue<int> que;
    que.push(st);
    fill(vis, vis+V, 0);

    while (que.size()) {
        auto v = que.front(); que.pop();
        vis[v] = true;
        cout << v << ' ';

        for (auto u: G[v]) {
            if (vis[u]) continue;
            que.push(u);
        } 
    }
}

int main() {
    // io;
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bfs(2);
    return 0;
}