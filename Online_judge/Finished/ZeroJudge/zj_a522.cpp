/*
***DP-Subset***
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX_P 20
#define MAX_N 1000
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, p;
    cin >> t;
    while(t--)
    {
        int dp[MAX_N+1] = {}, 
            l[MAX_P+1] = {};
        cin >> n >> p;
        for(int i=0; i<p; i++)
            cin >> l[i];
        dp[0] = 1;
        for(int i=0; i<p; i++)
        {
            for(int j=n; j>=l[i]; j--)
            {
                if(dp[j-l[i]]) //當dp[j-l[i]] = 1，代表長度j-l[i]存在，又l[i]也存在，因此j存在
                    dp[j] = 1;
            }
        }
        if(dp[n])
            cout << "YES\n";
        else 
            cout <<"NO\n";
    }
    return 0;
}