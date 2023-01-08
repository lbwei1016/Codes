/*
***The Erdős-Gallai theorem***
    Description:
        Given a degree sequence, determine whether it is graphical.
    Solution:
        Search the theorem itself first.
        Precalculate prefix sum and suffix sum of the degree sequence, and then
        use binary search to find 'm' s.t. 'dm' is the first one <= 'k'.
    Complexity:
        O(n logn): 'n' is the number of vertices.
    Note:
        This algorithm is faster than the ones based on "Havel-Hakimi theorem", 
        which takes O(n^2) or worse.
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool solve(vector<int> &deg, int n) {
    sort(deg.begin(), deg.end());
    ll sum = 0;
    vector<ll> psum(n+1, 0), ssum(n+1, 0);
    for (int i=1; i<=n; ++i) {
        psum[i] = psum[i-1] + deg[i-1];
        ssum[n-i] = ssum[n-i+1] + deg[n-i];
        sum += deg[i-1];
    }
    if (sum & 1) return false;

    for (int i=0; i<n; ++i) {
        ll k = n - i;
        int at = lower_bound(deg.begin(), deg.begin()+i, k) - deg.begin();
        ll rs = k*(k-1) + psum[at] + k*((n-at+1)-k-1);
        if (ssum[i] > rs) return false;
    }
    return true;
}

int main() {
    io;
    int q; cin >> q;
    while (q--) {
        int n, m; cin >> n >> m;
        vector<int> deg(n);
        for (int i=0; i<n; ++i) {
            int a; cin >> a;
            deg[i] = a;
        }

        bool good = true;
        for (int i=0; i<m; ++i) {
            int u, v; cin >> u >> v;
            --u; --v;
            if (--deg[u] < 0) good = false; 
            if (--deg[v] < 0) good = false;
        }

        if (good)
            good &= solve(deg, n);

        if (good) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}