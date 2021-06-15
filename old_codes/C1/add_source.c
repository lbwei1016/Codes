#include <stdio.h>
#include <string.h>

int main(void) 
{
	char numA[500]={0}, numB[500]={0}, op[2], sum[500]={0};
	int i, j, count, slA, slB;

	scanf("%s%s%s", numA, op, numB);
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
		//printf("%c\n", sum[i]);
		if(sum[i]-48 > 9)
		{
			sum[i]-=10;
			sum[i+1] = '1';
		}	
	}
	strrev(sum);
	printf("%s", sum);
	return 0;
}
