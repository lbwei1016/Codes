#include <iostream>

using namespace std;

const int MOD = 1e9+7;
struct Mat
{
	long long mat[2][2] = 
	{
		{1, 1},
		{1, 0}
	};

	friend Mat operator* (const Mat &m1, const Mat &m2);
	friend Mat operator% (Mat m, int mod);
};

Mat operator* (const Mat &m1, const Mat &m2)
{
	Mat res;
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
		{
			res.mat[i][j] = 0;
			for(int k=0; k<2; k++)
				res.mat[i][j] += (m1.mat[i][k] * m2.mat[k][j]) % MOD;
		}
	}
	return res;
}
Mat operator% (Mat m, int mod)
{
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			m.mat[i][j] %= mod;
	return m;
}
Mat expo(Mat m, int n)
{
	Mat res;
	while(n > 0)
	{
		if(n & 1)
			res = res * m % MOD;
		m = m * m % (MOD);
		n >>= 1;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	if(n == 0)
	{
		cout << "0\n";
		return 0;
	}
	Mat temp;
	Mat res = expo(temp, n-2+2);
	cout << res.mat[0][0]-1 << '\n';

	return 0;
}