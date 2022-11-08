/*
***Bipartite Matching***

    Find the "maximun matching" in a bipartite matching.
    
    O(V * E)
*/
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int MAX_V = 100;

int V;
vector<int> G[MAX_V];    
vector<int> match(MAX_V, -1);
bitset<MAX_V> vis;

bool dfs(int v) {
    for (auto u: G[v]) {
        if (vis[u]) continue;
        vis[u] = true;
        if (match[u] == -1 || dfs(match[u])) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int matching() {
    int res = 0;
    for (int i=0; i<V; ++i) {
        if (match[i] == -1) {
            vis.reset();
            if (dfs(i)) ++res;
        }
    }
    return res;
}


int main() {
    //Input
    return 0;
}