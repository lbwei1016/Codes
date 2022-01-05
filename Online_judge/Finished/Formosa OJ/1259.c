#include <stdio.h>
#define MAX_V 105
#define INF 1000000000

int V, E, s, t, d[MAX_V];
int G[MAX_V][MAX_V];

int bfs() {
    for(int i=0; i<MAX_V; ++i) d[i] = INF;
    int que[MAX_V], head = 0, tail = 0;
    que[tail++] = s; d[s] = 0;
    while(head < tail) {
        int v = que[head++];
        if(v == t) return d[v];
        for(int i=0; i<G[0][v]; ++i) {
            int to = G[v][i];
            if(d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                que[tail++] = to;
            }
        }
    }
    return -1;
}
int main() {
    scanf("%d %d", &V, &E);
    for(int i=0; i<E; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        ++u; ++v; // numbered from 1
        G[u][G[0][u]++] = v;
        G[v][G[0][v]++] = u;
    }
    scanf("%d %d", &s, &t);
    ++s; ++t;
    int res = bfs();
    if(res < 0) puts("Oops");
    else printf("%d\n", res);
    return 0;
}