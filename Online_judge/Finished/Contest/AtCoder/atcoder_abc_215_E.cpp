/*
***DP*** -- bits (*)
    O(2^k * n * k)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
int n;
// dp[i][u][j]: i: 目前選至第 i 項；u: 參加過的競賽種類集合；j: 最近一次參加的競賽種類
ll dp[1005][(1<<10)+1][10];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i=1; i<=n; ++i) {
        int x = s[i-1] - 'A';
        for(int u=0, S=1<<10; u<S; ++u) {
            for(int j=0; j<10; ++j) {
                // 不選第 i 項 ("x")
                // 必須 "+="，因為底下的 "u|(1<<x)" 可能會使 dp[i][u][j] 的值提早不為 0
                dp[i][u][j] = (dp[i][u][j] + dp[i-1][u][j])%MOD; 
                // 第一次選比賽 "x"
                if(!(u>>x & 1)) {
                    dp[i][u|(1<<x)][x] = (dp[i][u|(1<<x)][x] + dp[i-1][u][j])%MOD;
                }
            }
            // 前一次選 "x"，這次繼續選
            // if(u>>x & 1): 這個判斷多餘，因為若 !(u>>x & 1)，則 dp[i-1][u][x] 必為 0，但對於程式碼易讀性有幫助
                dp[i][u][x] = (dp[i][u][x] + dp[i-1][u][x])%MOD;
        }
        // 只有選 "x"
        dp[i][1<<x][x] = (dp[i][1<<x][x]+1)%MOD;
    }
    ll res = 0;
    for(int u=0, S=1<<10; u<S; ++u) {
        for(int j=0; j<10; ++j) {
            res = (res + dp[n][u][j])%MOD;
        }
    }
    printf("%lld\n", res);
    return 0;
}