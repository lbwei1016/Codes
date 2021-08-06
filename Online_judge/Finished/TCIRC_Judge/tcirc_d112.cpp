/*
***Graph*** -- Minimal Dominating Set
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
//ch[]: 是否有小孩被選上 (若有，則自己未被選上也可以)
bool visit[N], ch[N];
//vac[]: 初始值 = deg[]；代表仍未有可抵達的服務中心的小孩數量
int p[N], deg[N], vac[N];
vector<int> G[N];
//轉化為有根樹
void dfs(int v) {
    visit[v] = true;
    for(int u : G[v]) {
        if(!visit[u]) {
            p[u] = v;
            deg[v]++; vac[v]++;
            dfs(u);
        }
    }
    return;
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //以 1 為根
    dfs(1);
    queue<int> que;
    for(int i=2; i<=n; i++) {
        if(deg[i] == 0) 
            que.push(i);
    }
    int res = 0; p[1] = 0;
    while(!que.empty()) {
        int v = que.front(); que.pop();
        //若有小孩仍未有可抵達的服務中心
        if(vac[v]) {
            res++; //自己成為服務中心
            vac[p[v]]--;
            ch[p[v]] = true;
        } else if(ch[v]) vac[p[v]]--; //若有小孩是服務中心
        if(--deg[p[v]] == 0)
            que.push(p[v]);
    }
    if(!vac[1] && !ch[1]) res++;
    printf("%d\n", res);
    return 0;
}