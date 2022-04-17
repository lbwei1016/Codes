#include <iostream>
#include "9_topo.h"
using namespace std;

int main() {
    int V = 6, E = 8;
    vector<int> G[V];
    for (int i=0; i<E; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    TopoIterator it(V, G);
    auto v = it.get_all();
    for (auto x: v) {
        cout << x << ' ';
    }
    cout << '\n';
    cout << it.at() << ' ';
    it.advance();
    cout << it.at();
    return 0;
}