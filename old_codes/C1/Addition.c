#include <stdio.h>
#include <string.h>

char *add(char[], char[]);
int main(void) 
{
	char numA[500]={0}, numB[500]={0}, op[2];
	
	scanf("%s%s%s", numA, op, numB);
	printf("%s", add(numA, numB));

	return 0;
}
char *add(char numA[], char numB[])
{
	static char sum[500]={0};
	int i, j, count, slA, slB;
	
	strrev(numA);
	strrev(numB);
	slA = strlen(numA);
	slB = strlen(numB);
	if(slA > slB)
		count = strlen(numA);
	else
		count = strlen(numB);
	for(i=0; i<count; i++)
	{
		if(i-slA>=0)
			numA[i] = '0';
		else if(i-slB>=0)
			numB[i] = '0';
		
		if(sum[i] == '1')
			sum[i] -= 48;
		sum[i] += numA[i]+numB[i]-48;
		if(sum[i]-48 > 9)
		{
			sum[i]-=10;
			sum[i+1] = '1';
		}	
	}
	strrev(sum);
	return sum;
}
