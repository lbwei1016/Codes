/*
***DP***
    Solution:
        由頂端逐漸疊上抽屜：以頂端的抽屜為上鎖或非為記錄依據，再判斷狀況
    
    O(n ^ 2)
*/
#include <bits/stdc++.h>

using namespace std;

/*
    dp[i][j][k]:
        i: 抽屜數量
        j: 確保安全的數量
        k: 最頂端是否上鎖 (lock: 1, unlock: 0)
*/
long long dp[67][67][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1][0][0] = 1;
    dp[1][1][1] = 1;

    for(int i=2; i<67; i++) {
        for(int j=0; j<=i; j++) {
            /*
                dp[i-1][j+1][1]:
                    本來頂端安全，再放上一個未鎖的抽屜，而變得不安全
                dp[i-1][j][0]:
                    本來頂端就不安全，再放一未鎖的抽屜不影響
            */
            dp[i][j][0] += dp[i-1][j+1][1] + dp[i-1][j][0];
            if(j > 0) 
            /*
                dp[i-1][j-1][1]:
                    在安全的頂端再放一上鎖的抽屜
                dp[i-1][j-1][0]:
                    在不安全的頂端放一上鎖的抽屜
            */
                dp[i][j][1] += dp[i-1][j-1][1] + dp[i-1][j-1][0];
        }
    }

    int n, s;
    while(cin >> n >> s) {
        if(n < 0) break;
        long long res = dp[n][s][0] + dp[n][s][1];
        cout << res << '\n';
    }
    
    return 0;
}