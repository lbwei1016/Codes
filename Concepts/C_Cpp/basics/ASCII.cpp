#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string s1 = "A", s2 = "a"; //A < a; a < b

	if(s1 > s2)
		cout << s1+" > "+s2+'\n';
	else
		cout << s1+" < "+s2+'\n';

	string circ = "circ", ddc = "Ddc";
    if (circ > ddc) // 依照字典順序比較
        cout << "circ is greater than ddc.\n";
    else
        cout << "circ is not greater than ddc.\n";
	return 0;
}