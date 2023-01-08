#include <iostream>
#include <set>

using namespace std;

int main()
{

	set<int, greater<int> > s;
	s.insert(18);
	s.insert(6);
	s.insert(9);
	s.insert(s.begin(), 99);
	set<int>:: iterator it_s;
	for(it_s=s.begin(); it_s!=s.end(); ++it_s)
	{
		cout << *it_s << ' ';
	}

	s.erase(99);
	if(s.find(6) != s.end()) // if not found, s,find() returns s.end()
		cout << "6 found" << '\n';
	if(s.count(99)) // s.count() return 1 or 0
		cout << "99 found" << '\n';
	else 
		cout << "99 not found" << '\n';
	for(const int i : s) //the elements in a "set" is "const"
		cout << i << ' ';
	cout << '\n';

	cout << *s.lower_bound(20) << '\n';

	return 0;
}