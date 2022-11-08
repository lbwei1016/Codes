#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1005, M = 15;
int G[M][N];

struct P {
    int cnt;
    vector<pair<int, int>> at;
    P (): cnt(0) { at.clear(); }
};

bool ok[M];

bool check(int m) {
    for (int i=0; i<m; ++i) {
        if (!ok[i]) return false;
    }
    return true;
}

int main() {
    io;
    int n, m; cin >> n >> m;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> G[i][j];
        }
    }

    map<int, P> mp;
    vector<pair<int, int>> update(m); 
    vector<int> cand;
    // iota(update.begin(), update.end(), 0);
    for (int i=0; i<m; ++i) {
        update[i] = make_pair(i, 0);
    }
    while (true) {
        if (update.empty()) break;

        bool flag = false;
        for (auto up: update) {
            int x = up.first, y = up.second;
            if (y == n) continue;
            auto it = mp.find(G[x][y]);
            if (it == mp.end()) {
                mp.insert(make_pair(G[x][y], P()));
                it = mp.find(G[x][y]);
            }

            // cand.push_back(G[x][y]);
            ok[x] = 1;
            if (check(m)) {
                flag = true;
                break;
            }

            it->second.cnt++;
            it->second.at.push_back(make_pair(x, y));
        }

        if (flag) break;
        update.clear();
        for (auto &p: mp) {
            if (p.second.cnt > 1) {
                for (auto &x: p.second.at) {
                    update.push_back(make_pair(x.first, x.second+1));
                }
                // p.second.cnt = 0;
                p.second.at.clear();
            }  
        }
    }

    // sort(cand.begin(), cand.end());
    // cand.resize(unique(cand.begin(), cand.end()) - cand.begin());

    // cout << cand.size() << '\n';
    // for (auto x: cand) cout << x << ' ';

    return 0;
}
/*
5 3
1 3 4 5 2
3 1 2 5 4
3 2 1 5 4
*/