#include <iostream>

using namespace std;

const int v[6] = {1, 5, 10, 50, 100, 500};
int c[6];
int A;

int Greed()
{
	int res = 0;
	for(int i=5; i>=0; i--)
	{
		int k = min(A/v[i], c[i]); //這是重點!!!!!
		A -= v[i]*k;
		res+=k;
	}
	return res;
}
int main()
{
	for(int i=0; i<6; i++)
		cin >> c[i];
	cin >> A;

	int res = Greed();
	cout << res;
	return 0;
}