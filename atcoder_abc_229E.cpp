#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int MAXV = 2e5+5;
vector<int> G[MAXV];
int p[MAXV];

int cc;

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (p[x] < p[y]) {
        p[x] += p[y];
        p[y] = x;
    }
    else {
        p[y] += p[x];
        p[x] = y;
    }
    --cc;
}

int main() {
    // io;
    memset(p, -1, sizeof(p));
    int V, E;
    cin >> V >> E;
    for (int i=0; i<E; ++i) {
        int u, v;
        // --u, --v;
        cin >> u >> v;
        --u, --v;
        if (u < v) swap(u, v);
        G[v].push_back(u);
    }

    vector<int> res(1);
    for (int i=V-1; i>=0; --i) {
        ++cc;
        for (auto v: G[i]) {
            unite(v, i);
        }
        res.push_back(cc);
    }

    res.pop_back();
    reverse(res.begin(), res.end());
    // res.pop_back();
    for (auto x: res) {
        cout << x << '\n';
    }
    return 0;
}