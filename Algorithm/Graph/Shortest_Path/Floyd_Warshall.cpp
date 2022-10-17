/*
    Floyd-Warshall's algorithm: (DP)
        Find the shortest path for each vertex to the others.(multiple source)
    Note:
        Floyd-Warshall 可以用來找最小環！
        "求最小環如同求最短路徑；求最大環如同求最長路徑。" -- 演算法筆記

        其他最短路徑演算法無法求最小環的原因在於，他們有 "起點" 的概念，
        也就是說，一開始起點的距離就被設為 0，無法再被更新。而且更重要的是，
        他們都單源。
    O(V^3)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_V 1000
#define INF 1e9

// d[][]: the distance from "u" to "v"
// mid[i][j]: the minimum "k" (between i and j)
int d[MAX_V][MAX_V], mid[MAX_V][MAX_V]; 
vector<int> path;

// init the cost(distance) of e(u, v); if e(u, v) doesn't exist => INF, and d[u][u] = 0;
void init(int V) {
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++) {
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
            mid[i][j] = -1;
        }
}

bool floyd_warshall(int V) {
    for(int k=0; k<V; k++) // whether includes the (k-1)th vertex 
        for(int i=0; i<V; i++) {
            if(d[i][i] < 0) 
                return false; // a negative cycle exists
            for(int j=0; j<V; j++) {
                if(d[i][j] > d[i][k]+d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    mid[i][j] = k;
                }
            }
        }
    return true;   
}
// 不包含起、終點
void find_path(int s, int t) {
    if(mid[s][t] == -1) return;
    find_path(s, mid[s][t]);
    path.push_back(mid[s][t]);
    find_path(mid[s][t], t);
    return;
}

int main() {
    int V, E;
    scanf("%d%d", &V, &E);
    init(V);
    for(int i=0; i<E; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        d[u][v] = d[v][u] = w;
    }
    bool no_neg_cycle = floyd_warshall(V);
    path.push_back(0);
    find_path(0, V-1);
    path.push_back(V-1);
    for(auto v : path) printf("%d ", v);
    printf("\n");
    return 0;
}