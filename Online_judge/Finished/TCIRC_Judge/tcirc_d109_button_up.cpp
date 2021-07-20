/*
***Graph / DP*** -- Max Weight Independent Set
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
int p[N], f0[N], f1[N], deg[N];
int main() {
    scanf("%d%d", &n, &f1[1]);
    for(int i=2; i<=n; i++) {
        scanf("%d%d", &p[i], &f1[i]);
        deg[p[i]]++;
    }
    queue<int> que;
    for(int i=1; i<=n; i++) {
        if(deg[i] == 0)     
            que.push(i);
    }
    while(true) {
        int v = que.front(); que.pop();
        if(v == 1) break;
        int par = p[v];
        f0[par] += max(f0[v], f1[v]);
        f1[par] += f0[v];
        if(--deg[par] == 0) que.push(par);
    }
    printf("%d\n", max(f0[1], f1[1]));
    return 0;
}