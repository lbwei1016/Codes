/*
***Graph*** -- diameter, radius, center of tree (*)
    Description:
        將森林中的各樹連通，並使得最後合併出的樹具有最小的直徑。
    Solution:
        找出各樹的重心，再將所有樹的重心與半徑最大的樹的重心連接起來 (最小化直徑)，
        並考慮兩種可能為合併後的樹直徑的情況:
            1.  最大 + 次大半徑 + L (題目給的連接長度)
            2.  次大 + 第三大半徑 + 2L (先走到最大半徑樹再走向次大半徑樹)
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
struct E { int to, w; };
int n, m, l, D;
bitset<N> vis;
vector<E> ds(N), G[N];

int dfs(int v, int p) {
    vis[v] = 1;

    int id = 0, d = 0;
    for(auto e : G[v]) {
        int u = e.to, w = e.w;
        if(u == p) continue;
        d = w + dfs(u, v);
        // record the highest child
        if(d > id) {
            id = d; 
            ds[v].to = u; ds[v].w = w;
        }
    }
    return id;
}
int main() {
    while(scanf("%d%d%d", &n, &m, &l) != EOF) {
        // init!!!
        for(int i=0; i<n; ++i) {
            ds[i].to = -1; ds[i].w = 1e9;
            G[i].clear();
        }
        vis.reset();

        for(int i=0; i<m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        int res = 0; 
        int mx[5] = {0}; // 分屬不同棵樹的前三大半徑 (多分配空間來存非前三大值)
        for(int i=0; i<n; ++i) {
            if(!vis[i]) {
                dfs(i, n);
                int v, sum = 0, dx, st = 3;
                // go to the deepest leaf -- an end point of diameter
                for(v=i; ds[v].to>0; v=ds[v].to); 
                D = dfs(v, n);

                res = max(res, D); // self
                while(sum+ds[v].w <= D/2) {
                    sum += ds[v].w;
                    v = ds[v].to;
                }
                dx = min(sum+ds[v].w, D-sum);
                // record the 1-st, 2-nd, and 3-rd great value, consecutively
                // point!!!
                while(st && dx > mx[st-1]) {
                    mx[st] = mx[st-1];
                    st--;
                }
                mx[st] = dx;
            }
        }
        // 有三顆以上的樹 / 只有兩棵樹
        if(n-m > 2) res = max(res, max(mx[0]+mx[1]+l, mx[1]+mx[2]+2*l));
        else if(n-m > 1) res = max(res, mx[0]+mx[1]+l); 
        printf("%d\n", res);
    }
    return 0;
}