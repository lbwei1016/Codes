/*
***DP***
        After a prisoner is taken out from the cell, the string of cells 
    will be divided into "two independent" string of cells, and further
    divide the cells into smaller portions, which is why we use the 
    concept of "DP".

    O(Q ^ 2)
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX_P 10000
#define INF 10000000

int p; //from 1 to p
int q;
int dp[MAX_P+2][MAX_P+2];
vector<int> prisoner;

//release prisoners in the range from a to b
int solve(int a, int b)
{
    if(dp[a][b] != INF)
        return dp[a][b];
    int res = 0; //coins spent so far

    //this loop goes over to decide which prisoner to start
    for(int i=0; i<q; i++)
    {
        /*
            b - a : coins spent for the release of current prisoner
            solve(a, p[i]-1) : check the left side of the current prisoner
            solve(p[i]+1, b) : check the right side
        */ 

        //inside the scope
        if(a <= prisoner[i] && prisoner[i] <= b)
        {
            int tmp = (b-a) + solve(a, prisoner[i]-1) + solve(prisoner[i]+1, b);
            //update for minimum result
            if(tmp < res || !res)   res = tmp;
        }
    }
    dp[a][b] = res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int cnt=1; cnt<=n; cnt++)
    {
        cin >> p >> q;
        
        prisoner.resize(q);
        for(int i=1; i<=p; i++)
            for(int j=1; j<=p; j++)
                dp[i][j] = INF;

        for(int i=0; i<q; i++)
            cin >> prisoner[i];
        
        int res = solve(1, p);
        cout << "Case #" << cnt << ": " << res << '\n';
    }
    
    return 0;
}