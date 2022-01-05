#include <iostream>

using namespace std;

int& fun()
{
	static int x = 10;
	return x;
}
// int (*a)[2]: 長度為2的陣列的指標；int *a[2]: 長度為2的指標陣列(兩個指標)
void power(long long (*res)[2], long long (*m)[2], int n) {
    while(n > 0) {
        // if(n & 1) mul(res, m);
        // mul(m, m);
        n >>= 1;
    }
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