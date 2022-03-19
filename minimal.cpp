#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;
using mat = vector<vector<int> >;

const int N = 505;
struct P { 
    int r, c, cost; 
    bool operator<(P p) const {
        return cost < p.cost;
    }
};
int n;
multiset<P> neg_1s;

void reduce(int &unknown, mat &A, mat &B) {
    bool update = true;
    while (update) {
        update = false;
        // row
        for (int i=0; i<n; ++i) {
            int cnt = 0;
            int x, y;
            for (int j=0; j<n; ++j) {
                if (A[i][j] == -1) {
                    ++cnt;
                    x = i, y = j;
                }
                if (cnt > 1) break;
            }
            if (cnt == 1) {
                A[x][y] = 0;
                neg_1s.erase(P{x, y, B[x][y]});
                if (--unknown == 0) return;
                update = true;
            }
        }
        // col
        for (int i=0; i<n; ++i) {
            int cnt = 0;
            int x, y;
            for (int j=0; j<n; ++j) {
                if (A[j][i] == -1) {
                    ++cnt;
                    x = j, y = i;
                }
                if (cnt > 1) break;
            }
            if (cnt == 1) {
                A[x][y] = 0;
                neg_1s.erase(P{x, y, B[x][y]});
                if (--unknown == 0) return;
                update = true;
            }
        }
    }
}

ll solve(int &unknown, mat &A, mat &B, vector<P> &cho) {
    ll cost = 0;
    while (!neg_1s.empty()) {
        reduce(unknown, A, B);
        if (neg_1s.empty()) return cost;
        auto mn = neg_1s.begin();
        A[mn->r][mn->c] = 0;
        cho.push_back(P{mn->r, mn->c});
        cost += B[mn->r][mn->c];
        neg_1s.erase(mn);
    }
    return cost;
}

int main() {
    // io;
    int t; cin >> t;
    for (int i=1; i<=t; ++i) {
        cin >> n;
        mat A(n, vector<int>(n)), B(n, vector<int>(n));
        vector<int> R(n), C(n);
        int unknown = 0;

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> A[i][j];
            }
        }
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                cin >> B[i][j];
            }

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j] == -1) {
                    ++unknown;
                    neg_1s.insert(P{i, j, B[i][j]});
                }
            }
        }
                
        for (int i=0; i<n; ++i)
            cin >> R[i];
        for (int i=0; i<n; ++i)
            cin >> C[i];
        vector<P> cho;
        // rec(unknown, 0, A, B, 2, cho);
        // puts("-------------------");
        printf("Case #%d: %lld\n", i, solve(unknown, A, B, cho));
        // for (auto x: cho) {
        //     printf("(%d, %d): %d\n", x.r, x.c, B[x.r][x.c]);
        // }
        // puts("-------------------");
    }
    return 0;
}