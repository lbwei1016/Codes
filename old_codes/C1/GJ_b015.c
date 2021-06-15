#include<stdio.h>
#include<string.h>

int main(void)
{
	char s[3][100], *p;
	int n = 0, row = 0, col = 0, i = 0;

	while(n < 3)
	{
		fgets(s[n], 100, stdin);
		n++;
	}
	for(n=0; n<3; n++)
	{
		s[n][strlen(s[n])-1] = 0;//remove '\n'
	}

	for(n=0; n<3; n++)
	{
		for(i=0, p=strtok(s[n], " "); p; i++, p=strtok(0, " "))
		{
			if(strcmp(p, "BILL") == 0)
			{
				row = n+1;
				col = i+1;
				break;
			}
		}
	}
	
	if(row == 0)
		printf("NO");
	else
		printf("%d %d", row, col);

	return 0;
}