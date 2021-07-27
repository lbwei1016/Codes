/*
***Graph***
    Solution I、II:
        兩次 DFS !!!
    O(V)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 15;
// d[]: 深度；ds[]: 紀錄直徑的編號
int n, d[N], ds[N]; 
// mid[]: 可能的圓心座標 (若直徑為偶數則有兩個)；D: 直徑
int mid[2], D;
vector<int> G[N];
int dfs1(int, int);
int dfs2(int, int);

int main() {
    // 方法一:
    d[0] = -1; // dummy
    scanf("%d", &n);
    for(int i=0; i<n-1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        ++u; ++v; // 為方便起見，從 1 開始編號
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int root2 = dfs1(1, 0);
    dfs1(root2, 0);
    printf("---------------------\n");
    printf("D: %d\nmid0: %d\nmid1: %d\n", D, mid[0], mid[1]);
    printf("d[mid[0]]: %d\nd[mid[1]]: %d\n", d[mid[0]], d[mid[1]]);

    /*--------------------------以下為方法二-------------------------------------*/

    memset(ds, -1, sizeof(ds)); // -1 代表葉
    dfs2(1, 0); // 1 可代換為任意起始點
    int v, rad = 0, mid;
    for(v=1; ds[v]>0; v=ds[v]); // v = 起始點，最終 v = 直徑端點
    D = dfs2(v, 0);
    while(rad + 1 <= D/2) {
        rad++; v = ds[v];
    }
    mid = v; // 圓心即為最後的 v
    printf("D: %d\nrad: %d\nmid: %d\n", D, rad, mid);
    return 0;
}

int dfs1(int v, int p) {
    d[v] = d[p] + 1;
    if(G[v].size()==1 && G[v][0]==p) return v; // leaf

    // id: 子樹中深度最深者，即根所到最遠的節點 (直徑的另一端點)
    // 遞迴至最深處後即可得知直徑長，再回溯定位圓心 (直徑中點)
    int id = 0, temp;
    for(auto u : G[v]) {
        if(u == p) continue;
        temp = dfs1(u, v);
        if(d[temp] > d[id]) id = temp;
    }
    // 更新直徑與圓心
    if(d[id] > D && d[v] == d[id]/2+1) {
        D = d[id];
        if(D & 1) {
            mid[0] = v;
            mid[1] = 0;
        }
        else {
            mid[0] = v;
            mid[1] = p;
        }
    }
    return id;
}
int dfs2(int v, int p) {
    int id = 0, d = 0;
    for(auto u : G[v]) {
        if(u == p) continue;
        d = 1 + dfs2(u, v); 
        // 紀錄最深的子樹
        if(d > id) {
            id = d; 
            ds[v] = u;
        }
    }
    return id;
}
/* test cases:
8
0 1
0 2
0 3
7 0
1 4
1 5
3 6
*/