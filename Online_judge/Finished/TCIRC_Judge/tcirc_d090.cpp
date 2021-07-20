/*
***Graph*** 
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> G[105];

void bfs(int s) {
    bool visit[105] = {false};
    int d[105] = {0};
    int cnt_v = 0, dis_sum = 0;
    queue<int> Q;
    visit[s] = true; d[s] = 0;
    Q.push(s);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(int v : G[u]) {
            if(!visit[v]) {
                visit[v] = true;
                d[v] = d[u] + 1;
                dis_sum += d[v];
                cnt_v++;
                Q.push(v);
            }
        }
    }
    printf("%d\n%d\n", cnt_v, dis_sum);
}
int main() {
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for(int i=0; i<m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
    bfs(s);
    return 0;
}