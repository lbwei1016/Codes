#include <bits/stdc++.h>

using namespace std;

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int s[6], count = 0;
	for(int i=5; i>=0; i--)
		cin >> s[i];

	for(int i=5; i>=0; i--)
	{
		if(s[i] > 1)
		{
			if(count != 0)
				printf(" + ");

			if(i == 5)
				printf("%dx^2", s[i]);
			else if(i == 4)
				printf("%dxy", s[i]);
			else if(i == 3)
				printf("%dy^2", s[i]);
			else if(i == 2)
				printf("%dx", s[i]);
			else if(i == 1)
				printf("%dy", s[i]);
			else
				printf("%d", s[i]);

			count++;
		}
		else if(s[i] < -1)
		{
			s[i] *= -1;
			if(count != 0)
				printf(" - ");
			else 
				printf("-");

			if(i == 5)
				printf("%dx^2", s[i]);
			else if(i == 4)
				printf("%dxy", s[i]);
			else if(i == 3)
				printf("%dy^2", s[i]);
			else if(i == 2)
				printf("%dx", s[i]);
			else if(i == 1)
				printf("%dy", s[i]);
			else
				printf("%d", s[i]);

			count++;
		}
		else if(s[i] == 1)
		{
			if(count != 0)
				printf(" + ");

			if(i == 5)
				printf("x^2");
			else if(i == 4)
				printf("xy");
			else if(i == 3)
				printf("y^2");
			else if(i == 2)
				printf("x");
			else if(i == 1)
				printf("y");
			else
				printf("1");

			count++;
		}
		else if(s[i] == -1)
		{
			if(count != 0)
				printf(" - ");
			else
				printf("-");

			if(i == 5)
				printf("x^2");
			else if(i == 4)
				printf("xy");
			else if(i == 3)
				printf("y^2");
			else if(i == 2)
				printf("x");
			else if(i == 1)
				printf("y");
			else
				printf("1");

			count++;
		}
	}

	if(count == 0)
		printf("0\n");
	else 
		printf("\n");
	return 0;
}
