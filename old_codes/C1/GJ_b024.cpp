#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long int dp[90];
	dp[0] = 1;
	dp[1] = 2;
	for(int i=2; i<90; i++)
	{
		dp[i] = dp[i-1]+dp[i-2];
	}
	long long int k = dp[n-1]; // start from 0 
	cout << k << " " << dp[(k%n)-1] << endl;

	return 0;
}
