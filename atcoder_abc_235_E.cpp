/*
***MST / LCA***
    Description:
        Given a graph first. After that, give an edge once ,and find 
        the MST after considering that edge, i.e. whether that edge can 
        be substituted for an existing edge.
    Solution:
        Kruskal for MST;
        LCA for finding the largerst edge in the path along the two 
        vertices of the given edge. (O(logV))
    O(ElogE + QlogV)
*/
#include <bits/stdc++.h>
#define max(a, b) ((a)>(b)?(a):(b))
using namespace std;

const int MAX_N = 2e5+5;
struct E { 
    int u, v, w; 
    bool operator <(const E &e) const {
        return w < e.w;
    }
};
int n, m, q;    
vector<E> es;
vector<E> mst[MAX_N];
int p[MAX_N];

int t;
int tin[MAX_N], tout[MAX_N];
int anc[MAX_N][(int)log2(MAX_N/2)+1];
int anc_w[MAX_N][(int)log2(MAX_N/2)+1];

constexpr int log2(int x) {
    int i = 0;
    while(1<<i <= x) ++i;
    return i-1;
}
int find(int x) {
    if(p[x] < 0) return x;
    else return p[x] = find(p[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(p[x] < p[y]) {
        p[x] += p[y];
        p[y] = x;
    }
    else {
        p[y] += p[x];
        p[x] = y;
    }
}
void kruskal() {
    for(auto e: es) {
        if(find(e.u) != find(e.v)) {
            join(e.u, e.v);
            mst[e.u].push_back(E{0, e.v, e.w});
            mst[e.v].push_back(E{0, e.u, e.w});
        }
    }
}
void dfs(int v, int par) {
    tin[v] = ++t;
    anc[v][0] = par;
    int logV = log2(n/2) + 1;
    for(int i=1; i<logV; ++i) {
        anc[v][i] = anc[anc[v][i-1]][i-1];
        anc_w[v][i] = max(anc_w[v][i-1], anc_w[anc[v][i-1]][i-1]);
    }
    for(auto u: mst[v]) {
        if(u.v == par) {
            continue;
        }
        anc_w[u.v][0] = u.w;
        dfs(u.v, v);
    }
    tout[v] = ++t;
}
bool is_anc(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int LCA(int u, int v) {
    int w = 0;
    // if(is_anc(u, v)) swap(u, v);
    
    for(int i=log2(n/2); i>=0; --i) {
        if(!is_anc(anc[u][i], v)) {
            w = max(w, anc_w[u][i]);
            u = anc[u][i];
        }
    }
    if(!is_anc(u, v))
        w = max(w, anc_w[u][0]);
    for(int i=log2(n/2); i>=0; --i) {
        if(!is_anc(anc[v][i], u)) {
            w = max(w, anc_w[v][i]);
            v = anc[v][i];
        }
    }
    if(!is_anc(v, u))
        w = max(w, anc_w[v][0]);
    return w;
}

int main() {
    memset(p, -1, sizeof(p));
    cin >> n >> m >> q;
    for(int i=0; i<m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        es.push_back(E{u, v, w});
    }
    sort(es.begin(), es.end());
    kruskal();
    
    for(int i=0; i<MAX_N; ++i) {
        if(mst[i].size()) {
            dfs(i, 0);
            tin[0] = -1;
            tout[0] = 1e9;
            break;
        }
    }

    while(q--) {
        int u, v, w;
        cin >> u >> v >> w;
        if(w < LCA(u, v)) puts("Yes");
        else puts("No");
    }
    return 0;
}