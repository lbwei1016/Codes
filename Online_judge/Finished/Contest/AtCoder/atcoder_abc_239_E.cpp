/*
***Tree***
    Description:
        Find the K-th largest value under the V-rooted subtree.
    Solution:
        K is small!!! 
        K is small!!! 
        K is small!!! 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<int> G[N];

void dfs(int at, int p, vector<multiset<int> > &sub) {
    for(auto x: G[at]) {
        if(x == p) continue;
        dfs(x, at, sub);
        // auto it = sub[at].begin();
        for(auto val: sub[x]) {
            sub[at].insert(val);
            if(sub[at].size() > 20)
                sub[at].erase(sub[at].begin()); 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<multiset<int> > subtree(n+1);

    for(int i=1; i<=n; ++i) {
        int x; cin >> x;
        subtree[i].insert(x);
    }
    for(int i=1; i<=n-1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0, subtree);

    while(q--) {
        int v, k;
        cin >> v >> k;
        auto it = subtree[v].rbegin();
        while(k > 1) {
            ++it;
            --k;
        }
        cout << (*it) << '\n';
    }
    
    return 0;
}