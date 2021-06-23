#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

bool comp(pii a, pii b)
{
	if(a.first == b.first)
		return (a.second > b.second); //遞減(大的在前)
	else
		return (a.first < b.first); //遞增(小的在前)
}
int main()
{
	int n;

	while(cin >> n)
	{
		vector<pii> v;

		for(int i=0; i<n; ++i)
		{
			int temp;
			cin >> temp;
			v.push_back(pii(temp%10, temp));
		}

		sort(v.begin(), v.end(), comp); //comp requires no "()";
										//but greater requires: greater<int>()
		for(int i=0; i<n; ++i)
			cout << v[i].second << ' ';
		cout << '\n';

	}
	return 0;
}