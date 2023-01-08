#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	vector<int> v = {0, 1, 2, 4};
	//vector<int>::const_iterator cit = v.cbegin();
	//*it = 9; //error

	v.resize(100); //size
	v.reserve(200); //capacity
	v.shrink_to_fit(); //size = capacity
	printf("%d, %d, %d\n", v.size(), v.capacity(), v.max_size());

	int *ptr = v.data();
	if(*ptr == v.at(0))
		cout << "v.data() returns the pointer of the first element" << '\n';
	
	v.push_back(10);
	v.front();
	v.back();
	v.pop_back();
	v.insert(v.begin()+3, 3);
    v.erase(v.end()-1);
	v.emplace_back(4);
	v.emplace(v.begin(), -1);

	vector<int> v2 = {9, 9, 9, 9, 9, 9};
	vector<int>::iterator it;
	v2.swap(v);

	v2.resize(5);
	for(it=v2.begin(); it<v2.end(); it++) //??? problems are up there
		cout << *it << ' ';

 	return 0; 
}