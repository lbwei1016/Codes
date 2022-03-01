#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

int randint(int n) //generate integer [0, n)
{
	if((n-1) == RAND_MAX) //here RAND_MAX: 32767
		return rand();
	else
	{
		int length = RAND_MAX/n;
		assert(length > 0);
		length *= n; //length可被n整除

		int ran;
		while((ran=rand()) >= length);
		return ran%n; //the range of ran: 0~(length-1)共length個

	}
}
int main()
{
	int max = 100, min = 7;
	for(int i=0; i<10; i++)
	{
		srand(time(0)+i*i);
		int x = randint(max);
		printf("%d\n", x);
	}
		
	return 0;
}