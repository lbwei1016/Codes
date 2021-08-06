/*
***Graph / DP***
    Solution:
        將 @ 分四種情況遞迴；父節點先決定好才遞迴，讓未知只在子節點
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
//cost[u][i]: 當 u 的 parent 是第 i 字母時(0~3)，以 u 為根的子樹的最小差異度
int n, m, root, cost[N][4]; 
vector<int> chl[N];
unordered_map<char, int> mp = {{'A', 0}, {'U', 1}, {'C', 2}, {'G', 3}};
char s[N][85];

int dfs(int k, int v) { 
    int sum = 0, p = mp[s[v][k]];
    for(int u : chl[v]) {
        //record
        if(cost[u][p] >= 0) {
            sum += cost[u][p];
            continue;
        }
        if(s[u][k] == '@') {
            int mn = 1e9;
            for(auto temp : mp) {
                int cnt = 0;
                s[u][k] = temp.first;
                if(s[u][k] != s[v][k]) cnt++;;
                cnt += dfs(k, u);
                mn = min(mn, cnt);
            }
            cost[u][p] = mn;
            s[u][k] = '@'; //回復，供下次遞迴
        } else {
            if(s[u][k] != s[v][k]) cost[u][p] = 1;
            else cost[u][p] = 0;
            cost[u][p] += dfs(k, u);
        }
        sum += cost[u][p]; //累加子節點
    }
    return sum;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        int a, b;
        scanf("%d%d%s", &a, &b, s[i]);
        if(a == b) root = a;  
        else chl[b].push_back(a);
    }
 
    int res = 0;
    for(int k=0; k<m; k++) {
        memset(cost, -1, sizeof(cost)); //記得初始化
        if(s[root][k] == '@') {
            int mn = 1e9;
            for(auto temp : mp) {
                s[root][k] = temp.first;
                mn = min(mn, dfs(k, root));
            }
            res += mn;
        }
        else res += dfs(k, root);
    }
    printf("%d\n", res);
    return 0;
}