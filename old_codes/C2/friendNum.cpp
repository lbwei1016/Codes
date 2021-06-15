#include <iostream>

using namespace std;

int main()
{
	int a, b, sumA=0, sumB=0;
	cin >> a >> b;

	for(int i=1; i*i<a; i++)
		if(a % i == 0)
			sumA += i+(a/i);
	for(int i=1; i*i<b; i++)
		if(b % i == 0)
			sumB += i+(b/i);
	if(sumA == sumB)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';

	return 0;
}
