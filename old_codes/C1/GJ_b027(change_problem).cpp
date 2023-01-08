#include <iostream>

using namespace std;

#define MAX 100
int main()
{
	int n, dp[MAX];
	int coin[6] = {1, 5, 10, 12, 16, 20};
	cin >> n;

	for(int i=0; i<MAX; i++)
		dp[i] = 0;
	for(int i=1; i<=n; i++)
	{
		 for(int j=1; j<6; j++)
		 {
		 	if(i-coin[j] < 0)
		 	{
		 		dp[i] = dp[i-coin[j-1]] + 1;
		 		break;
		 	}
		 	else
		 		dp[i] = min(dp[i-coin[j]], dp[i-coin[j-1]])+ 1;
		 }
	}
	cout << dp[n] << endl;

	return 0;
}
