#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P {
    int u, v;
};

bool planar() {
    int n, m;
    cin >> n >> m;
    vector<P> Es;
    for (int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        Es.push_back(P{u, v});
    }

    if (m > 3*n - 6) return false;

    for (int E=(1 << m)-1; E>=9; --E) {
        vector<int> G[n + 1];
        for (int i=0; i<m; ++i) {
            if (E & (1 << i)) {
                auto e = Es[i];
                G[e.u].push_back(e.v);
                G[e.v].push_back(e.u);
            }
        }
        for (int u=1; u<=n; ++u) {
            if (G[u].size() == 2) {
                int v1 = G[u][0], v2 = G[u][1];
                G[v1].erase(find(G[v1].begin(), G[v1].end(), u)); 
                G[v2].erase(find(G[v2].begin(), G[v2].end(), u));
                G[v1].push_back(v2); 
                G[v2].push_back(v1);
                G[u].clear();
            }
        }   

        // remove duplicate neighbors
        for (int u=1; u<=n; ++u) {
            if (G[u].empty()) continue;
            sort(G[u].begin(), G[u].end());
            G[u].resize(unique(G[u].begin(), G[u].end()) - G[u].begin());
        }

        auto K5 = [&]() {
            int cnt = 0;
            for (int u=1; u<=n; ++u) {
                if (G[u].empty()) continue;
                if (G[u].size() != 4) return false;
                ++cnt;
            }
            return cnt == 5;
        };
        auto K33 = [&, E]() {
            vector<int> ver;
            for (int u=1; u<=n; ++u) {
                if (G[u].empty()) continue;
                if (G[u].size() != 3) return false;
                ver.push_back(u);
            }
            if (ver.size() != 6) return false;
            for (int i=0; i<6; ++i) {
                int x = ver[i];
                for (int j=i+1; j<6; ++j) {
                    int y = ver[j];
                    for (int k=j+1; k<6; ++k) {
                        int z = ver[k];
                        if (G[x] == G[y] && G[y] == G[z]) {
                            return true;
                        }
                    }
                }
            }
            return false;
        };
        if (K5() || K33()) return false;
    }
    return true;
}

int main() {
    io;
    int q; 
    cin >> q;
    while (q--) {
        if (planar()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}