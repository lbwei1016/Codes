#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;
using mat = vector<vector<int> >;

const int N = 505;
// int A[N][N], B[N][N], R[N], C[N], n;
int n;
ll min_cost;

void reduce(int &unknown, mat &A, int times) {
    bool update = true;
    while (update) {
        update = false;
        // row
        for (int i=0; i<n; ++i) {
            int cnt = 0;
            int x, y;
            for (int j=0; j<n; ++j) {
                if (A[i][j] == -1 || A[i][j] < -1*times) {
                    ++cnt;
                    x = i, y = j;
                }
                if (cnt > 1) break;
            }
            if (cnt == 1) {
                A[x][y] = -1*times;
                if (--unknown == 0) return;
                update = true;
            }
            // else update_r = false;
        }
        // col
        for (int i=0; i<n; ++i) {
            int cnt = 0;
            int x, y;
            for (int j=0; j<n; ++j) {
                if (A[j][i] == -1 || A[j][i] < -1*times) {
                    ++cnt;
                    x = j, y = i;
                }
                if (cnt > 1) break;
            }
            if (cnt == 1) {
                A[x][y] = -1*times;
                if (--unknown == 0) return;
                update = true;
            }
            // else update_c = false;
        }
    } 
}

void rec(int &unknown, ll cost, mat &A, mat &B, int times, vector<int> &cho) {
    reduce(unknown, A, times);
    if (unknown == 0) {
        cout << "---------------------\nSolution:\n";
        for (auto x: cho) cout << x << ' ';
        cout << "\n---------------------\n";
        min_cost = min(min_cost, cost);
        return;
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (A[i][j] == -1 || A[i][j] < -1*times) {
                if (cost + B[i][j] >= min_cost) continue;
                A[i][j] = 0;
                int uk = unknown - 1;
                // --unknown;
                cho.push_back(B[i][j]);
                rec(uk, cost+B[i][j], A, B, times+1, cho);
                A[i][j] = -1;
                cho.pop_back();
                // ++unknown;
            }
        }
    }
}

int main() {
    // io;
    int t; cin >> t;
    for (int i=1; i<=t; ++i) {
        cin >> n;
        mat A(n, vector<int>(n)), B(n, vector<int>(n));
        vector<int> R(n), C(n);
        int unknown = 0;
        min_cost = 1e17;


        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                cin >> A[i][j];
                if (A[i][j] == -1)
                    ++unknown;
            }
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                cin >> B[i][j];
            }
                
        for (int i=0; i<n; ++i)
            cin >> R[i];
        for (int i=0; i<n; ++i)
            cin >> C[i];
        vector<int> cho;
        rec(unknown, 0, A, B, 2, cho);
        printf("Case #%d: %lld\n", i, min_cost);
    }
    return 0;
}