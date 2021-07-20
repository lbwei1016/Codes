#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int N = 1e4+5;
int n, m;
vector<P> G[N]; //v, w
int d[N];

void dijkstra() {
    fill(d, d+n, 1e9);
    priority_queue<int, vector<P>, greater<P> > pq;
    pq.push({d[0]=0, 0}); //dis, v
    while(!pq.empty()) {
        P p = pq.top(); pq.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(auto e : G[v]) {
            int u = e.first, w = e.second;
            if(d[u] > d[v]+w) {
                d[u] = d[v] + w;
                pq.push({d[u], u});
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
    dijkstra();
    int mx = -1, cnt = 0;
    for(int i=0; i<n; i++) {
        if(d[i] < 1e9) {
            if(d[i] > mx) mx = d[i];
        } else cnt++;
    }
    printf("%d\n%d\n", mx, cnt);
    return 0;
}