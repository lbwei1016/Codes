/*
***Graph***
*/
#include <bits/stdc++.h>
using namespace std;

struct E { int to, w; };
int n, mx_len, mx_step;
vector<E> es[100004];

void dfs(int v, int step, int len) {
    if(es[v].size() == 0) {
        mx_step = max(mx_step, step);
        mx_len = max(mx_len, len);
        return;
    }
    for(auto u : es[v]) {
        dfs(u.to, step+1, len+u.w);
    }
    return;
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n-1; i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        es[v].push_back({i, w});
    }
    dfs(0, 0, 0);
    printf("%d\n%d\n", mx_len, mx_step);
    return 0;
}