#include <stdio.h>
#include <string.h>

#define N 100
int len[N][N];
int max(int a, int b)
{
	int m;
	m = a>b ? a:b;
	return m;
}
int main()
{
	int i, j;
	char s1[N], s2[N];
	scanf("%s%s", s1, s2);

	int l1 = strlen(s1);
	int l2 = strlen(s2);


	for(i=0; i<l1; i++)
	{
		for(j=0; j<l2; j++)
		{
			if(s1[i] == s2[j])
			{
				if(i-1 >= 0 && j-1 >= 0)
					len[i][j] = len[i-1][j-1]+1;
				else
					len[i][j] = 1;
			}
			else
				len[i][j] = max(len[i-1][j], len[i][j-1]); 
		}
	}
	if(l1 > 0 && l2 > 0)
		printf("%d\n", len[l1-1][l2-1]);
	else
		printf("%d\n", 0);
	return 0;
}