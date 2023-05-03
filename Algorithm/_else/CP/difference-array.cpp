/*
***Difference Array*** -- off-line range add and query
    Description:
        See https://codeforces.com/blog/entry/78762?fbclid=IwAR1pXBco25EwUCFboO2k-JMHtspVoC1zSt7dJNxHPdsWICrYrLdNXOork8I.
    Note:
        Range add can be done in O(1).
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P { int l, r; ll d; };

int main() {
    io;
    int n, m, k;
    cin >> n >> m >> k;
    // odiff[]: difference array for operation ranges
    vector<ll> v(n), diff(n + 2), odiff(m + 2);
    vector<P> op(m);
    for (int i=0; i<n; ++i) cin >> v[i];
    for (int i=0; i<m; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        --l;
        op[i] = P{l, r, d};
    }
    for (int i=0; i<k; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        odiff[l]++;
        odiff[r]--;
    }
    for (int i=1; i<m; ++i) {
        odiff[i] += odiff[i - 1];
    }
    for (int i=0; i<m; ++i) {
        auto p = op[i];
        diff[p.l] += p.d * odiff[i];
        diff[p.r] -= p.d * odiff[i];
    }
    for (int i=1; i<n; ++i) {
        diff[i] += diff[i - 1];
    }
    for (int i=0; i<n; ++i) cout << v[i] + diff[i] << ' ';
    return 0;
}