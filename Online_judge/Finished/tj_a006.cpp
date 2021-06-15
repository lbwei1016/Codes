#include <cstdio>

using namespace std;

int si[6];
int count = 0;

int exp(int x, int n)
{
	int t = 1;
	for(int i=0; i<n; ++i)
		t*=x;
	return t;
}
int function(int x)
{
	long f = 0;
	for(int i=0; i<6; ++i)
	{
		f += si[i]*exp(x, 5-i);
	}
	if(f == 0)
		return 0;
	if(f > 0)
		return 1;
	else
		return -1;
}
void solve()
{
	for(int i=-35; i<35; ++i)
	{
		if(function(i) == 0)
		{
			printf("%d %d\n", i, i);
			count++;
		}
		else if(function(i)*function(i+1) < 0)
		{
			printf("%d %d\n", i, i+1);
			count++;
		}
	}
}
int main()
{
	int ss = 0;
	for(int i=0; i<6; ++i)
	{
		scanf("%d", si+i);
		ss += si[i]*si[i];
	}

	if(ss == 0)
		printf("Too many... = =\"\n");
	else
	{
		solve();
		if(count == 0)
			printf("N0THING! >\\\\\\<\n");
	}

	return 0;
}