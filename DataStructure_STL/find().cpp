#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v = {0, 1, 2, 4, 4};
	// int n, k;
	// cin >> n >> k;
	vector<int>::iterator it;
	it = find(v.begin(), v.end(), 9); //return iter of first element that matches val
	cout << (it-v.begin()) << '\n';
	return 0;
}