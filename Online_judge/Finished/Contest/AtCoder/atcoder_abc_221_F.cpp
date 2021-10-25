/*
***Tree*** -- diameter, center (*)
    Description:
        Choose two or more of the vertices and paint them red so that 
        all distances between two red vertices are D. Find the number.
    Solution:
        There two scenarios: D is odd or even.
        The methods to deal with them are different, but it can be summarized
        into below concept:
            1. Find the center of the tree after obtaining the diameter.
            2. Divide the tree into several sub-tree, which is cut with the center(s).
            3. Count the number of the nodes(in sub-trees) that comply with the demands. (D/2 or D/2-1)
        For detailed information, visit https://atcoder.jp/contests/abc221/editorial/2731.
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
const int N = 2e5+5;
vector<int> G[N];
// des[v]: descendant(child) of "v"
int n, D, des[N];

// 回傳深度 (for finding diameter)
int dfs(int v, int p) {
    int d0 = 0, d = 0;
    for(auto u : G[v]) {
        if(u == p) continue;
        d = 1 + dfs(u, v);
        if(d > d0) {
            d0 = d;
            des[v] = u;
        }
    }
    return d0;
}

// 回傳符合條件的個數 (for counting)
int trav(int v, int p, int d, const int eq) {
    int cnt = 0;
    if(d == eq) ++cnt;
    for(auto u : G[v]) {
        if(u == p) continue;
        cnt += trav(u, v, d+1, eq);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    memset(des, -1, sizeof(des));

    for(int i=0, u, v; i<n-1; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    int v, mid, rad = 0;
    for(v=1; des[v]>0; v=des[v]);
    D = dfs(v, 0);
    while(rad + 1 <= D/2) {
        ++rad; v = des[v];
    }
    mid = v;

    ll res = 1;
    if(D % 2 == 0) {
        ll sum = 0;
        vector<ll> cnt;
        for(auto u : G[mid]) {
            cnt.push_back(trav(u, mid, 0, D/2-1)); 
        }
        for(auto x : cnt) {
            res *= (x+1LL); 
            res %= MOD;
            sum += x;
        }
        // 扣除只選一或全不選的情形 (choose two or more of the vertices)
        res -= (sum + 1LL);
    }
    else {
        ll cnt1 = trav(mid, des[mid], 0, D/2);
        ll cnt2 = trav(des[mid], mid, 0, D/2);
        res = (cnt1*cnt2)%MOD;
    }
    cout << res << '\n';
    return 0;
}