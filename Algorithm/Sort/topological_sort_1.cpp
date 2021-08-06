/*
***Topology / Sort***
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> G[n]; //adjacent list
    int indegree[n] = {0}; //入分支度
    for(int i=0; i<m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        indegree[v]++;
    }
    int topo[N], head = 0, tail = 0; //queue
    for(int i=0; i<n; i++) {
        //沒有人在自己前面了
        if(indegree[i] == 0) {
            topo[tail++] = i; //push
        }
    }
    //有人的 indegree 是 0 
    while(head < tail) {
        int u = topo[head++]; //pop
        for(int v : G[u]) {
            if(--indegree[v] == 0) {
                topo[tail++] = v; // push
            }
        }
    }

    //有環，所以並無法全部的點皆達到 indgree = 0
    if(tail < n) 
        printf("Not a DAG"); 
    else {
        for(int i=0; i<n; i++) {
            printf("%d%c", topo[i], i==n-1 ? '\n' : ' ');
        }
    }   
    return 0;
}