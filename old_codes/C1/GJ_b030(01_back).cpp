#include <iostream>
#include <cmath>

using namespace std;

#define M 1000
#define N 100

int dp[M+1];
int main()
{
	int n, m, l[N], s[N];
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> l[i] >> s[i];

	for(int i=0; i<n; i++)
	{
		for(int j=m; j-l[i]>=0; j--)
			dp[j] = max(dp[j], dp[j-l[i]]+s[i]);
		    //01背包問題逆著放；無窮背包順著放!!
	}

	cout << dp[m] << endl;

	return 0;
}
