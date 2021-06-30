#include <bits/stdc++.h>

using namespace std;

#define N 100
string s1 = "absfwej",
       s2 = "asbrjeew";
int dp[N][N]; //dp[i][j] represents the LCS when the length of s1 is i, and that of s2 is j
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n1 = s1.length(),
        n2 = s2.length();
    
    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n1][n2] << '\n';
    return 0;
}