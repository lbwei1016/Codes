#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> a, b;
int dp[101][20005];

bool rec(int at, int d) {
    if(d == n) return (at == x);
    if(at >= x) return false;

    int toa = at + a[d], tob = at + b[d];
    // bool res = 0;
    if(dp[d][toa] < 0) dp[d][toa] = rec(toa, d+1);

    if(dp[d][tob] < 0) dp[d][tob] = rec(tob, d+1);
    return dp[d][toa] | dp[d][tob];
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> x;
    a.resize(n), b.resize(n);
    for(int i=0; i<n; ++i) {
        cin >> a[i] >> b[i];
    }
    if(rec(0, 0)) puts("Yes");
    else puts("No");
    return 0;
}