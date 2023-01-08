#include<stdio.h>
#include<string.h>

int main(void)
{
	char A[100], B[100], sum[101]={0};
	int i, count;

	scanf("%s%s", A, B);

	int Alen = strlen(A), Blen = strlen(B);
	count = Alen>Blen ? Alen : Blen;

	for(i=count; i>0; i--, Alen--, Blen--)
	{
		char a, b; 
		a = (Alen-1)<0 ? '0' : A[Alen-1];
		b = (Blen-1)<0 ? '0' : B[Blen-1];

		sum[i] += a+b-'0';
		if(sum[i]>'9')
		{
			sum[i]-=10;
			sum[i-1]++;
		}
	}
	if(sum[0]>0)
	{
		sum[0]+='0';
		printf("%s", sum);
	}
	else
		printf("%s", sum+1);//avoid not able to print due to '\0'

	return 0;
}