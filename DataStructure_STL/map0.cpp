#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<char, int> pci;

int main()
{
	map<char, int> m;
	
	for(int i=0; i<26; i++)
		m.insert(pci('A'+i, i));
	//auto it_m_al = lower_bound(m.begin(), m.end(), 'S');
	auto it_m_inn = m.lower_bound('S');

	cout << /* << '\n' << */it_m_inn->second << '\n';

	// for(pci p : m)
	// {
	// 	cout << p.first << ' ' << p.second << '\n';
	// }

	for(auto it=m.begin(); it!=m.end(); ++it)
		cout << it->first << ' ' << it->second << '\n';
	return 0;
}