/*
***Graph*** -- median of tree
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, med;
long long len;
int w[N], des[N]; //descendant
vector<int> chl[N];

void dfs(int v) {
    for(int u : chl[v]) {
        dfs(u);
        des[v] += des[u];
        len += min(des[u], n-des[u]) * w[u];
    }
    des[v]++;
    if(med < 0 && des[v] >= n/2)
        med = v;
    return;
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int p, r;
        scanf("%d%d", &p, &r);
        chl[p].push_back(i);
        w[i] = r;
    }
    med = -1;
    dfs(0);
    printf("%d\n%lld\n", med, len);
    return 0;
}