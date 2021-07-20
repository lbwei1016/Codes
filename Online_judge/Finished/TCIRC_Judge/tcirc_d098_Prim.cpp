/*
***MST*** -- Prim
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int N = 1e4+5;
const int INF = 1e9;
struct E { int to, w; };
int n, m;
int d[N];
vector<E> G[N];
bool visit[N];

void prim() {
    fill(d, d+n, INF);
    priority_queue<P, vector<P>, greater<P> > pq;
    pq.emplace(d[0]=0, 0);
    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int v = p.second;
        if(visit[v]) continue;
        visit[v] = true;
        for(auto e : G[v]) {
            int u = e.to, w = e.w;
            if(visit[u]) continue;
            if(d[u] > w) {
                d[u] = w;
                pq.emplace(d[u], u);
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    prim();
    int cnt = 0, res = 0;
    for(int i=0; i<n; i++) {
        if(d[i] < INF) {
            res += d[i];
            cnt++;
        }
    }
    if(cnt < n) printf("-1\n");
    else printf("%d\n", res);
    return 0;
}