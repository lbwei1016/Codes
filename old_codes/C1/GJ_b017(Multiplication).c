#include<stdio.h>
#include<string.h>

#define MAX_LEN 200

int main(void)
{
	char L[100], W[100], product[MAX_LEN+1]={0};
	int i, j, count;

	scanf("%s%s", L, W);
	int Llen = strlen(L), Wlen = strlen(W);

	/* If two numbers multiply, their product's digit will be
	 * less than the two numbers' digits sum; that is to say : 
	 * product's digit will be no more than (Llen + Wlen) !!!
	 */

	for(i=Llen; i>0; i--)
	{
		for(j=Wlen; j>0; j--)
		{
			int p = (L[i-1]-'0')*(W[j-1]-'0');
			product[i+j] += p;
			if(product[i+j] > 9)
			{
				product[i+j-1] += product[i+j]/10;
				product[i+j] %= 10;
			}
		}
	}
	for(i=0; ; i++)
	{
		if(product[i] != 0)//to skip meaningless '\0'
		{
			count = i;
			break;
		}
	}
	for(; i<=Wlen+Llen; i++)
	{
		product[i] += '0';//restore type "int" to "ASCII" in the end
	}

	printf("%s", product+count);//"count"is to avoid not able to print due to '\0'

	return 0;
}