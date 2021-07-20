/*
***DP***
*/
#include <bits/stdc++.h>
using namespace std;

int n, L;
int p[205];
int cost[205][205];
int main() {
    scanf("%d%d", &n, &L);
    for(int i=1; i<=n; i++) {
        scanf("%d", &p[i]);
    }
    p[0] = 0, p[n+1] = L;
    for(int i=0; i<n+1; i++) {
        cost[i][i+1] = 0;
    }
    //j - i = len
    for(int len=2; len<n+2; len++) {
        //cost(i, i+len)
        for(int i=0; i+len<n+2; i++) {
            int j = i + len, mn = 1e9;
            for(int k=i+1; k<j; k++) {
                mn = min(mn, cost[i][k] + cost[k][j]);
            }
            cost[i][j] = mn + p[j] - p[i];
        }
    }
    printf("%d\n", cost[0][n+1]);
    return 0;
}