#include <stdio.h>
#include <string.h>

char *sub(char[], char[]);
int main(void) 
{
	char numA[500]={0}, numB[500]={0}, op[2];
	scanf("%s%s%s", numA, op, numB);
	printf("%s", sub(numA, numB));

	return 0;
}
char *sub(char numA[], char numB[])
{
	static char diff[500]={0};
	char *temp = NULL;
	int i, j, count, slA, slB, neg = 0;
	
	strrev(numA);
	strrev(numB);
	slA = strlen(numA);
	slB = strlen(numB);
	if(slA >= slB)
	{
		count = strlen(numA);
	}	
	else
	{
		count = strlen(numB);
		temp = numA;
		numA = numB;
		numB = temp;
		neg = 1;
	}
	for(i=0; i<count; i++)
	{
		if(i-slB >= 0)
			numB[i] = '0';

		diff[i] = numA[i]-numB[i]+48;
		//printf("%c\n", sum[i]);
		if(diff[i] < 48)
		{
			diff[i]+=10;
			numA[i+1]-=1;
		}
	}
	if(diff[i-1] == '0')
	{
		if(neg)
			diff[i-1] = '-';
		else
			diff[i-1] = 0;
	}
	else if(neg)
		diff[i] = '-';
	
	strrev(diff);
	return diff;
}
