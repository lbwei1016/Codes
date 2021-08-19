/*
***Tree*** -- Minimum Vertex Cover 
    O(n)
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

const int N = 1005;
// two_lamp1[v]: 以 v 為根的子樹所有邊被兩點涵蓋的數量，且 v 有選；tow_lamp0[v]: v 沒選
int t, n, m, two_lamp1[N], two_lamp0[N];
vector<int> G[N], roots;
int f1[N], f0[N]; // f1[v]: 以 v 為根，在 v 有選的情況下，點涵蓋大小；f0[v]: v 沒選
bitset<N> vis; // there may be a forest

void init() {
    for(int i=0; i<N; ++i) G[i].clear();
    roots.clear();
    vis.reset();
}
void dfs(int v, int p) {
    vis[v] = 1;
    f1[v] = 1, f0[v] = 0;
    two_lamp1[v] = two_lamp0[v] = 0;
    // int two = 0;
    for(int i=0, l=G[v].size(); i<l; ++i) {
        int u = G[v][i];
        if(u == p) continue;
        dfs(u, v);
        // 找最小點涵蓋，並且要有最大數量的邊同時被兩點涵蓋
        if(f1[u]<f0[u] || (f1[u]==f0[u] && two_lamp1[u]+1>two_lamp0[u])) {
            f1[v] += f1[u];
            two_lamp1[v] += two_lamp1[u] + 1;
        }
        else {
            f1[v] += f0[u];
            two_lamp1[v] += two_lamp0[u];
        }
        f0[v] += f1[u];
        two_lamp0[v] += two_lamp1[u];
    }
}
int main() {
    scanf("%d", &t);
    while(t--) {
        init();
        scanf("%d%d", &n, &m);
        for(int i=0; i<m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=0; i<n; ++i) {
            if(!vis[i]) {
                roots.push_back(i);
                dfs(i, n);
            }
        }
        int min_lamp = 0, two = 0;
        for(int i=0, l=roots.size(); i<l; ++i) {
            int r = roots[i];
            if(f1[r]<f0[r] || (f1[r]==f0[r] && two_lamp1[r]>two_lamp0[r])) {
                min_lamp += f1[r]; two += two_lamp1[r];
            }
            else {
                min_lamp += f0[r]; two += two_lamp0[r];
            }
        }
        printf("%d %d %d\n", min_lamp, two, m-two);
    }
    return 0;
}
/*
test cases:
3
4 3
0 1
1 2
2 3
5 4
0 1
0 2
0 3
0 4
16 14
0 1
0 2
0 3
1 4
1 5
2 6
4 7
4 8
5 9
9 10
11 12
11 13
11 14
13 15
*/