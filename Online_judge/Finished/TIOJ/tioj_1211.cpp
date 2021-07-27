/*
***MST***
*/
#include <bits/stdc++.h>
using namespace std;

const int V = 10005;
struct E { int u, v, w; };
int n, m, p[V];
vector<E> es;

bool cmp(E e1, E e2) {
    return e1.w < e2.w;
}
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void unite(int x, int y) {
    int r1 = find(x);
    int r2 = find(y);
    if(r1 == r2) return;
    if(p[r1] < p[r2]) {
        p[r1] += p[r2];
        p[r2] = r1;
    }
    else {
        p[r2] += p[r1];
        p[r1] = r2;
    }
}
int Kruskal(int n) {
    int res = 0, cnt = 0;
    sort(es.begin(), es.end(), cmp);
    for(auto e : es) {
        int u = e.u, v = e.v, w = e.w;
        if(find(u) != find(v)) {
            unite(u, v);
            res += w; ++cnt;
        }
    }
    if(cnt < n-1) return -1;
    return res; 
}

int main() {
    while(scanf("%d%d", &n, &m) == 2) {
        if(n == 0) break;
        es.resize(m);
        memset(p, -1, sizeof(p));
        for(int i=0; i<m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            es[i] = {u, v, w};
        }
        printf("%d\n", Kruskal(n));
    }
    return 0;
}