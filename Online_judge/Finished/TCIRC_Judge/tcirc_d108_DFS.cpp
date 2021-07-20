/*
***Graph***
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
long long n;
long long w[N], des[N];
vector<int> chl[N];
long long len;

void dfs(int v) {
    des[v]++;
    for(int u : chl[v]) {
        dfs(u);
        des[v] += des[u];
    }
}
void trav(int v) {
    for(int u : chl[v]) {
        trav(u);
        len += 2LL * des[u] * (n-des[u]) * w[u];
    }
}
int main() {
    scanf("%lld", &n);
    for(int i=2; i<=n; i++) {
        int p;
        scanf("%d", &p);
        chl[p].push_back(i);
    }
    for(int i=2; i<=n; i++) {
        scanf("%lld", &w[i]);
    }
    dfs(1);
    trav(1);
    printf("%lld\n", len);
    return 0;
}