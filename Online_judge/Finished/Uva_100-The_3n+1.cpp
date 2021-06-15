#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
// in the queue...
int solve(int i, int j)
{
	int Max = 0;
	for(int n=i; n<=j; n++)
	{
		int count = 1;
		int x = n;

		while(x != 1)
		{
			if(x%2 == 0)
				x/=2;
			else
				x = 3*x+1;
				
			count++;
		}

		Max = max(count, Max);
	}
	return Max;
}
int main()
{
	int i, j;
	while(scanf("%d%d", &i, &j) != EOF)
	{
		int max = solve(i, j);
		printf("%d\n", max);
	}
	
	

	return 0;
}