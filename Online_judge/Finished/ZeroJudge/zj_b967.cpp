/*
***DFS***

    Description:
        Find the farthest distance between nodes on a tree.
    
    Solution:
        First, DFS from any given node, traverse to the deepest node, and 
        make that node a new root.
        Second, DFS from the new root to find out the deepest node from it,
        and the depth is exactly the farthest distance.

    O(N)
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000+5;

int N, ans, root2;
vector<int> T[MAX_N];
bool used[MAX_N];

void dfs(int v, int d) {
    for(int i=0; i<T[v].size(); i++) {
        int u = T[v][i];
        if(!used[u]) {
            used[u] = true;
            dfs(u, d+1);
        }
    }
    if(d > ans) {
        root2 = v;
        ans = d;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> N) {
        ans = root2 = 0;
        memset(used, 0, sizeof(used));
        for(int i=0; i<N; i++) {
            T[i].clear();
        }
        for(int i=0; i<N-1; i++) {
            int a, b;
            cin >> a >> b;
            T[a].push_back(b);
            T[b].push_back(a);
        }
        used[0] = true;
        dfs(0, 0);
        memset(used, 0, sizeof(used));
        used[root2] = true;
        dfs(root2, 0);
        cout << ans << '\n';
    }

    return 0;
}