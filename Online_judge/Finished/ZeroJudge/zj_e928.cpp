/*
***Math / Divide and Conquer*** -- Karatsuba algorithm
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1<<10;
int F[N], G[N];

vector<int> dac(int f[], int g[], int n) {
    if(n == 2) {
        vector<int> mul(N);
        mul[2] = f[1]*g[1];
        mul[1] = f[1]*g[0] + f[0]*g[1];
        mul[0] = f[0]*g[0];
        return mul;
    }
    int k = n / 2;
    vector<int> res(N);
    if(k == 1) return res;
    int le[N] = {0}, ri[N] = {0};
    for(int i=0; i<k; ++i) le[i] = f[i] + f[i+k];
    for(int i=0; i<k; ++i) ri[i] = g[i] + g[i+k];
    vector<int> k_0 = dac(f, g, k), k_2 = dac(f+k, g+k, k);
    vector<int> kaa = dac(le, ri, k);
    for(int i=0; i<n; ++i) {
        res[i] += k_0[i];
        res[i+k] += kaa[i] - k_0[i] - k_2[i];
        res[i+n] += k_2[i];
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, to2 = 1;
    cin >> n;
    for(int i=n; i>=0; --i) cin >> F[i];
    cin >> m;
    for(int i=m; i>=0; --i) cin >> G[i];
    if(n < m) swap(n, m);
    while(to2 <= n) to2 <<= 1;
    n = to2;
    vector<int> res = dac(F, G, n);
    int st;
    for(st=2*n-1; res[st]==0; --st);
    cout << st << '\n';
    for(int i=st; i>=0; --i) cout << res[i] << ' ';
    cout << '\n';
}