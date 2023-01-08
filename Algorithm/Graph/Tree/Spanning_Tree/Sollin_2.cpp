/*
***Graph / MST*** -- Sollin's Algorithm (Borůvka's Algorithm)
    Description: 
        利用 DSU 實作，常數與空間複雜度皆較小較小，也較易於實作。

    O(ElogV)
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int MAXV = 1e5+5;
const ll INF = 1e18;
struct Edge {
    int u, v;
    ll w;
};

int p[MAXV];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (p[x] < p[y]) {
        p[x] += p[y];
        p[y] = x;
    }
    else {
        p[y] += p[x];
        p[x] = y;
    }
    return true;
}

ll Sollin(int V, int E, vector<Edge> &es) {
    memset(p, -1, sizeof(p));
    vector<ll> min_w(V, INF); // min_w[v]: v 節點所在的連通子圖的最小聯外邊權重
    vector<ll> num_e(V); // num_e[v]: v 節點所在的聯通子圖最小聯外邊的編號
    ll sum = 0;

    bool update = true;
    while (update) {
        update = false;
        fill(min_w.begin(), min_w.end(), INF);
        for (int i=0; i<E; ++i) {
            int x = find(es[i].u);
            int y = find(es[i].v);
            if (x == y) continue;

            update = true;
            ll w = es[i].w;
            // 如果此邊較小，更新
            if (w < min_w[x]) {
                min_w[x] = w;
                num_e[x] = i;
            }
            if (w < min_w[y]) {
                min_w[y] = w;
                num_e[y] = i;
            }
        }

        for (int i=0; i<V; ++i) {
            if (min_w[i] != INF) {
                // 如果此邊被採用，加上該權重
                if (unite(es[num_e[i]].u, es[num_e[i]].v)) {
                    sum += es[num_e[i]].w;
                }
            }
        }
    }
    // 檢查是否連通
    for (int i=0; i<V; ++i) {
        if (p[i] == -V) return sum;
    }
    return -1; // 不連通
}

int main() {
    io;
    int V, E;
    while (cin >> V >> E) {
        vector<Edge> es;
        for (int i=0; i<E; ++i) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            es.push_back({u, v, w});
        }
        cout << Sollin(V, E, es) << '\n';
    }

    return 0;
}