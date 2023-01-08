#include <stdio.h>


int add(int a, int b)
{
	return a+b;
}
void print(int a, int b)
{
	printf("%d\n", a+b);
}
int main(void)
{
	int x=8, y=9;
	print(x, y);
	printf("%d", add(20, 1));
	return 0;
}