/*
***MST*** -- Kruskal
*/
#include <bits/stdc++.h>
using namespace std;

struct E { int from, to, w; };
int n, m;
vector<E> es;
int p[10005];

bool cmp(E e1, E e2) {
    return e1.w < e2.w;
}
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
int unite(int x, int y) {
    int p1 = find(x);
    int p2 = find(y);
    if(p1 == p2) return -p[p1];
    int sum = p[p1] + p[p2];
    if(p[p1] < p[p2]) {
        p[p1] = sum;
        p[p2] = p1;
    } else {
        p[p2] = sum;
        p[p1] = p2;
    }
    return -sum;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        es.push_back(E{u, v, w});
    }
    memset(p, -1, sizeof(p));
    sort(es.begin(), es.end(), cmp);

    int res = 0, size = 1;
    for(int i=0; i<m; i++) {
        E e = es[i];
        if(find(e.from) != find(e.to)) {
            res += e.w;
            size = unite(e.from, e.to);
            if(size == n) break;
        }
    }
    if(size < n) 
        printf("-1\n");
    else
        printf("%d\n", res);
    return 0;
}