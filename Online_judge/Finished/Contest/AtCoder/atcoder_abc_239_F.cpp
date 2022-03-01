/*
***Graph***
    Solution:
        定義連通分量的總分支度為 DEG。
        將連通分量分成兩類: DEG = 1 和 DEG > 1。逐步連通 DEG = 1 和
        DEG > 1 的分量。(why?)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
struct P { 
    int id, d; 
    bool operator<(P p) const {
        return d < p.id;
    }
};
int n, m;
vector<int> deg(N);
vector<int> G[N];  

int p[N];

int find(int x) {
    if(p[x] < 0) return x;
    else return p[x] = find(p[x]);
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
}

int main() {
    memset(p, -1, sizeof(p));
    cin >> n >> m;

    for (int i=0; i<n; ++i) {
        cin >> deg[i];
    }

    for (int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
        --deg[u], --deg[v];
        unite(u, v);
    }

    vector<vector<int> > tmp(n);
    for (int i=0; i<n; ++i) {
        if (deg[i] < 0) {
            puts("-1");
            return 0;
        }
        int px = find(i);
        // 以 Union Find 來記錄連通分量
        for (int j=0; j<deg[i]; ++j) {
            // i 要幾個分支度就放幾個 i 進去
            tmp[px].push_back(i);
        }
    }

    vector<int> c1; // deg = 1
    vector<vector<int> > c2; // deg > 1

    for (int i=0; i<n; ++i) {
        if (tmp[i].size() == 1) c1.push_back(tmp[i][0]);
        else if (tmp[i].size() > 1) {
            // tmp[i].push_back(i);
            c2.push_back(tmp[i]);
        }
    }

    vector<pair<int, int> > ans;
    // 此處保證 deg > 1 都用完
    for (auto x: c2) {
        for (int i=0, len=x.size(); i<len-1; ++i) {
            if (c1.empty()) {
                puts("-1");
                return 0;
            }
            unite(x[i], c1.back());
            ans.push_back(make_pair(x[i], c1.back()));
            c1.pop_back();
        }
        c1.push_back(x.back());
    }

    // 非 2 則不可能連通
    if (c1.size() != 2) {
        puts("-1");
        return 0;
    }
    unite(c1[0], c1[1]);
    // if not all connected, -1
    int mn = 0;
    for (int i=0; i<n; ++i) {
        mn = min(mn, p[i]);
    }
    // 並不完全連通
    if (-mn != n) {
        puts("-1");
        return 0;
    } 
    
    ans.push_back(make_pair(c1[0], c1[1]));
    for (auto x: ans) {
        cout << x.first+1 << ' ' << x.second+1 << '\n';
    }

    return 0;
}