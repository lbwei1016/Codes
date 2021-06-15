#include <stdio.h>
#include <string.h>

char *mul(char[], char[]);
int main(void) 
{
	char numA[500]={0}, numB[500]={0}, op[2];
	
	scanf("%s%s%s", numA, op, numB);
	printf("%s", mul(numA, numB));

	return 0;
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
