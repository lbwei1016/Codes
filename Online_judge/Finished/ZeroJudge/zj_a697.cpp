/*
***DP*** 
    Description:
        有 m 個花盆 n 種花，第 i 種花有其最大數量 a[i]，求一直線、將同種花擺放在一起的方法數
    Solution:
        漸進式:
            dp[i][j] = dp[i-k][j-1] (for k from 0 to a[i]) => 加入 0 ~ a[j] 盆第 j 種花

    O(m * n * a)

    P.S. 這是第一個完全自己想出來的 DP !!!
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100+5;
const int MOD = 1000007;
int n, m;
int a[MAX]; 
int dp[MAX][MAX]; //dp[i][j]: 有 i 個花盆 j 種花時的擺放方法數

void solve() {
    for(int i=1; i<=a[1]; i++) dp[i][1] = 1; //全部都擺第一種花時
    for(int j=1; j<=n; j++) dp[0][j] = 1; //全部都擺第 j 種花時

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            //讓出 k 個位子來讓第 i 種花擺放
            for(int k=0; i-k>=0 && k<=a[j]; k++) {
                dp[i][j] = (dp[i][j] + dp[i-k][j-1]) % MOD;
            }
        }
    }
    cout << dp[m][n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    solve();
    
    return 0;
}