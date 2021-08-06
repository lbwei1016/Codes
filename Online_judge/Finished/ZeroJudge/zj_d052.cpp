/*
***DP-LIS(LDS)*************
***Reference to DP_LIS_2***
Problem:
    Given a set of numbers(train cars) coming in a order, and the numbers(cars) can 
    be put either at the front or the buttom of the previous sequence(cars)；to find
    out the Longest Decreasing Sequence(identical to LIS) is the problem.
Solution:
    Since the coming numbers can be put both ways, we can directly make the sequence's
    both way added by the coming number；that is:
        given: [3, 1, 4, 2]
        convert to: [2, 4, 1, 3, 3, 1, 4, 2]
    Then what we need to do is find out the LIS of the converted sequence
*/
#include <bits/stdc++.h>

using namespace std;
#define MAX_N 2000
#define INF 1e9
deque<int> f_b; //store the "front-back"(converted) seq
int dp[2*MAX_N]; //dp[i]: the length of LIS when the length of arr is i+1
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        f_b.resize(2*n);
        fill(dp, dp+(2*n), INF);
        for(int i=0; i<n; i++)
        {
            int temp;
            cin >> temp;
            f_b[n+i] = temp;
            f_b[n-i-1] = temp;
        }
        int ans = 0;
        for(int i=0; i<2*n; i++)
        {
            *(lower_bound(dp, dp+(2*n), f_b[i])) = f_b[i];
        }
        cout << (lower_bound(dp, dp+(2*n), INF) - dp) << '\n';

    }
    return 0;
}