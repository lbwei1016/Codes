/*
***Graph***
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m;
int w[N], lc[N], rc[N], in[105];

int dfs(int v) {
    if(v >= n) return w[v];
    return w[v] = dfs(lc[v]) + dfs(rc[v]);
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i=n; i<2*n; i++) {
        scanf("%d", &w[i]);
    }
    for(int i=0; i<m; i++) {
        scanf("%d", &in[i]);
    }
    for(int i=1; i<n; i++) {
        int p, s, t;
        scanf("%d%d%d", &p, &s, &t);
        lc[p] = s; rc[p] = t;
    }
    w[1] = dfs(1); //root
    for(int i=0; i<m; i++) {
        int v = 1;
        while(v < n) {
            if(w[lc[v]] <= w[rc[v]]) {
                v = lc[v];
            } else {
                v = rc[v];
            }
            w[v] += in[i];
        }
        printf("%d%c", v, i==m-1 ? '\n' : ' ');
    }
    return 0;
}