#include <stdio.h>
#include <string.h>

int pow_ten(int a)
{
    int i;
    int sum = 1;
    for(i=0; i<a; i++)
        sum*=10;
    return sum;
}
int calc(char *s, int a, int b)
{
    int sum = 0, i;
    for(i=a; i<b; i++)
    {
        int dif = s[i]-'0';
        sum += dif*pow_ten(b-i-1);
    }
    return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	char s[n][30];
	for(int i=0; i<n; i++)
		scanf("%s", s[i]);

	for(int m=0; m<n; m++)
	{
		int length  = strlen(s[m]);
		int cou = 0, k = 0;
		int as[30], bs[30], cs[30];
		for(int i=1; i<=length/2; i++)
		{
			for(int j=i+1; j<=length*2/3; j++)
			{
				if(s[m][i] == '0' && j!=i+1)
					continue;
				if(s[m][j] == '0')
					continue;
				int a = calc(s[m], 0, i);
				int b = calc(s[m], i, j);
				int c = calc(s[m], j, length);

				if(a+b == c)
				{
					cou++;
					as[k] = a;
					bs[k] = b;
					cs[k] = c;
					k++;
				}

			}
		}
		if(s[m][0]==s[m][1] && s[m][1]==s[m][2] && s[m][2]=='0' && strlen(s[m])==3)
			printf("1\n0 + 0 = 0\n");
		else
		{
			printf("%d\n", cou);
			for(int r=0; r<k; r++)
			printf("%d + %d = %d\n", as[r], bs[r], cs[r]);		
		}
		
	}
	


	return 0;
}