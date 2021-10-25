#include <bits/stdc++.h>
using namespace std;

int m, n;
// v is the sequence
vector<int> A, u, v;

int main() {
    cin >> m >> n;
    A.resize(m);
    u.resize(n);
    // v.resize(m);
    for(int i=0; i<m; ++i) cin >> A[i];
    for(int i=0; i<n; ++i) cin >> u[i];
    for(int i=0, j=0; i<n;) {
        if(u[i] <= j) {
            cout << v[i] << '\n';
            ++i;
        }
        else {
            v.insert(lower_bound(v.begin(), v.end(), A[j]), A[j]);
            ++j;
        }
    }
    return 0;
}