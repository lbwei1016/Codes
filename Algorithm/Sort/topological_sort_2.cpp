/*
***Topology / Sort***
    Note: 
        誠心建議，使用迴圈版 (queue 版) 不要用這個遞迴版 (2021/7/28)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, es, vis[N], p[N]; // p[]: number of parents；if 0, it is one of the roots 
bool cycle; // whether there is a cycle
vector<int> G[N], tp; // tp: topologically sorted

void dfs(int v) {
    if(vis[v] == 1) {
        cycle = true;
        return;
    }
    if(vis[v] == 2) return;
    vis[v] = 1; // time_in = ++timer
    for(auto u : G[v]) {
        dfs(u);
    }
    vis[v] = 2; // time_out = ++timer
    tp.push_back(v);
    return;
}

int main() {
    memset(vis, 0, sizeof(vis));
    cin >> n >> es;
    for(int i=0; i<es; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        ++p[v];
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i] && p[i]==0) dfs(i);
    }
    if(cycle) cout << "not a DAG\n";
    else {
        reverse(tp.begin(), tp.end());
        for(auto v : tp) cout << v << ' ';
        cout << '\n';
    }
    return 0;
}