/*
***DP*** -- bits
    Solution:
        與方法一不同在於: 方法一是從集合 s 中挑出「還沒去過的 i」，
        再從「已經去過的 j」找出最小值；而方法二則是挑出「已經去過
        的 i」，再回推 (從集合去除 i 之後的情況) 求最小值。

        兩者最大的差異在於初始邊界的設定。
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 16+1;
ll dp[N][1<<N], t[N];
int n;

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%lld", &t[i]);
    
    int S = 1 << n;
    ll mn = 1e17;
    for(int i=0; i<n; ++i) for(int s=0; s<S; ++s) dp[i][s] = 1e17;

    dp[0][0] = 1; // 邊界，回推法才適用
    for(int s=1; s<S; ++s) {
        // j -> i
        for(int i=0; i<n; ++i) { 
            if(!(s>>i & 1)) continue;
            for(int j=0; j<n; ++j) {
                if(dp[j][s & ~(1<<i)] == 1e17) continue;
                ll x = dp[j][s & ~(1<<i)] + abs(i-j);
                ll g = ((x-1)/t[i]+1) * t[i];
                dp[i][s] = min(dp[i][s], g);
            }
        }
    }
    for(int i=0; i<n; ++i) mn = min(mn, dp[i][S-1]);
    printf("%lld\n", mn);
    return 0;   
}