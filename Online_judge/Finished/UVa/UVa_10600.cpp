/*
***Graph*** -- Second-best Spanning Tree
    Solution:
        先找出 MST，再一次去除 MST 上一條邊，並加入新的邊形成新的 ST，
        此 V-1 棵 (可能沒這麼多，因為可能去除了兩連通區塊的唯一邊) ST 的
        最小值即是「次小生成數」。
    Note:
        還有更快的演算法。
    O(V*ElogE) = O(n*mlogm)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 105;
struct E { int u, v, w, id; };
int t, n, m, p[N];
vector<E> es;
bitset<100000> vis, ban;

bool inline cmp(const E &e1, const E &e2) {
    return e1.w < e2.w;
}
void init() {
    es.clear();
    vis.reset(); ban.reset();
    memset(p, -1, sizeof(p));
}
int find(int x) {
    return p[x]<0 ? x : p[x]=find(p[x]);
}
void unite(int x, int y) {
    int r1 = find(x), r2 = find(y);
    // if(r1 == r2) return;
    if(p[r1] < p[r2]) {
        p[r1] += p[r2];
        p[r2] = r1;
    }
    else {
        p[r2] += p[r1];
        p[r1] = r2;
    }
}
int min_sptree(bool flag) {
    int res = 0, cnt = 0;
    for(auto e : es) {
        if(ban[e.id]) continue;
        int u = e.u, v = e.v;
        if(find(u) != find(v)) {
            unite(u, v);
            if(flag) vis[e.id] = 1;
            res += e.w;
            ++cnt;
        }
    }
    if(cnt != n-1) return 1e9;
    return res;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        init();
        int mn, mn2 = 1e9;
        scanf("%d%d", &n, &m);
        for(int i=0; i<m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            es.push_back({u, v, w, i});
        }
        sort(es.begin(), es.end(), cmp);
        mn = min_sptree(1);
        for(int i=0; i<m; ++i) {
            if(vis[i]) {
                ban[i] = 1;
                memset(p, -1, sizeof(p));
                mn2 = min(mn2, min_sptree(0));
                ban[i] = 0;
            }
        }
        printf("%d %d\n", mn, mn2);
    }
    return 0;
}