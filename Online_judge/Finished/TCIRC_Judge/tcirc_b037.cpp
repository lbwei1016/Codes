#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<char, int> m;
	char c;

	while(cin >> c)
		m[c]++;

	for(char a='a'; a<='z'; ++a)
		m[a] += m['A'-'a'+a];
	for(char a='a'; a<='z'; ++a)
	{
		if(m[a] == 0)
			continue;
		cout << '\'' << a << '\'' << ": " << m[a] << '\n';
	}
	return 0;
}