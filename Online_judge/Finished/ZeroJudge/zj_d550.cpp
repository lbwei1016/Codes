#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int> > v;
	int n, m;
	cin >> n >> m;

	v.resize(n); // this is necessary!!!!!!!!!!!!!!

	for(int i=0; i<n; ++i)
	{
		v[i].resize(m);
		for(int j=0; j<m; ++j)
			cin >> v[i][j];
	}

	sort(v.begin(), v.end());
	
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<m; ++j)
			cout << v[i][j] << ' ';

		cout << '\n';
	}
}

//在sort前必須確保每一要進行排序的元素是「存在的」(像是vector內要有東西)
//用resize() 來掌握大小