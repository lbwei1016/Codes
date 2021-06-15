#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull; 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ull n, a, b;
	cin >> n >> a >> b;

	if(a > b)
	{
		if(4*a >= n)
			cout << "!!666\n" << n-(a+b) << '\n';
		else 
			cout << "QQ~~\n" << n-(a+b) << '\n';
	}
	else 
		cout << "QQ~~\n" << n-(a+b) << '\n';
	return 0;
}