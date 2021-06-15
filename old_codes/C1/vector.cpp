#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdlib> //rand()
#include <ctime> //time()
using namespace std;

typedef map<int, int> pii;
typedef map<pii, int> ppi;
int main()
{
	srand(time(0));
	vector<int> v(5, 6);
	v.assign(3, 5);
	vector<int>::iterator iter;
	v.push_back(50);
	v.insert(v.begin()+(rand()%6), 777);

	for(iter=v.begin(); iter!=v.end(); iter++)
		cout << *iter << '\n';

	vector<int> v1(v.begin(), v.end());
	sort(v1.begin(), v1.end());
	reverse(v1.begin(), v1.end());

	for(iter=v1.begin(); iter!=v1.end(); iter++)
		cout << *iter << '\n';
}