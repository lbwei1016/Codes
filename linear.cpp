#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;
using mat = vector<vector<int> >;

const int N = 505;
struct P {
    int r, c;
};
// int A[N][N], B[N][N], R[N], C[N], n;
int n;
ll min_cost;

void reduce(int &unknown, list<P> &A) {
    bool update = true;
    int len = A.size();
    while (update) {
        update = false;
        int row = A.begin()->r, cnt = 1;
        for (auto it=++A.begin(); it!=A.end(); ++it) {
            if (it->r != row) {
                if (cnt == 1) {
                    A.erase(--it);
                    update = true;
                }
                cnt = 1;
            }
            else ++cnt;
        }
    }
}

void rec(int &unknown, ll cost, list<P> A, mat &B) {
    reduce(unknown, A);
    if (unknown == 0) {
        min_cost = min(min_cost, cost);
        return;
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (A[i][j] == -1) {
                if (cost + B[i][j] >= min_cost) continue;
                A[i][j] = 0;
                int uk = unknown - 1;
                // --unknown;
                rec(uk, cost+B[i][j], A, B);
                A[i][j] = -1;
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
        list<P> A;
        mat B(n, vector<int>(n));
        vector<int> R(n), C(n);
        int unknown = 0;
        min_cost = 1e17;


        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                int val;
                cin >> val;
                if (val == -1) {
                    A.push_back(P{i, j});
                }
                    // ++unknown;
            }
        }
        A.push_back(P{1000, 1000});
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                cin >> B[i][j];
            }
                
        for (int i=0; i<n; ++i)
            cin >> R[i];
        for (int i=0; i<n; ++i)
            cin >> C[i];
        rec(unknown, 0, A, B);
        printf("Case #%d: %lld\n", i, min_cost);
    }
    return 0;
}