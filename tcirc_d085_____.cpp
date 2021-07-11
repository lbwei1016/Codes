#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> p;
int dp[3][8];
int main() {
    scanf("%d%d", &n, &k);
    p.resize(n+5);
    for(int i=1; i<=n; i++) {
        scanf("%d", &p[i]);
    }
    int res = 0;
    for(int i=1; i<=k; i++) {
        int pmin = p[1], at = 1;
        for(int j=2; j<=n; j++) {
            if(p[j-1] <= pmin) {
                pmin = p[j-1];
                at = j-1;
            }
            if(p[j]-pmin+dp[i-1][at-1] > dp[i][j]) {
                dp[i][j] = p[j]-pmin+dp[i-1][at-1];
                pmin = p[j];
                at = j;
            }
            res = max(res, dp[i][j]);
        }
    }
    printf("%d\n", res);
    return 0;
}