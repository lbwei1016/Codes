/*
***Graph*** -- LCA
    比 LCA_1 省空間
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int n, sz;
vector<vector<int>> sl, up;
vector<int> d;

void precalc(int v, int p){
    d[v] = d[p] + 1;
    up[v][0] = p;
    for(int i = 1; i <= sz; ++i){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for(int u: sl[v]){
        if(u == p) continue;
        precalc(u, v);
    }
}

int lca(int u, int v){
    if(d[u] < d[v]){
        swap(u, v);
    }
    for(int cur = sz; cur >= 0; --cur){
        if (d[u] - (1 << cur) >= d[v]) {
            u = up[u][cur];
        }
    }
    for(int cur = sz; cur >= 0; --cur){
        if (up[u][cur] != up[v][cur]) {
            u = up[u][cur];
            v = up[v][cur];
        }
    }
    return u == v ? u : up[u][0];
}

int main() {
    // io;
    
    return 0;
}