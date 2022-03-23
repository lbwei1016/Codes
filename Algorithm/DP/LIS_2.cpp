/*
    O(nlogn)
*/
#include <bits/stdc++.h>

using namespace std;

#define N 5
#define INF 10000000
int s[] = {4, 2, 3, 1 ,5};
//dp[i]: the smallest element of the LIS when the length of LIS is i+1
//if the smallest element is unfound, then dp[i] = INF
int dp[N+1]; 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(dp, dp+N, INF);
    for(int i=0; i<N; i++)
    {
        /*
            find the first element in "dp" that is ">= s[i]"；if that is "INF", 
            it means that LIS increases by 1；if not, the replacement of ele-
            ment can produce the potential for a longer LIS without affecting
            the length of current LIS.

            lower_bound(arr, arr+n, k) returns a pointer points to the element 
            in arr that is ">=" than k
        */
        *lower_bound(dp, dp+N, s[i]) = s[i];
    }
    /*
        to find out the postion in dp where its element is not INF, which means
        that the LIS ends at it(i.e. its length)
    */
    cout << (lower_bound(dp, dp+N, INF)-dp) << '\n';
    return 0;
}