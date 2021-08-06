/*
***DP-Coin Change
*/
#include <bits/stdc++.h>

using namespace std;

const int coin[] = {1, 5, 10, 25, 50};
int dp[7490]; //dp[j]: 在金額為j時，所擁有的組合數
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i=0; i<5; i++)
        {
            for(int j=coin[i]; j<=n; j++)
            {
                //如果「金額 j 減去使用某種硬幣 v」後可以被組合出來 ，則該金額一定可以被組合出來。
                dp[j] += dp[j-coin[i]]; 
                //e.g. dp[20] <- dp[20-5] = dp[15]: 15多加一個5即是20
            }
        }
        cout << dp[n] << '\n';
    }
    
    return 0;
}