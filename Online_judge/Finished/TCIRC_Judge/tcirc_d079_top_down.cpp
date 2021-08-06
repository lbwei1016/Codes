#include <bits/stdc++.h>
using namespace std;

int n, L;
int p[205];
int memo[205][205];
//[l, r]
int cut(int l, int r) {
    if(memo[l][r] >= 0) return memo[l][r];
    int mn = 1e9;
    for(int k=l+1; k<r; k++) {
        mn = min(mn, cut(l, k)+cut(k, r));
    }
    mn += p[r] - p[l];
    return memo[l][r] = mn;
}
int main() {
    scanf("%d%d", &n, &L);
    for(int i=1; i<=n; i++) {
        scanf("%d", &p[i]);
    }
    memset(memo, -1, sizeof(memo));
    //邊界處理
    p[0] = 0, p[n+1] = L;
    for(int i=0; i<n+1; i++) 
        memo[i][i+1] = 0;
    printf("%d\n", cut(0, n+1));
    return 0;
}