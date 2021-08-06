/*
***DP***
    Solution:
        使用另外的陣列(非 dp[][])來記錄累加情形 -- 因為題目限制只能走連續的格子
    
    O(M * N)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_M = 50+5;
const int MAX_N = 10000+5;

int M, N;
ll a[MAX_N]; //紀錄當前的列
ll dp[MAX_M][MAX_N];
ll l[MAX_N], r[MAX_N]; //紀錄某列的從左或從右累加

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=N; j++) {
            cin >> a[j]; 
            if(j == 1) l[j] = dp[i-1][j] + a[j]; //從前一行的第一列走下來
            else l[j] = max(dp[i-1][j], l[j-1]) + a[j]; //從左或上
        }
        for(int j=N; j>=1; j--) {
            if(j == N) r[j] = dp[i-1][j] + a[j]; //從前一行的最後一列走下來
            else r[j] = max(dp[i-1][j], r[j+1]) + a[j]; //從右或上
            dp[i][j] = max(l[j], r[j]);
        }
    }
    ll ans = -1e9;
    for(int j=1; j<=N; j++) {
        ans = max(ans, dp[M][j]);
    }
    cout << ans << '\n';
    
    return 0;
}