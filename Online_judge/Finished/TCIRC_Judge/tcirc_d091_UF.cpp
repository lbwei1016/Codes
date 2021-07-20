/*
***Union and Find***
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
int root[50005];
int w[50005];

inline int find(int x) {
    if(root[x] < 0) return x;
    else return root[x] = find(root[x]);
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &w[i]);
    }
    for(int i=0; i<n; i++) 
        root[i] = -1;
    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int r1 = find(a);
        int r2 = find(b);
        if(r1 == r2) continue;
        else if(root[r1] < root[r2]) {
            root[r1] += root[r2];
            root[r2] = r1;
            w[r1] += w[r2];
        } else {
            root[r2] += root[r1];
            root[r1] = r2;
            w[r2] += w[r1];
        }
    }
    int res = 0;
    for(int i=0; i<n; i++) {
        res = max(res, w[i]);
    }
    printf("%d\n", res);
    return 0;
}