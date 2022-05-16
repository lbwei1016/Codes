#include <iostream>
#include <string>
#include <algorithm> // for "copy()"

using namespace std;

int main()
{
	string str1, str2;
	str1 = "Hello";
	cout << str2.capacity() << '\n';
	str2.resize(5); //remember the size

	string::iterator str1_it = str1.begin();

	copy(str1.begin(), str1.begin()+5, str2.begin());
  //copy(source_from, source_to, destination_from);
	
	cout << str2;

	//check "iterator"
	return 0;
}