#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
// using int = long long;

// struct P {
//     int x, y;
//     int val;
//     bool operator<(P p) const {
//         return x == p.x ? y < p.y : x < p.x;
//     }
// };

map<int, map<int, int>> X, Y;

int solve() {
    int res = 0;
    map<int, int> rsum, csum;
    // csum(C);
    // for (int i=0; i<R; ++i) {
    //     for (int j=0; j<C; ++j) {
    //         rsum[i] += G[i][j];
    //     }
    // }
    // for (int j=0; j<C; ++j) {
    //     for (int i=0; i<R; ++i) {
    //         csum[j] += G[i][j];
    //     }
    // }

    int mxr = 0, wr;
    for (auto &px: X) {
        for (auto &v: px.second) {
            rsum[px.first] += v.second;
        }
        if (rsum[px.first] > mxr) {
            wr = px.first;
            mxr = rsum[px.first];
        }
    }


    int mxc = 0, wc;
    for (auto &py: Y) {
        for (auto &v: py.second) {
            csum[py.first] += v.second;
        }
        if (csum[py.first] > mxc) {
            wc = py.first;
            mxc = csum[py.first];
        }
    }

    cout << mxr << ' ' << mxc << '\n';
    // for (int j=0; j<C; ++j) {
    //     int mx[3] = {0};
    //     for (int i=0; i<R; ++i) {
    //         mx[2] = rsum[i] - G[i][j];
    //         int at = 2;
    //         while (at > 0 && mx[at-1] < mx[at]) {
    //             swap(mx[at-1], mx[at]);
    //             at--;
    //         }
    //     }
    //     res = max(res, mx[0] + mx[1] + csum[j]);
    // }

    // for (auto &py: Y) {
        int j = wc;
        int mx[3] = {0};
        for (auto &px: X) {
            int i = px.first;
            mx[2] = rsum[i] - X[i][j];
            int at = 2;
            while (at > 0 && mx[at-1] < mx[at]) {
                swap(mx[at-1], mx[at]);
                at--;
            }
        }
        res = max(res, mx[0] + mx[1] + csum[j]);
        res = max(res, mx[0] + mx[1] + mx[2]);
    // }

    // cout << res << '\n';

    // for (int i=0; i<R; ++i) {
    //     int mx[3] = {0};
    //     for (int j=0; j<C; ++j) {
    //         mx[2] = csum[j] - G[i][j];
    //         int at = 2;
    //         while (at > 0 && mx[at-1] < mx[at]) {
    //             swap(mx[at-1], mx[at]);
    //             at--;
    //         }
    //     }
    //     res = max(res, mx[0] + mx[1] + rsum[i]);
    // }

    // for (auto &px: X) {
        int i = wr;
        // int mx[3] = {0};
        memset(mx, 0, sizeof(mx));
        for (auto &py: Y) {
            int j = py.first;
            mx[2] = csum[j] - Y[j][i];
            int at = 2;
            while (at > 0 && mx[at-1] < mx[at]) {
                swap(mx[at-1], mx[at]);
                at--;
            }
        }
        res = max(res, mx[0] + mx[1] + rsum[i]);
        res = max(res, mx[0] + mx[1] + mx[2]);
    // }

    return res;
}

int main() {
    io;
    int n; cin >> n;
    // vector<int> X, Y;
    // set<P> ps;
    for (int i=0; i<n; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        // ps.insert(P{x, y, v});
        // X.push_back(x); Y.push_back(y);
        X[x][y] = v;
        Y[y][x] = v;
    }

    // sort(X.begin(), X.end());
    // sort(Y.begin(), Y.end());
    // X.resize(unique(X.begin(), X.end()) - X.begin());
    // Y.resize(unique(Y.begin(), Y.end()) - Y.begin());

    // assert(X.size() * Y.size() < 10000000);

    // vector<vector<int>> G1/*,G2*/;

    // G1.resize(X.size(), vector<int>(Y.size(), 0));
    // // G2.resize(Y.size(), vector<int>(X.size(), 0));

    // for (auto p: ps) {
    //     p.x = lower_bound(X.begin(), X.end(), p.x) - X.begin();
    //     p.y = lower_bound(Y.begin(), Y.end(), p.y) - Y.begin();
    //     G1[p.x][p.y] = p.val;
    //     // G2[p.y][p.x] = p.val;
    // }

    // int v1 = solve(G1);
    // int v2 = solve(G2);
    // cout << "G1: " << v1 << '\n';
    // cout << "G2: " << v2 << '\n';

    // cout << max(v1, v2) << '\n';
    // cout << v1 << '\n';

    cout << solve();
    
    return 0;
}
/*
7
1 1 5
1 2 2
1 3 2
2 1 5
2 2 3
3 1 5
3 2 5
*/