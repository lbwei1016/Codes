
//DP就是建表來計算，不要直接拿原始表格來記錄值
//這是最小正方面積問題

#include <iostream>
#include <cmath>

using namespace std;

#define MAX 100

int main()
{
	int h, w, mat[MAX][MAX], dp[MAX][MAX];
	//mat:輸入; dp:紀錄
	int m = 0;
	cin >> h >> w;

	for(int i=0; i<h; i++)
	{
		for(int j=0; j<w; j++)
		{
			cin >> mat[i][j];
		}
	}

	for(int i=0; i<h; i++)
		dp[i][0] = !(mat[i][0]);
	for(int j=0; j<w; j++)
		dp[0][j] = !(mat[0][j]);

	for(int i=1; i<h; i++)
	{
		for(int j=1; j<w; j++)
		{
			dp[i][j] = mat[i][j] == 0 ? 
			min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1 : 0;
			m = max(m, dp[i][j]);
		}
	}

	cout << m*m << endl;
	return 0;
}