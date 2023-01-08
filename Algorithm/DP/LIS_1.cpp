/*
    O(n^2)
*/
#include <bits/stdc++.h>

using namespace std;

#define N 5
int s[] = {4, 2, 3, 1 ,5};
int dp[N]; //the length of the sequence
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ans = 0;
    for(int i=0; i<N; i++)
    {
        dp[i] = 1; //when the subsequence only contains s[i] itself
        for(int j=0; j<i; j++)
        {
            if(s[j] < s[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}