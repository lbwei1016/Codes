#include <iostream>
#include <string> // getline(cin ,str)
using namespace std;

int main()
{
	string s1, s2;
	char str[10], c;

	cin >> s1 >> s2; 
	// ends when encounter whitespace or '\n', 
	// and extracts all above but without whitespace or '\n'(but do not discard it) 
	cout << s1 << ' ' << s2 << '\n';

	cin.get(str, 10, '\n');
	cin.get(c);
	// only for C-string or char 
	// extracts all [except] delim('\n' if not specified),
	// and leave it('\n') in the buffer
	// note: extract until encounter delim or after (n-1) chars
	cout << str << ' ' << c << '\n';

	cin.getline(str, 10, '\n');
	// only for C-string
	// extracts all [include] delim('\n' if not specified),
	// and [discard] it('\n')
	// note: extract until encounter delim or after (n-1) chars
	cout << str << '\n';

	getline(cin, s1);
	getline(cin, s2);
	// extracts all [include] delim('\n' if not specified),
	// and [discard] it('\n')
	cout << s1 << ' ' << s2 << '\n';

	char a, b, c;
    cin >> a;
    b = getchar();
	//getchar() extracts a char(including '\n')
    cin >> c;
    cout << a << b << c;


	int x; 
	string s;
	cin >> x; 
	cin.ignore(); // ignore endl ('\n')
	getline(cin, s); // works fine!
	return 0;
}