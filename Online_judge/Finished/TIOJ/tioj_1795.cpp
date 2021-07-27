/*
***Graph*** -- MST
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+4;
struct E { int u, v, c; };
int n, m, k, p[N];
vector<E> es;

bool cmp(E ea, E eb) {
    return ea.c < eb.c;
}
int find(int x) {
    return p[x] < 0 ? x : p[x]=find(p[x]);
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
int kruskal() {
    int res = 0;
    for(auto e : es) {
        int u = e.u, v = e.v, c = e.c;
        if(find(u) != find(v)) {
            unite(u, v);
            res += c;
        }
    }
    return res;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    memset(p, -1, sizeof(p));
    for(int i=0; i<m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        es.push_back({u, v, c});
    }
    sort(es.begin(), es.end(), cmp);

    int mn = kruskal();
    memset(p, -1, sizeof(p));
    reverse(es.begin(), es.end());
    int mx = kruskal();

    if(mn<=k && k<=mx) puts("TAK");
    else puts("NIE");

    return 0;
}