#include <iostream>

using namespace std;

int& fun()
{
	static int x = 10;
	return x;
}

int main()
{
	int a = 10;
	int &ref = a;
	int *ptr = &a;

	cout << "a: " << a << '\n';
	cout << "ref: " << ref << '\n';
	cout << "ptr: " << ptr << ' ' << *ptr <<'\n';
	cout << "add of a: " << &a << '\n';
	cout << "add of ref: " << &ref << '\n';// << "real" << &(&ref); ???why wrong???
	cout << "add of ptr: " << &ptr << '\n';

	// fun() = 30;
	// cout << fun();

	// Check reference
	return 0;
}