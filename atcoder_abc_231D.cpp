#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e5+5;
vector<int> G[N];
set<pair<int, int> > table;
bool vis[N];
bool cycle;

bool trav(int at, int p) {
    if (G[at].size() > 2) 
        return false;
    bool ok = true;
    for (auto &u: G[at]) {
        if (p == u) continue;
        if (vis[u]) return false;
        else {
            vis[u] = true;
            ok &= trav(u, at);
        }
    }
    return ok;
}
// 4 5 1 2 3
int main() {
    // io;
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        if (table.count(make_pair(u, v)) || table.count(make_pair(v, u))) 
            continue;
        G[u].push_back(v);
        G[v].push_back(u);
        // ++cnt;
        table.insert(make_pair(u, v));
    }
    bool ok = true;
    for (int i=1; i<=n; ++i) {
        if (!vis[i]) {
            ok &= trav(i, 0);
        }
    }
    if (ok) puts("Yes");
    else puts("No");
    return 0;
}
// no cycle