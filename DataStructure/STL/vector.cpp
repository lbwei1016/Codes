/* 
functions:
	advance(it, offset): no return
	next(it, offset): return it_1
	prev(it, offset): return it_2
*/
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	vector<int> i = {4, 3, 99, 5, 7};
	vector<int> v = {100, 200, 300};

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

	i.insert(i.begin(), 55);

	for(int &x : i)
		cout << x << ' ';

	vector<int> vv;
	//insert_iterator<vector<int> > iii= inserter(vv, vv.begin());
	//不要理他(上面)

	


	return 0;
}