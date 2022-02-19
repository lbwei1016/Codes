/*
***DP***
    Description:
        找出長度為 N、僅由數字 n in [1, M] 組成的序列中，LIS 恰等於 3
        的序列數量。
    Solution:
        首先想起 .../Algorithm/.../LIS_3.cpp，利用此處找出 LIS 的方法逆推:
            對於所有 LIS=3 的序列，其必然可以用一長度為 3 的 DP 陣列 (vector<int> lis)
            來表示該 LIS 的情形。以下的計算方式就是模擬 LIS_3.cpp，一次從尾端加入一數字，
            並更新 LIS 的最有潛力 DP 陣列。
    Note:
        截至 2022/2/19，我對這題依然不太了解，Solution 也只是湊合著寫而已。
        詳見 atcoder abc 237 editorial。
    O(n * m^4)
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1005, M = 12, MOD = 998244353;
int n, m;
ll dp[N][M][M][M];

int main() {
    cin >> n >> m;
    dp[0][m+1][m+1][m+1] = 1;

    for(int len=0; len<n; ++len) for(int a1=1; a1<=m+1; ++a1)
    for(int a2=1; a2<=m+1; ++a2) for(int a3=1; a3<=m+1; ++a3) 
    for(int x=1; x<=m; ++x) {
        if(x <= a1) {
            dp[len+1][x][a2][a3] += dp[len][a1][a2][a3];
            dp[len+1][x][a2][a3] %= MOD;
        }
        else if(x <= a2) {
            dp[len+1][a1][x][a3] += dp[len][a1][a2][a3];
            dp[len+1][a1][x][a3] %= MOD;
        }
        else if(x <= a3) {
            dp[len+1][a1][a2][x] += dp[len][a1][a2][a3];
            dp[len+1][a1][a2][x] %= MOD;
        }
    }
    ll sum = 0;
    for(int a1=1; a1<=m; ++a1) for(int a2=a1+1; a2<=m; ++a2) 
    for(int a3=a2+1; a3<=m; ++a3) {
        sum += dp[n][a1][a2][a3];
        sum %= MOD;
    }
    cout << sum << '\n';
    return 0;
}