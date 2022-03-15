/*
***DP** --memoization
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5;
struct P {
    // ll num;
    vector<ll> ball;
};
ll n, X;
map<ll, unordered_map<ll, ll> > dp;

ll rec(int d, ll prod, vector<P> &v) {
    if (d == n) return prod == X;
    if (dp[d].count(prod)) return dp[d][prod];
    dp[d][prod] = 0;
    for (int i=0, len=v[d].ball.size(); i<len; ++i) {
        if (prod*v[d].ball[i] > X) continue;
        dp[d][prod] += rec(d+1, prod*v[d].ball[i], v);
    }
    return dp[d][prod];
}

int main() {
    cin >> n >> X;
    vector<P> v(n);
    for (int i=0; i<n; ++i) {
        int L; cin >> L;
        v[i].ball.resize(L);
        for (int j=0; j<L; ++j) {
            cin >> v[i].ball[j];
        }
    }
    cout << rec(0, 1, v) << '\n';
    return 0;
}