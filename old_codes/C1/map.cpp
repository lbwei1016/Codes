#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef map<int, int> pii;
int main()
{
	pii myMap;
	pii::iterator iter;
	pair<int, int> p;
	myMap[1] = 10;
	myMap[2] = 5;
	myMap[0] = 0;
	for(int i=0; i<10; i++)
	{
		iter = myMap.find(i);
		if(iter != myMap.end())
			cout << iter->second << '\n';
		else
			break;
	}
	
}