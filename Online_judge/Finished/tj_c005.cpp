#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char c;
	while(scanf("%c", &c) != EOF)
	{ 
		switch(c)
		{
			case 'A':
				putchar('U');
				break;
			case 'T':
				putchar('A');
				break;
			case 'C':
				putchar('G');
				break;
			case 'G':
				putchar('C');
				break;
			case '\n':
				putchar('\n');
				break;
		}
	}
	return 0;
}