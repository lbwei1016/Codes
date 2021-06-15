#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int first_bench = 0, last_bench = 0;
	int ans = 0;
	vector<int> v;

	cin >> n;
	v.resize(n);

	for(int i=0; i<n; ++i)
		cin >> v[i];

	bool find = false;
	for(int i=0; i<n; ++i)
	{
		if(v[i] == 1 && !find)
		{
			first_bench = i;
			find = true;
		}

		if(v[i] == 9)
		{
			if(i == 0)
			{
				if(v[i+1]!=1 && v[i+1]!=9)
					v[i+1] = -1;
			}
			else if(i == n-1)
			{
				if(v[i-1]!=1 && v[i-1]!=9)
					v[i-1] = -1;
			}
			else
			{
				if(v[i+1]!=1 && v[i+1]!=9)
					v[i+1] = -1;
				if(v[i-1]!=1 && v[i-1]!=9)
					v[i-1] = -1;
			}
		}
	}
	for(int i=n-1; i>0; i--)
	{
		if(v[i] == 1)
		{
			last_bench = i;
			break;
		}
	}
		

	for(int i=first_bench; i<last_bench; ++i)
	{
		if(v[i] == 0)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}
