/*
***Graph / DP*** -- Max Weight Independent Set
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
int p, f0[N], f1[N];
vector<int> chl[N];

void dfs(int v) {
    for(int u : chl[v]) {
        dfs(u);
        f1[v] += f0[u];
        f0[v] += max(f0[u], f1[u]);
    }
    return;
}
int main() {
    scanf("%d%d", &n, &f1[1]);
    for(int i=2; i<=n; i++) {
        scanf("%d%d", &p, &f1[i]);
        chl[p].push_back(i);
    }
    dfs(1);
    printf("%d\n", max(f1[1], f0[1]));
    return 0;
}