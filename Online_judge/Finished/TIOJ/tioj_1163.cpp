/*
***Graph*** -- MST / LCA
    Solution:  
        1.  要找最快抵達的方法 -> MST
        2.  是否到達要看路徑中的最大值 -> LCA (log V 查詢)
    O(E*logV + QlogV) (MST + LCA query)
*/  
#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 30005, logV = 17;
struct Edge { int fr, to, w; };
struct P { int u, w; };
int V, E, Q, par[MAX_V], tin[MAX_V], tout[MAX_V], t_cnt=0;
vector<Edge> es;
vector<P> G[MAX_V];
P anc[MAX_V][logV]; // anc[][].u: 該代祖先是誰；anc[][].w: 到該祖先的最大權重
bitset<MAX_V> vis; 

bool cmp(Edge e1, Edge e2) { return e1.w < e2.w; }
int find(int x) { return par[x] < 0 ? x : par[x]=find(par[x]); }
bool is_anc(int x, int y) { return tin[x]<=tin[y] && tout[x]>=tout[y]; }
void unite(int x, int y) {
    int r1 = find(x), r2 = find(y);
    if(r1 == r2) return;
    if(par[r1] < par[r2]) {
        par[r1] += par[r2];
        par[r2] = r1;
    }
    else {
        par[r2] += par[r1];
        par[r1] = r2;
    }
}
void kruskal() {
    memset(par, -1, sizeof(par));
    sort(es.begin(), es.end(), cmp);
    for(auto e : es) {
        int u = e.fr, v = e.to, w = e.w;
        if(find(u) != find(v)) {
            unite(u, v);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
    }
}
void dfs(int v, int p) {
    tin[v] = ++t_cnt; vis[v] = 1;
    anc[v][0].u = p;
    for(int i=1; i<logV; ++i) {
        anc[v][i].u = anc[anc[v][i-1].u][i-1].u;
        // 紀錄最大權重
        anc[v][i].w = max(anc[v][i-1].w, anc[anc[v][i-1].u][i-1].w);
    }
    for(auto e : G[v]) {
        int u = e.u, w = e.w;
        if(u == p) continue;
        anc[u][0].w = w;
        dfs(u, v);
    }
    tout[v] = ++t_cnt;
}
int LCA(int x, int y) {
    if(is_anc(x, y)) return x;
    if(is_anc(y, x)) return y;
    // x 爬上來
    for(int i=logV-1; i>=0; --i) {
        if(!is_anc(anc[x][i].u, y)) {
            x = anc[x][i].u;
        }
    }
    return anc[x][0].u;
}
int getMax(int x, int y) {
    if(x == y) return 0;
    if(is_anc(x, y)) swap(x, y); // 讓 x 爬上來
    int mx = 0;
    for(int i=logV-1; i>=0; --i) {
        if(!is_anc(anc[x][i].u, y)) {
            mx = max(mx, anc[x][i].w);
            x = anc[x][i].u;
        }
    }
    return max(mx, anc[x][0].w);
}
int main() {
    // 0 是任何人的祖先！！！！
    tin[0] = -1, tout[0] = 1e9;

    scanf("%d%d", &V, &E);
    for(int i=0; i<E; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        es.push_back({u, v, w});
    }
    kruskal();
    vis.reset();
    // 遍歷森林
    for(int i=1; i<=V; ++i) {
        if(vis[i]) continue;
        t_cnt = 0;
        dfs(i, 0);
    }

    scanf("%d", &Q);
    for(int i=0; i<Q; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        if(find(u) != find(v)) puts("-1");
        else if(u == v) puts("0");
        else {
            int lca = LCA(u, v);
            printf("%d\n", max(getMax(u, lca), getMax(lca, v)));
        }
    }
    return 0;
}
/* 也可以把 LCA 和 getMax 寫在一起
int LCA(int x, int y) {
    int mx = 0;
    if(is_anc(y, x)) swap(x, y);
    else if(!is_anc(x, y)){
        // x 爬上來
        for(int i=logV-1; i>=0; --i) {
            if(!is_anc(anc[x][i].u, y)) {
                mx = max(mx, anc[x][i].w);
                x = anc[x][i].u;
            }
        }
        mx = max(mx, anc[x][0].w);
        x = anc[x][0].u;
    }
    // y 爬上來
    for(int i=logV-1; i>=0; --i) {
        if(!is_anc(anc[y][i].u, x)) {
            mx = max(mx, anc[y][i].w);
            y = anc[y][i].u;
        }
    }
    return max(mx, anc[y][0].w);
}
*/