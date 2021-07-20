/*
***Graph*** -- Minimum Vertex Cover
    Note: "Minimum Vertex Cover" + "Maximum Independent Set" = V (number of vertices)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+4;
int n;
int p[N], deg[N];
bool chosen[N];
int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d", &p[i]);
        deg[p[i]]++;
    }
    queue<int> que;
    for(int i=0; i<n; i++) {
        if(deg[i] == 0)
            que.push(i);
    }
    int res = 0;
    while(!que.empty()) {
        int v = que.front(); que.pop();
        if(!chosen[v]) {
            chosen[p[v]] = true;
        } else res++;
        if(--deg[p[v]] == 0) 
            que.push(p[v]);
    }
    printf("%d\n", res);
    return 0;
}