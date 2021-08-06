/*
***Graph*** -- top-down DP
    Note: 先手其實是實際遊玩的 "後手"
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10005;
int n, E, dp[2][MAX_N]; // dp[who][v]: who 在 v 圓圈時獲勝的人
char st[20];

int dfs(vector<int> G[], int v, int who) {
    if(dp[who][v] >= 0) return dp[who][v];
    if(v == n) return who;
    for(auto u : G[v]) {
        // 當對手可以選擇到讓對手獲勝的路徑
        if(dfs(G, u, who^1) == who^1) {
            dp[who^1][v] = who;
            return dp[who][v] = who^1;
        }
            
    }
    dp[who^1][v] = who^1;
    return dp[who][v] = who;
}
int main() {
    while(scanf("%d%d", &n, &E) == 2) {
        if(n == 0) break;
        vector<int> G[MAX_N];
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<E; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        scanf("%s", st);
        // 先手是 0
        if(!dfs(G, 1, 0)) puts(st);
        else {
            if(strlen(st) == 4) puts("Moumou");
            else puts("Mimi");
        }
    }
    return 0;
}