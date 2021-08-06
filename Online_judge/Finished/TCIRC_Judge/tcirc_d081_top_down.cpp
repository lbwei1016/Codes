/*
***DP / Bit*** -- top_down
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int w[1 << 20];
int dp[1 << 20];

int f(int des) {
    if(dp[des] >= 0) return dp[des];
    int mx = 0;
    for(int i=0; i<n; i++) {
        //若該位元為一，回推至前一個狀態
        if(des & (1<<i)) {
            mx = max(mx, f(des ^ (1<<i)));
        }
    }
    return dp[des] = mx + w[des];
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<(1<<n); i++) {
        scanf("%d", &w[i]);
    }
    for(int i=0; i<(1<<n); i++)
        dp[i] = -1;
    //起始點
    dp[0] = w[0];
    printf("%d\n", f((1<<n)-1));
    return 0;
}