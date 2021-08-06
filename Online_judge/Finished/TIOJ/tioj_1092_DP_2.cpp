/*
***Graph*** -- top-down DP
    Note: 先手其實是實際遊玩的 "後手"
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10005;
int n, E;
char st[20];
// win[n]: 以 n 為起始獲勝的人
bitset<MAX_N> win, vis;

bool dfs(vector<int> G[], int v) {
    if(!vis[v]) {
        bool who = 1; // 1 代表先手 (被動的那方)
        for(auto u : G[v]) {
            // 當下的人是被動的，因此若有任一路徑可使他方獲勝 (return 0)，則對手必走該步並獲勝
            who &= dfs(G, u);
        }
        win[v] = who;
        vis[v] = 1;
    }
    return !win[v];
}
int main() {
    while(scanf("%d%d", &n, &E) == 2) {
        if(n == 0) break;
        vis.reset();
        win.reset();
        vector<int> G[MAX_N];
        for(int i=0; i<E; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        // 1 代表先手；win[1] = true 代表先手獲勝
        // 先假設先手獲勝，再從終點遞推回來，決定在起點時是誰獲勝
        vis[n] = win[n] = 1; 
        scanf("%s", st);
        dfs(G, 1);
        if((win[1] && st[1]=='i') || (!win[1] && st[1]=='o')) 
            puts("Mimi");
        else puts("Moumou");
    }
    return 0;
}