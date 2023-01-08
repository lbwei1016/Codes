#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> i = {4, 3, 99, 5, 7};
	vector<int> v = {100, 200, 300};
	vector<int> v2;
	vector<int> v3(i);

	auto it_b = i.begin();
	vector<int>::iterator it_e = i.end();
	auto it1 = it_b;

	advance(it1, 2); //without returning

	auto it2 = next(it_b, 2); //return an iterator
	auto it3 = prev(it_e, 3); //return an iterator

	if(it1 == it2 && it2 == it3)
	{
		cout << "it1 = it2 = it3" << '\n';
		cout << *it1 << '\n';
	}
	else
		cout << *it1 << ' ' << *it2 << ' ' << *it3 << '\n';

	copy(v.begin(), v.end(), inserter(i, i.begin()+2));
	// inserter(要插入的, 從哪裡)

	v2.assign(i.begin(), i.end());

	i.insert(i.begin(), 55);

	for(int &x : i)
		cout << x << ' ';
	cout << '\n';

	for(int &x : v2)
		cout << x << ' ';
	cout << '\n';

	


	return 0;
}