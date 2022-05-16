#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct HI
{
	int a;
	HI *next;
};
HI *list[5];
int main()
{
	HI *hi = new HI;
	for(int i=0; i<5; i++)
	{
		hi->a = i;
		hi->next = list[i];
		list[i] = hi;
	}
	for(int i=0; i<5; i++)
	{
		cout << list[i]->a << '\n';
	}
	
	return 0;
}
