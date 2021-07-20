/*
***Topology***
    Solution:
        Topologically sort the vertices, and then record their distances.
        Find those with largest distance, and go backwards to collect the 
        "key" vertices.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;
int n, m;
vector<int> G[N], rG[N]; //original graph and rev graph
//weight of vertices, in/out-degree, distance
int w[N], in[N], out[N], d[N];

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &w[i]);
    }
    for(int i=0; i<m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        rG[v].push_back(u);
        in[v]++;
        out[u]++;
    }
    queue<int> Q;
    for(int i=1; i<=n; i++) {
        if(in[i] == 0) {
            d[i] = w[i];
            Q.push(i);
        }
    }
    while(!Q.empty()) {
        int v = Q.front(); Q.pop();
        for(int u : G[v]) {
            //"key" tasks are last-finished tasks
            d[u] = max(d[u], d[v]+w[u]);
            if(--in[u] == 0) 
                Q.push(u);
        }
    }
    int res = 0, last;
    for(int i=1; i<=n; i++) {
        //the last is the "key" path
        if(!out[i] && d[i] > res) {
            res = d[i];
            last = i;
        }
    }
    //there may be multiple "key" path
    for(int i=1; i<=n; i++) {
        if(!out[i] && d[i] == res) {
            Q.push(i);
        }
    }
    set<int> key;
    while(!Q.empty()) {
        int v = Q.front(); Q.pop();
        key.insert(v);
        for(int u : rG[v]) {
            //go backwards
            if(d[u]+w[v] == d[v] && !key.count(u)) 
                Q.push(u);
        }
    }
    printf("%d\n", res);
    for(auto i : key) {
        printf("%d ", i);
    }
    return 0;
}