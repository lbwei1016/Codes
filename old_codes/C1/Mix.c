#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *add(char[], char[]);
char *sub(char[], char[]);
char *mul(char[], char[]);
int main(void) 
{
	char *(*operate[4])(char[], char[]);
	char numA[500]={0}, numB[500]={0}, op[2];
	
	scanf("%s%s%s", numA, op, numB);
	operate['+'] = add;
	printf("%s", operate[op[0]](numA, numB));

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
char *mul(char numA[], char numB[])
{
	static char prod[500]={0};
	int i, j, k, count, slA, slB, temp=0, carry;
	
	strrev(numA);
	strrev(numB);
	slA = strlen(numA);
	slB = strlen(numB);

	for(i=0; i<slA; i++)
	{
		for(j=0; j<slB; j++)
		{
			carry = 0;
			temp = (numA[i]-48)*(numB[j]-48);
			prod[i+j] += (temp%10);
			if(prod[i+j] > 9)
			{
				prod[i+j] -= 10;
				carry = 1;
			}
			prod[i+j+1] += (temp/10)+carry;
			// use type "int" to calculate first(a.k.a only number 0~9)
		}
	}
	for(k=0; k<slA+slB; k++)//trasform "int" into real "char"
		prod[k] += 48;
		
	if(prod[k-1] == '0')//remove unnecessary front 0
		prod[k-1] = 0;
	strrev(prod);
	return prod;
}
