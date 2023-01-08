#include <iostream>

using namespace std;

void hanoi(int n, int a, int b, int c);
int main()
{
	int n;
	cin >> n;
	hanoi(n, 1, 2, 3);
	return 0;
}
void hanoi(int n, int a, int b, int c)
{
	if(n == 1)
		printf("Ring %d from %d to %d\n", n, a, c);
	else
	{
		hanoi(n-1, a, c, b);
		printf("Ring %d from %d to %d\n", n, a, c);
		hanoi(n-1, b, a, c);
	}

}