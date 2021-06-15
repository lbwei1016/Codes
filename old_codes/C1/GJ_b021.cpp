#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
int main()
{
	int n;
	vector<ppi> v;
	vector<ppi>::iterator iter;
	cin >> n;

	while(n--)
	{
		int id, a, b, c, d, e;
		cin >> id >> a >> b >> c >> d >> e;
		v.push_back(make_pair(make_pair(a+b+c+d+e, c), id));
	}
	sort(v.begin(), v.end(), greater<ppi>());
	for(iter=v.begin(); iter<v.end(); iter++)
	{
		cout << iter->second << '\n';
	}

}