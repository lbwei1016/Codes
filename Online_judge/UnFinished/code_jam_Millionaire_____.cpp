/*
    I Don't even understand how to come up with the solution!
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX_M 15
int M, X; //M: rounds; X: initial money
double P;
double dp[2][(1 << MAX_M) + 1];

double solve()
{
    int n = 1 << M;
    double *prev = dp[0], *next = dp[1];
    memset(prev, 0, sizeof(double) * (n+1));
    prev[n] = 1.0;

    for(int r=0; r<M; r++)
    {
        for(int i=0; i<=n; i++)
        {
            int jub = min(i, n-i);
            double t = 0.0;
            for(int j=0; j<=jub; j++)
            {
                t = max(t, P * prev[i+j] + (1-P) * prev[i-j]);
            }
            next[i] = t;
        }
        swap(prev, next);
    }
    int i = (long long)X * n / 1000000;
    return prev[i];
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int cnt=1; cnt<=n; cnt++)
    {
        scanf("%d%f%d", &M, &P, &X);
        double ans = solve();
        printf("Case #%d: %.6f\n", cnt, ans);
    }
    
    return 0;
}