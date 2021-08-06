/*
***DFS*** (*)航線規劃問題
    Solution:
        重點: gcd(x, x+1) = 1。因此，DFS 遍歷的順序一定可以構成題目要求: 編號的最大公因數是 1
*/
#include <bits/stdc++.h>
#include "lib1481.h"
using namespace std;

const int N = 20005;
struct P { int to, id; };
int n, k, ans[N], cnt;
vector<P> G[N];
vector<bool> visit(N);

// 以邊為主體
void dfs(int v) {
    for(auto e : G[v]) {
        int u = e.to, id = e.id;
        if(visit[id]) continue;
        visit[id] = true;
        ans[id] = ++cnt;
        dfs(u);
    }
}
int main() {
    Init(); // interactive 必先 Init()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<=k; ++i) {
        int from, to;
        cin >> from >> to;
        G[from].push_back({to, i});
        G[to].push_back({from, i});
    }
    dfs(1);
    Possible();
    for(int i=1; i<=k; ++i) Number(ans[i]);
    Finish();
    return 0;
}