/*
***DP-01 Backpack***
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10000
#define V 100
int v[MAX_N+1], c[MAX_N+1];
int dp[V+1];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin >> n)
	{
		fill(v, v+n+1, 0);
		fill(c, c+n+1, 0);
		fill(dp, dp+V+1, 0);
		for(int i=0; i<n; i++)
		{
			cin >> v[i] >> c[i];
		}
		for(int i=0; i<n; i++)
		{
			for(int j=V; j>=v[i]; j--)
			{
				dp[j] = max(dp[j], dp[j-v[i]]+c[i]);
			}
		}
		cout << dp[V] << '\n';
	}
	
	return 0;
}
