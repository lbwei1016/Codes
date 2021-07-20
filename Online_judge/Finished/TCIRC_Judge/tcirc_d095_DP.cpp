/*
***DP / Graph*** -- top-down / DAG
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+1;
const int INF = 2e9;
struct E { int pre, w; };
struct D { int md, Md; };
int n, m, s, t;
vector<E> pre[N];
int md[N], Md[N];

D dis(int u) {
    //whether visited
    if(md[u] <= INF && Md[u] >= -INF) 
        return D{md[u], Md[u]};
    md[u] = INF; Md[u] = -INF;
    for(auto e : pre[u]) {
        D d = dis(e.pre);
        md[u] = min(md[u], d.md + e.w);
        Md[u] = max(Md[u], d.Md + e.w);
    }
    return D{md[u], Md[u]};
}
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        pre[v].push_back(E{u, w}); 
    }
    fill(md, md+n, INF+1);
    fill(Md, Md+n, -INF-1);      
    md[s] = Md[s] = 0;

    dis(t);
    if(md[t] >= INF) printf("No path\nNo path\n");
    else printf("%d\n%d", md[t], Md[t]);
    return 0;
}