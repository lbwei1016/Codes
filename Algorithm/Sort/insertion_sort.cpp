#include <iostream>

using namespace std;

int main()
{
	int a[5] = {8, 5, 17, 4, 69};
	int len = 5;
	for(int i=0; i<len; i++) {
		int key = a[i];
		int j;
		for(j=i-1; j>=0 && a[j]>key; j--) {
			a[j+1] = a[j];
		}
		a[j+1] = key;
	}
	for(auto x : a) cout << x << ' ';
	return 0;
}
