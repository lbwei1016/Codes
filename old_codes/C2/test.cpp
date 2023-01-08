#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class T>
bool great(T &a, T &b)
{ 
	return (a>b);
}
int main()
{
	vector<int> v{88, 5, 96, 54, 1000};
	sort(v.begin(), v.end(), greater<int>());
	for(int i : v)
		cout << i << '\n';
	return 0;
}
