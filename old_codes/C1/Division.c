#include <stdio.h>
#include <string.h>

char *div(char[], char[]);//Unsolved
char *sub(char[], char[]);
char *add(char[], char[]);
int main(void)
{
	char numA[500]={0}, numB[500]={0}, op[2];
	scanf("%s%s%s", numA, op, numB);
	printf("%s", div(numA, numB));
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
		//printf("%c\n", sum[i]);
		if(sum[i]-48 > 9)
		{
			sum[i]-=10;
			sum[i+1] = '1';
		}	
	}
	strrev(sum);
	return sum;
}

char *sub(char numA[], char numB[])
{
	static char diff[500]={0};
	char *temp = NULL;
	/*
		Have to use pointer to point to numA's or numB's value, 
		since their value are passed in by pointer(char *)as well
	*/
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
		slB = slA;
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
	for(i=count-1; i>=0; i--)
	{
		if(diff[i] == '0')
			diff[i] = 0;
		else
			break;
	}
	if(neg)
		diff[i+1] = '-';
	strrev(diff);
	return diff;
}

char *div(char numA[], char numB[])
{
	static char *result = {"0"};
	char *div = {""}, count[2] = {'1'};
	char *ptr = NULL, *temp = NULL;
	int slA, slB, slD;
	div = numA;
	slA = strlen(numA);
	slB = strlen(numB);
	slD = strlen(div);
	ptr = numB;
	while((slB < slD) || (slB == slD && numB[0] < div[0]))//8/15 problems
	{
		div = sub(numA, numB);
		temp = add(result, count);
		//div = ptr;
		result = temp;
		slD = strlen(div);
		numA = div;
		numB = ptr;
	}
	return result;
}
