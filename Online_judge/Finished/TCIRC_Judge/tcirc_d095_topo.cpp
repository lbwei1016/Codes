/*
***Graph*** -- DAG 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+1;
const int INF = 2e9;
struct E { int to, w; };
int n, m, s, t;
vector<E> G[N];
int indgree[N];
int md[N], Md[N];

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(E{v, w});
        indgree[v]++;
    }
    fill(md, md+n, INF);
    fill(Md, Md+n, -INF);
    md[s] = Md[s] = 0;
    queue<int> Q;
    for(int i=0; i<n; i++) {
        if(indgree[i] == 0)
            Q.push(i);
    }
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(auto e : G[u]) {
            md[e.to] = min(md[e.to], md[u] + e.w);
            Md[e.to] = max(Md[e.to], Md[u] + e.w);
            if(--indgree[e.to] == 0) {
                Q.push(e.to);
            }
        }
    }
    if(md[t] == INF) printf("No path\nNo path\n");
    else printf("%d\n%d", md[t], Md[t]);

    return 0;
}