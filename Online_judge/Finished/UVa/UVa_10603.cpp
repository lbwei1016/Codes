/*
***BFS (隱式圖) / Hash*** -- tioj_1008
    Solution:
        要特別注意，最早達到某狀態的水量未必是最佳值，要持續更新至最後。
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int L = 201;
const ll INF = 1e18;
struct P { int s; ll d; };
int t, cap[3], a[3], b[3], D;
ll res[L]; // res[i]; 任一量杯達到 i 水量的最少需求水量
unordered_map<int, ll> vis; // hash table
queue<P> que;

void encode(ll d) {
    int s = 0;
    for(int i=2; i>=0; --i) {
        s <<= 8;
        s |= a[i];
    }
    auto it = vis.find(s);
    // 若同一狀態有較小水量，更新
    if(it!=vis.end() && it->second<d) return;
    vis[s] = d;
    que.push({s, d});
}
ll decode() {
    auto x = que.front(); que.pop();
    // 去除過時的狀態
    while(vis[x.s] < x.d) {
        x = que.front(); que.pop();
    }
    for(int i=0; i<3; ++i) {
        b[i] = x.s & 255;
        x.s >>= 8;
    }
    return x.d;
}
void bfs() {
    a[0] = a[1] = 0; a[2] = cap[2];
    res[cap[2]] = 0; res[0] = 0;
    encode(0);
    while(!que.empty()) {
        ll d = decode();
        for(int i=0; i<3; ++i) a[i] = b[i];
        // j -> i
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                if(i == j) continue;
                if(b[i]==cap[i] || b[j]==0) continue;
                ll x = d;
                if(b[i]+b[j] < cap[i]) {
                    x += b[j];
                    a[j] = 0; a[i] = b[i]+b[j];
                }
                else {
                    x += cap[i] - b[i];
                    a[j] = b[i]+b[j]-cap[i]; a[i] = cap[i];
                }
                res[a[j]] = min(res[a[j]], x);
                res[a[i]] = min(res[a[i]], x);
                encode(x);
                a[i] = b[i], a[j] = b[j];
            }
        }
    }
}
int main() {
    scanf("%d", &t);
    while(t--) {
        vis.clear();
        for(int i=0; i<L; ++i) res[i] = INF;
        for(int i=0; i<3; ++i) scanf("%d", &cap[i]);
        scanf("%d", &D);
        if(D >= cap[2]) {
            printf("%d %d\n", 0, cap[2]); continue;
        }

        bfs();
        while(res[D] == INF) --D;
        printf("%lld %d\n", res[D], D);
    }
    return 0;
}