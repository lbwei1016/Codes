/*
***Tree*** -- Max Weight Independent Set (tcirc_d109)
    Solution:
        若選 v，則 v 的孩子必不選；若不選 v，則 v 的孩子可選可不選。
    O(n)
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

const int N = 6005;
// f1[v]: 選 v；f0[v]: 不選 v
int n, w[N], f1[N], f0[N];
vector<int> chl[N];
bitset<N> not_root;

void dfs(int v, int p) {
    f1[v] = w[v], f0[v] = 0;
    for(int i=0, s=chl[v].size(); i<s; ++i) {
        int u = chl[v][i];
        if(u == p) continue;
        dfs(u, v);
        f1[v] += f0[u];
        f0[v] += max(f1[u], f0[u]);
    }
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", w+i);
    for(int i=1; i<=n; ++i) {
        int v, p;
        scanf("%d%d", &v, &p);
        if(!v) break;
        chl[p].push_back(v);
        not_root[v] = 1;
    }
    int root = 1;
    while(not_root[root]) ++root;
    dfs(root, 0);
    printf("%d\n", max(f1[root], f0[root]));
    return 0;
}