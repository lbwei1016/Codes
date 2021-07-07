/*
***Queue***
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
int parent[MAX_N]; 
int h[MAX_N]; //height
int chl[MAX_N]; //number of childrens
int n;
queue<int> Q;

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &chl[i]);
        //leaf
        if(chl[i] == 0) Q.push(i);
        for(int j=0; j<chl[i]; j++) {
            int ch;
            scanf("%d", &ch);
            parent[ch] = i;
        }
    }
    int root, res = 0;
    while(true) {
        int v = Q.front(); Q.pop();
        int p = parent[v];
        res += h[v];
        //we are here root
        if(p == 0) {
            root = v;
            break;
        }
        h[p] = max(h[p], h[v]+1);
        //no unvisited children, now like a leaf
        if(--chl[p] == 0) {
            Q.push(p);
        }
    }
    printf("%d\n%d\n", root, res);
    return 0;
}