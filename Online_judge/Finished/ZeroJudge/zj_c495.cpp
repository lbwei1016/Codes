/*
***Graph*** -- Second-best Spanning Tree
    Solution:
        1.  先找出 MST
        2.  遍歷該 MST，找出祖先關係，並記錄路徑上的最大權重
        3.  針對未包含於 MST 中的邊，列舉所有邊 e'(u, v)；去除 (u, v) 在
            MST 上的最大權重邊 e(u, v) (利用 LCA)，並加入新列舉出的 e'(u, v)，獲得
            新的展開樹權重和。(意思就是先把樹切開，再用新的邊連起來)
    O(ElogE (Kruskal) + VlogV (dfs) + ElogV (getmax)) 
    = O(ElogE)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
const ll MAX_V = 1e5+2, MAX_E = 5e5+2;
const ll logV = 18; // log(2)(1e5/2)
struct Edge { 
    ll u, v, w; 
    bool operator< (const Edge &e) {
        return w < e.w;
    }
};
ll V, E, par[MAX_V];
vector<Edge> es, adj[MAX_V]; // adj[] 借用 Edge，u 為閒置變數
bool vis[MAX_E]; // 紀錄是否為 MST 的邊
inline void init();
inline ll find(ll);
void unite(ll, ll);
ll kruskal();

ll t_in[MAX_V], t_out[MAX_V], timer;
ll anc[MAX_V][logV+1], maxw[MAX_V][logV+1];
inline bool is_anc(ll, ll);
void dfs(ll, ll);
ll getmax(ll, ll);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    ll mn, mn2 = 1e18;
    cin >> V >> E;
    for(ll i=0; i<E; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        es.push_back({u, v, w});
    }
    sort(es.begin(), es.end());
    mn = kruskal();
    for(ll i=1; i<=V; ++i) {
        if(!adj[i].empty()) {
            dfs(i, 0); break;
        }
    }
    for(ll i=0; i<E; ++i) {
        if(vis[i]) continue;
        Edge e = es[i];
        if(e.u == e.v) continue;
        ll wei = getmax(e.u, e.v);
        mn2 = min(mn2, mn-wei+e.w);
    }
    cout << mn << ' ' << mn2 << '\n';
    return 0;
}

inline void init() {
    memset(par, -1, sizeof(par));
    t_in[0] = -1, t_out[0] = 1e9;
}
inline ll find(ll x) {
    return par[x]<0 ? x : par[x]=find(par[x]);
}
void unite(ll x, ll y) {
    ll r1 = find(x), r2 = find(y);
    if(par[r1] < par[r2]) {
        par[r1] += par[r2];
        par[r2] = r1;
    }
    else {
        par[r2] += par[r1];
        par[r1] = r2;
    }
}
ll kruskal() {
    ll res = 0, cnt = 0;
    for(ll i=0; i<E; ++i) {
        Edge e = es[i];
        if(find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            vis[i] = 1;
            adj[e.u].push_back({-1, e.v, e.w});
            adj[e.v].push_back({-1, e.u, e.w});
            ++cnt;
            res += (ll)e.w;
        }
    }
    return cnt==V-1 ? res : 1e18;
}
inline bool is_anc(ll x, ll y) {
    return t_in[x]<=t_in[y] && t_out[x]>=t_out[y];
}
void dfs(ll v, ll p) {
    t_in[v] = ++timer;
    anc[v][0] = p;
    for(ll i=1; i<=logV; ++i) {
        anc[v][i] = anc[anc[v][i-1]][i-1];
        maxw[v][i] = max(maxw[v][i-1], maxw[anc[v][i-1]][i-1]);
    }
    for(auto e : adj[v]) {
        if(e.v == p) continue;
        maxw[e.v][0] = e.w;
        dfs(e.v, v);
    }
    t_out[v] = ++timer;
}
ll getmax(ll x, ll y) {
    ll mx = 0;
    if(is_anc(y, x)) swap(x, y);
    else if(!is_anc(x, y)) {
        for(ll i=logV; i>=0; --i) {
            if(!is_anc(anc[x][i], y)) {
                mx = max(mx, maxw[x][i]);
                x = anc[x][i];
            }
        }
        mx = max(mx, maxw[x][0]);
        x = anc[x][0];
    }
    for(ll i=logV; i>=0; --i) {
        if(!is_anc(anc[y][i], x)) {
            mx = max(mx, maxw[y][i]);
            y = anc[y][i];
        }
    }
    return max(mx, maxw[y][0]);
}