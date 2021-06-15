#include <iostream>

using namespace std;

int main()
{
	int v[9] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000};
	int n, c = 0;
	cin >> n;
	for(int i=8; i>=0; i--)
	{
		int t = n/v[i];
		n -= t*v[i];
		c += t;
	}
	cout << c << endl;

	return 0;
}