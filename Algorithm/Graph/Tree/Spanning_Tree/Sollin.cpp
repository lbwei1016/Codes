/*
***Graph / MST*** -- Sollin's Algorithm (Borůvka's Algorithm)
    Description:
        兩個操作:
            1. 針對每一連通子圖，找出對外的最小邊: O(E)
            2. 利用找出的最小邊們，連結連通子圖: O(V)
        由於連通子圖的數量會以 2 的次方遞減 (每次連結完剩不到一半)，因此上述操作
        最多執行 logV 次 => O(logV)

    Worst case: O((V+E)logV) => O(ElogV)
    Average case: O(V+E)

    Note:
        Sollin's Algorithm 可以用 DSU 來實作，簡便許多。
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const ll INF = 1e18;
struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge &e) const {
        return u==e.u ? v<e.v : u<e.u;
    }
};

ll Sollin(int V, vector<vector<Edge> > &G) {
    vector<Edge> mst; // 選出來的邊
    vector<int> label(V); // label[v] = 節點 v 的編號 (同一連通子圖編號相同)
    vector<vector<int> > table(V, vector<int>()); // table[k]: 那些節點的編號是 k
    ll total = 0; // total cost
    vector<int> component; // 連通子圖的集合

    for (int i=0; i<V; ++i) {
        label[i] = i;
        table[i].push_back(i);
        component.push_back(i);
    }

    while (component.size() > 1) {
        int sz = component.size();
        mst.clear();

        for (auto &lab: component) {
            int ver, which;
            ll mn = INF;
            // 在同一子圖 (編號同) 中，找出最小邊
            for (auto &u: table[lab]) {
                for (int i=0; i<G[u].size(); ++i) {
                    Edge &e = G[u][i];
                    if (label[e.u] == label[e.v]) continue;
                    if (e.w < mn) {
                        mn = e.w;
                        ver = u;
                        which = i;
                    }
                }
            }
            // 無法找到邊
            if (mn == INF) return -INF;
            mst.push_back(G[ver][which]);            
            G[ver][which].w = INF;
        }

        for (auto &e: mst) {
            if (label[e.u] == label[e.v]) continue;
            // 重新編號
            for (auto &u: table[label[e.u]]) {
                table[label[e.v]].push_back(u);
                label[u] = label[e.v];
            }
            total += e.w;
        }

        sz = component.size();
        vector<bool> vis(V);
        component.clear();
        // 計算剩餘的連通子圖
        for (int i=0; i<V; ++i) {
            if (vis[label[i]]) continue;
            vis[label[i]] = true;
            component.push_back(label[i]);    
        }
    }
    return total;
}

int main() {
    io;
    int V, E;
    while (cin >> V >> E) {
        vector<vector<Edge> > G(V, vector<Edge>());
        for (int i=0; i<E; ++i) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            G[u].push_back({u, v, w});
            G[v].push_back({v, u, w});
        }
        ll res = Sollin(V, G);
        if (res == -INF) cout << "-1\n";
        else cout << res << '\n';
    }    
    return 0;
}