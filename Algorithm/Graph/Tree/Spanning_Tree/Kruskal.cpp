/*
***Graph***
    Kruskal's algorithm:
        Find the Minimum Spanning Tree(MST), 
        through the selections of the shortest paths connecting two 
        subtrees (MSS: Minimum Spanning Subtree) which do not share 
        the same root. (using Union-Find Tree)
    O(E * logV)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_V = 100;
struct Edge { int u, v, w; };
int V, E, p[MAX_V];
vector<Edge> es;

void init() {
    es.clear();
    memset(p, -1, sizeof(p));
}

inline bool cmp(const Edge &e1, const Edge &e2) {
    return e1.w < e2.w;
}

int find(int x) {
    if (p[x] < 0) return x;
    else return p[x] = find(p[x]);
}

void unite(int x, int y) {
    int x = find(x), y = find(y);
    if (x == y) return;

    if (p[x] < p[y]) {
        p[x] += p[y];
        p[y] = x;
    }
    else {
        p[y] += p[x];
        p[x] = y;
    }
}

int kruskal() {
    int res = 0, cnt = 0;
    for (auto &e : es) {
        if (find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            ++cnt;
            res += e.w;
        }
    }
    return cnt==V-1 ? res : 1e9;
}

int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        es.push_back({u, v, w});
    }
    sort(es.begin(), es.end(), cmp);
    int res = kruskal();
    if(res == 1e9) cout << "No MST\n";
    else cout << "Sum: " << res << '\n';
    return 0;
}