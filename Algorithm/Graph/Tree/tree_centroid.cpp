/*
***Tree*** -- centroid
    Description:
        重心的定義是:
            以這個點為根，那麼所有的子樹 (不算整個樹自身) 的大小都不超過整個
            樹大小的一半；重心就是使最大的子樹最小的點
    Solution:
        DFS 一次，紀錄子數的節點數，然後更新
    Note: centroid 相當於樹的 median
    O(n)
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10;
int subsize[N]; // subsize[v]: v 的子樹的總節點數 (含 v)
vector<int> G[N];
int centroid, balance_size; // 重心；去除重心後的最大子樹節點數

void init() {
   memset(subsize, 0, sizeof(subsize));
   balance_size = 1e9;
}
void dfs(int v, int p, int n) {
    subsize[v] = 1;
    int max_sub = 0;
    for(auto u : G[v]) {
        if(u == p) continue;
        dfs(u, v, n);
        subsize[v] += subsize[u];
        max_sub = max(max_sub, subsize[u]);
    }
    max_sub = max(max_sub, n-subsize[v]);
    // 更新重心、子樹數量 (找最小字典序)
    if(max_sub<balance_size || (max_sub==balance_size && v<centroid)) {
        centroid = v; 
        balance_size = max_sub;
    }
}
int main() {
    init();
    int n;
    cin >> n;
    for(int i=0; i<n-1; ++i) {
        int p, v;
        cin >> p >> v;
        G[p].push_back(v);   
    }
    dfs(0, -1, n);
    cout << "centroid: " << centroid << '\n';
    cout << "balance size: " << balance_size << '\n';
    for(int i=0; i<n; ++i) printf("%d: %d\n", i, subsize[i]);
    return 0;
}