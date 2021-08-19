/*
***Graph*** -- median of tree
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
int p[N], w[N], deg[N], des[N]; //descendant
int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d%d", &p[i], &w[i]);
        deg[p[i]]++; //out-degree: number of children
    }

    queue<int> que;
    for(int i=1; i<n; i++) {
        if(deg[i] == 0) 
            que.push(i);
    }
    int median = -1; 
    long long len = 0; //total length of path
    p[0] = -1;
    //traverse from leaves
    while(!que.empty()) {
        int v = que.front(); que.pop();
        des[v]++;
        if(median < 0 && des[v] >= n/2) 
            median = v; //the first one 
        len += min(des[v], n-des[v]) * w[v]; //how many times this edge is used
        if(p[v] < 0) break; //root
        des[p[v]] += des[v];
        if(--deg[p[v]] == 0)
            que.push(p[v]);
    }
    printf("%d\n%lld\n", median, len);
    return 0;
}