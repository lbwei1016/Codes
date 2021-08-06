/*
***Graph / double*** -- Shortest path
    Solution:
        原題目為相乘，取 log 即可轉為相加 !!! 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
struct E { int to; double c; };
struct P {
    double dis; int id;
    bool operator < (const P &p2) const {
        return dis > p2.dis; // 這樣就會由小到大
    }
};
int n, m, s, t;
double d[N];
vector<E> G[N];
bitset<N> vis;

double dj() {
    vis.reset();
    fill(d, d+N, 1e5);
    priority_queue<P> pq; // operator <
    pq.push({0.0, s});
    d[s] = 0.0;
    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int v = p.id;
        if(v == t) return d[t];
        if(vis[v]) continue;
        vis[v] = 1;
        for(auto e : G[v]) {
            int u = e.to; double c = e.c;
            if(d[u] > d[v] + c) {
                d[u] = d[v] + c;
                pq.push({d[u], u});
            }
        }
    }
    return d[t];
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i=0; i<m; ++i) {
        int fr, to; double c; // 小心 c 為 double
        scanf("%d%d%lf", &fr, &to, &c);
        // 在輸入階段就先把 log 準備好，因為大家都是 +1
        G[fr].push_back({to, log10(c+1.0)});
    }
    double ans = dj(); // log10
    // 精確度 !!!
    int dig = int(floor(ans+1e-7)+1e-7); // <cmath>
    ans -= dig;
    // format specifier !!!
    printf("%.2fe+%03d\n", pow(10, ans), dig);
    return 0;
}