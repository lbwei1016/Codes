#include <stdio.h>

#define N 100
int dp[N], seq[N];
int main()
{
	int n, i, j, l, m=0;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &seq[i]);

	for(i=0; i<n; i++)
	{
		for(j=0, l=0; j<i; j++)
		{
			if(dp[j]>l && seq[i] > seq[j])
				l = dp[j];
		}
		dp[i] = l+1;
		if(dp[i] > m)
			m = dp[i];
	}
	printf("%d\n", m);

	return 0;
}
