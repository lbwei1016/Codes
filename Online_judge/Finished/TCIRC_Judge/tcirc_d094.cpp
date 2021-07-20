/*
***Graph*** 
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma message("Hi")
using namespace std;

const int N = 1e6+5;
int n, P, L, R;
int S[N];
int d[N];

void bfs() {
    memset(d, -1, sizeof(d));
    queue<int> Q;
    Q.push(0);
    d[0] = 0;
    while(!Q.empty() && d[P] < 0) {
        int p = Q.front(); Q.pop();
        int l = p-L, r = p+R;
        if(l > 0 && S[l] > 0 && S[l] < n && d[S[l]] < 0) {
            d[S[l]] = d[p] + 1;
            Q.push(S[l]);
        }
        if(r < n && S[r] > 0 && S[r] < n && d[S[r]] < 0) {
            d[S[r]] = d[p] + 1;
            Q.push(S[r]);
        }
    }
    printf("%d\n", d[P]);
}
int main() {
    scanf("%d%d%d%d", &n, &P, &L, &R);
    for(int i=0; i<n; i++) {
        scanf("%d" ,&S[i]);
    }
    bfs();
    return 0;
}