/*
***Graph*** -- diameter of tree
    Solution:
        The diameter must be the distance between two leaves with the
        greatest and second-greatest height and the distance is:
        "h[c1] + h[c2] + 2"
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, D, h[N];
vector<int> chl[N];
bool not_root[N];

void dfs(int v) {
    for(int u : chl[v]) {
        dfs(u);
        //calculate first before update to prevent adding the same child twice
        D = max(D, h[u]+1+h[v]);  
        h[v] = max(h[v], h[u]+1);
    }
    return;
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        chl[a].push_back(b);
        not_root[b] = true;
    }
    int root = 0;
    while(not_root[root]) root++;
    dfs(root);
    printf("%d\n", D);
    return 0;
}