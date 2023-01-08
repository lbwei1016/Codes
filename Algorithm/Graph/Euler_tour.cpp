/*
***Graph*** -- Euler tour
    Description:
        找出最小字典序的 Euler tour。
    Solution:
        優先走連到編號小的點的邊，再倒過來輸出點的離開順序。
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int MAXV = 500 + 5;
vector<int> res;
multiset<int> G[MAXV];

void trav(int at) {
    while (G[at].size()) {
        int to = *G[at].begin();
        G[to].erase(G[to].find(at));
        G[at].erase(G[at].find(to));
        trav(to);
    }
    res.push_back(at);
}

int main() {
    io;
    int V, E;
    while (cin >> E) {
        if (!E) break; 
        for (int i=0; i<E; ++i) {
            int u, v; cin >> u >> v;
            G[u].insert(v);
            G[v].insert(u);
        }

        int st = 1;
        for (int i=1; i<MAXV; ++i) {
            if (G[i].size() & 1) {
                st = i;
                break;
            }
        }
        trav(st);
        while (res.size()) {
            cout << res.back() << '\n';
            res.pop_back();
        }
        cout << '\n';
    }
    return 0;
}