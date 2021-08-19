/*
***DP*** -- bits
    O(2^n * n^2)
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
    for(int i=0; i<n; ++i) {
        dp[i][1<<i] = ((i+1-1)/t[i]+1) * t[i]; // i+1 是移動時間
    }
    for(int s=1; s<S; ++s) {
        // j -> i
        for(int i=0; i<n; ++i) { 
            if(s>>i & 1) continue;
            for(int j=0; j<n; ++j) {
                if(!(s>>j & 1)) continue;
                // x 是目前為止花費的加上移動至目標的時間
                ll x = dp[j][s] + abs(i-j);
                // g 是最接近 x 的 t[i] 的倍數 (x-1 是為了避免 x 是 t[i] 的倍數的情況)
                ll g = ((x-1)/t[i]+1) * t[i];
                dp[i][s|(1<<i)] = min(dp[i][s|(1<<i)], g);
            }
        }
    }
    for(int i=0; i<n; ++i) mn = min(mn, dp[i][S-1]);
    printf("%lld\n", mn);
    return 0;   
}