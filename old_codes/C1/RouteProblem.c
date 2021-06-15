#include <stdio.h>

#define N 10

int r[N][N];
int route(int, int);

int main(void)
{
	int x, y;
	scanf("%d%d", &x, &y);
	int ans = route(x, y);
	printf("%d", ans);

	return 0;
}

int route(int x, int y)
{
	if(x == 0 || y == 0)
		return 1;
	return r[x][y] = route(x-1, y) + route(x, y-1) + route(x-1, y-1);

	     /*
	     	The number of ways of current position is equal to 
	     	the sum of the numbers of the three previous positions.
	     */
}