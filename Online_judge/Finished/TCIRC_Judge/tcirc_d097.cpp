/*
***Union and Find***
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 300000;
int m, n, k, n_a, a_max;
int G[N], p[N];
int dd[] = {1, -1};

int find(int x) {
    if(p[x] < 0) return x;
    else return p[x] = find(p[x]);
}
void unite(int x, int y) {
    int p1 = find(x);
    int p2 = find(y);
    if(p1 == p2) return;
    a_max = max(a_max, -p[p1]-p[p2]);
    n_a--;
    if(p[p1] < p[p2]) {
        p[p1] += p[p2];
        p[p2] = p1;
    } else {
        p[p2] += p[p1];
        p[p1] = p2;
    }
}
int dfs(int s, int root) {
    p[s] = root;
    int area = 1;
    for(int i=0; i<4; i++) {
        int t = s + dd[i];
        if(G[t] && p[t] == -1) {
            area += dfs(t, root);
        }
    }
    return area;
}
int main() {
    scanf("%d%d%d", &m, &n, &k);
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", G+i*(n+2)+j);
            p[i*(n+2)+j] = -1;
        }
    }
    dd[2] = n+2, dd[3] = -n-2;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            int t = i*(n+2)+j;
            if(G[t] && p[t] == -1) {
                p[t] = -dfs(t, t);
                n_a++;
                a_max = max(-p[t], a_max);
            }
        }
    }
    long long n_sum = n_a, max_sum = a_max;
    while(k--) {
        int i, j, t;
        scanf("%d%d", &i, &j);
        t = i*(n+2)+j;
        if(G[t]) continue;
        G[t] = 1;
        n_a++;
        for(int l=0; l<4; l++) {
            if(!G[t+dd[l]]) continue;
            unite(t, t+dd[l]);
        }
        n_sum += n_a;
        max_sum += a_max;
    }
    printf("%lld\n%lld\n", max_sum, n_sum);
    return 0;
}