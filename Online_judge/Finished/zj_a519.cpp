#include <bits/stdc++.h>

using namespace std;

#define MAX_N 80
long long dp[MAX_N+1], fib[MAX_N+1];
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    fib[0] = fib[1] = 1;
    for(int i=2; i<=80; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    dp[1] = 1;
    for(int i=2; i<=80; i++)
    {
        dp[i] = fib[i-1] + fib[i-2];
    }
    int g;
    while(cin >> g)
    {
        if(g == 0)
            break;
        cout << dp[g] << '\n';
    }
    return 0;
}