#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int array[26];
void solve()
{
	for(char c='A'; c<='Z'; c++)
	{
			int c1, c2, m = c-'A';
			if(c <= 'H')
			{
				c1 = (m+10)/10 * 1;
				c2 = (m+10)%10 * 9;
				array[m] = c1+c2;
			}
			else if(c == 'I')
				array[m] = 1*3 + 9*4;
			else if(c <= 'N')
			{
				c1 = (m+9)/10 * 1;
				c2 = (m+9)%10 * 9;
				array[m] = c1+c2;
			}
			else if(c == 'O')
				array[m] = 1*3 + 9*5;
			else if(c <= 'V')
			{
				c1 = (m+8)/10 * 1;
				c2 = (m+8)%10 * 9;
				array[m] = c1+c2;
			}
			else if(c == 'W')
				array[m] = 1*3 + 9*2;
			else if(c == 'X')
				array[m] = 1*3 + 9*0;
			else if(c == 'Y')
				array[m] = 1*3 + 9*1;
			else if(c == 'Z')
				array[m] = 1*3 + 9*3;
	}
}
int main()
{
	solve();
	string s;
	while(cin >> s)
	{
		int res = 0;
		for(int i=8, j=0; i>=1; i--, j++)
		{
			res += i*(s[j]-'0');
		}

		int check = s[s.size()-1]-'0';
		for(int i=0; i<26; i++)
		{
		    int cmp = (10-((res+array[i])%10))%10; //當cmp=10，要再取一次餘數
			if(cmp == check)
				putchar(i+'A');
		}
		cout << '\n';

	}
	return 0;
}
