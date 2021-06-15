#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef struct 
{
	int data;
	char word;
}ID;
bool comp(ID I1, ID I2) // cannot pass a pointer
{
	return (I1.word < I2.word); // 小在前
}

int main()
{
	vector<ID> v = {{1, 'F'}, {9, 'B'}, {111, 'A'}};
	sort(v.begin(), v.end(), comp);

	for(auto it = v.begin(); it<v.end(); it++)
	{
		cout << it->data << ' ' << it->word << '\n';
	}
	return 0;
}