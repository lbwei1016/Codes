/*
***Sort***
*/
#include <iostream>

using namespace std;

int main()
{
	int a[5] = {8, 5, 17, 4, 69};
	for(int i=0; i<5; i++)
	{
		for(int j=i+1; j<5; j++)
		{
			if(a[j] < a[i])
			{
				swap(a[i], a[j]);
			}
		}
	}
	for(int i=0; i<5; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}
