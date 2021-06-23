#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int , int> pii;

bool comp(pii a, pii b)
{
	if(a.first == b.first)
	{
		if(a.second%2!=0 && b.second%2!=0)
			return a > b;
		else if(a.second%2==0 && b.second%2!=0)
		{
			if(a.second < b.second)
				return a > b;
		}
		else if(a.second%2!=0 && b.second%2==0)
		{
			if(a.second > b.second)
				return a > b;
		}
	}
		
	return a < b;
}
int main()
{
	vector<pii> v;
	int n, m;

	while(true)
	{
		cin >> n >> m;

		if(!n && !m)
		{
			cout << "0 0";
			break;
		}

		v.resize(n);
		for(int i=0; i<n; ++i)
		{
			cin >> v[i].second; // initial value
			v[i].first = v[i].second%m; // mod
		}

		sort(v.begin(), v.end(), comp);

		cout << n << ' ' << m << '\n';
		for(int i=0; i<n; i++)
			cout << v[i].second << '\n';
	}
	return 0;
}

//這是一個有著許多要求的sort問題
