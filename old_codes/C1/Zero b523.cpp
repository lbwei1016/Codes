#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, re[500];
	int i=0, indRe = 0, temp = 0;
	while(!cin.eof())
	{
		getline(cin, s);
		temp = 0;
		for(i=0; i<=indRe; i++)
		{
			if(s[0] == 0)
				break;
			if(s == re[i])
			{
				cout << "YES" << endl;
				break;
			}
			else
				temp++;
		}
		if(temp-1 == indRe)
			cout << "NO" << endl;
		re[indRe] = s;
		indRe++;
	}
}
