/*
***Tree*** -- Lowest Common Ancestor
*/
#include <iostream>
#include <vector>
using namespace std;

const int N = 100;
int n, t; // time
int time_in[N], time_out[N]; // start & end of its dfs
int ancestor[N][log2(N/2)+1]; // ancestor[v][i]: v's "2^i"-th ancestor
vector<int> G[N]; // adjacent list

constexpr int log2(int x) {
    int i = 0;
    while(1<<i <= x) ++i;
    return i-1;
}
void dfs(int v, int par) {
    time_in[v] = ++t;
    ancestor[v][0] = par;
    int logV = log2(n/2) + 1;
    for(int i=1; i<logV; i++) {
        ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];
    }
    for(auto u : G[v]) {
        if(u == par) continue;
        dfs(u, v);
    }
    time_out[v] = ++t;
}
bool is_ancestor(int x, int y) {
    return time_in[x] <= time_in[y] && time_out[x] >= time_out[y];
}
int LCA(int x, int y) {
    if(is_ancestor(x, y)) return x;
    if(is_ancestor(y, x)) return y;

    for(int i=log2(n/2); i>=0; --i) {
        if(!is_ancestor(ancestor[x][i], y)) 
            x = ancestor[x][i];
    }
    return ancestor[x][0];
}
int main() {
    
    return 0;
}