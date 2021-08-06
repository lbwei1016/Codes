/*
***Graph / Disjoint Set***
    原題等價為：求給的圖的補圖的連通塊數
    嘗試一：建構出補圖，但補圖為稠密圖，因此不是 TLE 就是 MLE
    嘗試二：http://cbdcoding.blogspot.com/2015/02/tioj-1220.html
            尚未理解成功
*/
#include <bits/stdc++.h>
using namespace std;

const int V = 1e5+10;
int n, m, p[V];
vector<int> G[V];
bitset<V> vis;

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
int main() {
    memset(p, -1, sizeof(p));
    vis.reset();
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1; i<=n; ++i) {
        
    }
    int cnt = 0;
    printf("%d\n", cnt);
    return 0;
}