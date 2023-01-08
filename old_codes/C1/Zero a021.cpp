#include <stdio.h>
#include <string.h>

int main(void) 
{
	char numA[500]={0}, numB[500]={0}, op[2], sum[500];
	int i, j, count;
	for(i=0; i<500; i++)
	{
		sum[i] = '0';
	}
	scanf("%s%s%s", numA, op, numB);
	strrev(numA);
	strrev(numB);
	printf("%s %s\n", numA, numB);
	
	if(strlen(numA) > strlen(numB))
		count = strlen(numA);
	else
		count = strlen(numB);
	printf("%d\n", count);
	for(i=0; i<count; i++)
	{
		sum[i] += numA[i]+numB[i]-48;
		if(sum[i]-48 > 9)
		{
			sum[i]-=10;
			sum[i+1]='1';
		}	
	}
	strrev(sum);
	printf("%s", sum);
	return 0;
}
