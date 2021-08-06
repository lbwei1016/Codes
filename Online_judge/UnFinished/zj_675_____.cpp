/*
    複雜的DP + Greedy問題
    ans: http://naivered.github.io/2018/03/24/Problem_Solving/UVa/UVa-166-Making-Change/
         https://blog.csdn.net/tengfei461807914/article/details/52235050
*/
#include <bits/stdc++.h>

using namespace std;

#define INF 10000000
const int coin[] = {5, 10, 20, 50, 100, 200};
int num[6];
int dp[6+1][101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true)
    {
        int check = 0;
        for(int i=0; i<6; i++)
        {
            cin >> num[i];
            if(num[i] == 0)
                check++;
        }
        if(check == 6)
            break;
        double p;
        cin >> p;
        int pay = (int)(p*100);

        for(int i=0; i<6; i++)
            for(int j=0; j<101; j++)
                dp[i][j] = INF;
        dp[0][0] = 0;
        for(int i=0; i<6; i++)
        {
            for(int j=0; j<=pay; j++)
            {
                if(j < coin[i])
                    dp[i+1][j] = dp[i][j];
                else
                {
                    dp[i+1][j] = min(dp[i][j], dp[i][j-coin[i]]+1);
                }
            }
        }
    }
    return 0;
}