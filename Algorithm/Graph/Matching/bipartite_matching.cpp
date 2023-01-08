/*
***Bipartite Matching*** -- Hungarian Algorithm
    Description:
        Find the "maximum matching" in a bipartite graph.
    Note:
        |maximum matching| = |minimum vertex cover|
    O(V * E)
*/
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int MAX_V = 100;

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

// 為什麼某個 match 更新過後，之前沒有 match 到的不需要再檢查一次 ?
int matching(int n) {
    int res = 0;
    for (int i=1; i<=n; ++i) {
        if (match[i] == -1) {
            vis.reset();
            if (dfs(i)) ++res;
        }
    }
    return res;
}


int main() {
    /*
        有些情況下，bipartite graph 兩邊的編號在題目中會重疊（例如都從 1 開始），
        所以才把某邊加上 M。
    */
    const int M = 500; 
    int n; cin >> n;
    for (int i=1; i<=n; ++i) {
        int sz = 0; cin >> sz;
        for (int j=0; j<sz; ++j) {
            int u; cin >> u;
            u += M;
            G[i].push_back(u);
            G[u].push_back(i);
        }
    }
    int res = matching(n);
    return 0;
}