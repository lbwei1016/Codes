/*
***DP-LCS***
    O(L1 * L2 * L3)
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define N 100
int lcs[N+1][N+1][N+1]; //lcs[i][j][k]代表的是s1長度為i、s2長度為j、s3長度為k的最長子字串長度

int main()
{
    string s1, s2, s3;
    int n1, n2, n3;
    cin >> s1 >> s2 >> s3;
    n1 = s1.size();
    n2 = s2.size();
    n3 = s3.size();

    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            for(int k=1; k<=n3; k++)
            {
                if(s1[i-1]==s2[j-1] && s1[i-1]==s3[k-1])
                    lcs[i][j][k] =  lcs[i-1][j-1][k-1] + 1;
                else  
                    lcs[i][j][k] = max(max(lcs[i-1][j][k], lcs[i][j-1][k]), lcs[i][j][k-1]);
            }
        }
    }
    cout << lcs[n1][n2][n3] << '\n'; 
    return 0;
}