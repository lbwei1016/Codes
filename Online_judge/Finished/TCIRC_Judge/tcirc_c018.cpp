#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	while(a != 0 && b != 0)
	{
		int temp;
		temp = a;
		b %= a;
		a = b;
		b = temp;
	}
	return (a!=0 ? a : b); 
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	int ans = b/gcd(a, b);
	cout << ans << '\n';

	return 0;
}