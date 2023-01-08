/*
***Math / Divide and Conquer***
    Description:
        和一般直式算法的複雜度其實一樣。
    O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1<<22;
int n;
int F[N], G[N];
vector<int> dac(int f[], int g[], int k) {
    if(k == 2) {
        vector<int> mul(n);
        mul[2] += f[1]*g[1];
        mul[1] += f[0]*g[1] + f[1]*g[0];
        mul[0] += f[0]*g[0];
        return mul;
    }
    int m = k / 2;
    vector<int> res(2*n);
    vector<int> k_0 = dac(f, g, m), k_11 = dac(f+m, g, m);
    vector<int> k_12 = dac(f, g+m, m), k_2 = dac(f+m, g+m, m);
    for(int i=0; i<k; ++i) {
        res[i] += k_0[i];
        res[i+m] += k_11[i]+k_12[i];
        res[i+k] += k_2[i];
    }
    return res;
}
int main() {
    int to2 = 1;
    memset(F, 0, sizeof(F));
    memset(G, 0, sizeof(G));
    cin >> n;
    for(int i=n; i>=0; --i) cin >> F[i];
    for(int i=n; i>=0; --i) cin >> G[i];
    while(to2 <= n) to2 <<= 1;
    n = to2;
    vector<int> res = dac(F, G, n);
    for(int i=2*n; i>=0; --i) cout << res[i] << ' ';

    return 0;
}