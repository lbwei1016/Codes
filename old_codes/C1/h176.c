#include <stdio.h>
#include <string.h>

unsigned long long pow_ten(int a)
{
    int i;
    unsigned long long sum = 1;
    for(i=0; i<a; i++)
        sum*=10;
    return sum;
}
unsigned long long calc(char *s, int a, int b)
{
    unsigned long long sum = 0, i;
    for(i=a; i<b; i++)
    {
        int dif = s[i]-'0';
        sum += dif*pow_ten(b-i-1);
    }
    return sum;
}

int main()
{
	int n, i, j, k, m;
	scanf("%d", &n);
	char s[n][30];
	for(i=0; i<n; i++)
		scanf("%s", s[i]);

	for(i=0; i<n; i++)
	{
		int len = strlen(s[i]);
		int count = 0, l = 0;
		unsigned long long as[1000], bs[1000], cs[1000];

		for(j=1; j<len-1; j++)
		{
			for(k=j+1; k<len; k++)
			{
				if(s[i][0]=='0' && j>1)
				{
					int br=0;
					for(m=1; m<j; m++)
					{
						if(s[i][m] != '0')
						{
							br = 1;
							break;
						}
					}
					if(br)
						break;
				}
				if(s[i][j]=='0' && k>j+1)
				{
					int br=0;
					for(m=j+1; m<k; m++)
					{
						if(s[i][m] != '0')
						{
							br = 1;
							break;
						}
					}
					if(br)
						break;
				}
				if(s[i][k]=='0')
				{
					int br=0;
					for(m=k+1; m<len; m++)
					{
						if(s[i][m] != '0')
						{
							br = 1;
							break;
						}
					}
					if(br)
						continue;
				}

				unsigned long long a = calc(s[i], 0, j);
				unsigned long long b = calc(s[i], j, k);
				unsigned long long c = calc(s[i], k, len);

				if(a+b == c)
				{
					count++;
					as[l] = a;
					bs[l] = b;
					cs[l] = c;
					l++;
				}
			}
		}
		if(as[0]+bs[0]+cs[0] == 0)
			printf("1\n0 + 0 = 0\n");
		else
		{
			printf("%d\n", count);
			for(m=0; m<l; m++)
				printf("%llu + %llu = %llu\n", as[m], bs[m], cs[m]);
		}
			
	}

	return 0;
}