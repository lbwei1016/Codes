#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
struct Edge {
    int to, length;
};

vector<int> bellman_ford(vector<vector<Edge> > &adjlist, const int V, const int st) {
    vector<int> dis(V, INF);
    bool update = true;
    int cnt = 0;

    dis[st] = 0;
    while (update) {
        update = false;
        // negative loop occurs
        if (cnt++ == V) return vector<int>();
        for (int u=0; u<V; ++u) {
            for (auto &edge: adjlist[u]) {
                if (dis[edge.to] > dis[u] + edge.length) {
                    dis[edge.to] = dis[u] + edge.length;
                    update = true;
                }
            }
        }
    }
    return dis;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<Edge> > adjlist(V, vector<Edge>());
    for (int i=0; i<E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u].push_back({v, w});
        // adjlist[v].push_back({u, w});
    }
    auto dis = bellman_ford(adjlist, V, 0);
    if (dis.empty()) cout << "negtive loop\n";
    else cout << dis[5] << '\n';
    return 0;
}
/*
7 8
0 1 5
0 3 2
1 2 1
2 4 -1
3 4 2
4 5 2
1 5 10
3 6 4
*/