/*
***Graph***
    Description:
        2022/05/09，較簡潔的實作。
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
struct Edge {
    int u, v, cost;
};

vector<int> pre;
vector<Edge> edge;
int V, E;

int bellman_ford(int fr, int to) {
    vector<int> dis(V+1, INF);
    pre.resize(V+1, -1);

    bool update = true;
    int cntV = 0;
    dis[fr] = 0;
    while (update) {
        update = false;
        if (cntV++ == V) return -INF; // negative loop
        for (auto &e: edge) {
            if (dis[e.u] != INF && dis[e.v] > dis[e.u] + e.cost) {
                update = true;
                dis[e.v] = dis[e.u] + e.cost;
                pre[e.v] = e.u;
            }
        }
    }
    return dis[to];
}

vector<int> get_path(int to) {
    vector<int> path(1, to);
    for (int v=to; pre[v]>0; v=pre[v]) {
        path.push_back(pre[v]);
    }
    return path;
}

int main() {
    // input for edges
    cin >> V >> E;
    edge.resize(E);
    for (int i=0; i<E; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edge.push_back({u, v, cost});
    }

    int dis = bellman_ford(1, 5);
    if (dis != -INF) {
        printf("The shortest distance is: %d\n", dis);
    
        puts("The path is:");
        vector<int> path = get_path(5);
        for (auto it=path.rbegin(); it!=path.rend(); ++it) 
            cout << *it << ' ';
    }
    else cout << "Negative cycle!\n";

    return 0;
}

/* test data
6 9
1 2 3 
1 4 7 
2 3 4
2 4 5
3 5 3
3 6 6
4 6 1
4 5 9
6 2 -6
*/