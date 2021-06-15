#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	vector<int> v;
	int n, k;
	cin >> n >> k;
	while(n--)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	while(k--)
	{
		int search;
		cin >> search;
		auto it = lower_bound(v.begin(), v.end(), search); //return iter
		
		if(*it == search)
			cout << (it-v.begin() +1) << '\n';
		else
			cout << '0' << '\n';
	}
	return 0;
}

//二分搜尋法(必須)；使用find()效率不足