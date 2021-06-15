#include <bits/stdc++.h>

using namespace std;

void toCapital(string &st)
{
	for(int i=0; i<st.size(); i++)
		if(st[i]<='Z')
			st[i] += 'a'-'A';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stringstream ss;
	string s[25];
	int n = 0;

	getline(cin, s[0]);
	ss << s[0];
	for(int i=0; s[i-1]!=""; i++, n++)
		ss >> s[i];

	for(int i=0; i<n; i++)
		toCapital(s[i]);
	
	bool flag = true;
	for(int i=0; i<n; i++)
	{
		flag = true;
		for(int j=0; j<n; j++)
		{
			if(s[i][j] != s[j][0])
			{
				flag = false;
				break;
			}
		}
		if(flag)
			break;
	}

	if(flag)
		cout << "o\'_\'o\n" ;
	else
		cout << "QQ\n";

	return 0;
}
