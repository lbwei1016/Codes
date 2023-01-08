#include <iostream>
#include <vector>

using namespace std;

int main()
{
	for(int i=0; i<10; ++i)
		cout << i << ", ";

	cout << "\b\b.\n9876543210123456789";
	cout << "\r00000";

	// for(int i=9; i>=0; --i)
	// 	cout << i << ", ";

	
	return 0;
}