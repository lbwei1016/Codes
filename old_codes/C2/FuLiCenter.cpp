#include <iostream>

using namespace std;

int main()
{
	int n;
	int sum = 0;
	cin >> n;

	while(n--)
	{
		int p;
		cin >> p;
		// if(p >= 2000)
		// 	p -= 200;
		sum += p;
	}
	sum -= (sum/1000)*100;
	cout << sum << '\n';

	return 0;
}
