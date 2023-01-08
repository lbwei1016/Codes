#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{

	return a<b;
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	// string s, re[500];
	// int i, indRe = 0, temp = 0;
	// while(!cin.eof())
	// {
	// 	temp = 0;
	// 	getline(cin, s);
	// 	for(i=0; i<=indRe; i++)
	// 	{
	// 		if(s == re[i])
	// 		{
	// 			cout << "YES" << endl;
	// 			break;
	// 		}
	// 		else
	// 			temp++;
	// 	}
	// 	if(temp-1 == indRe)
	// 		cout << "NO" << endl;
	// 	re[indRe] = s;
	// 	indRe++;
	// }
	int a[5] = {5, 1, 2, 4, 3}, b[5] = {1, 2, 3, 4, 5};
	sort(a, a+5, compare);
	for(int i=0; i<5; i++)
		cout << a[i] << '\n';

	int x = 1, y = 9;
	swap(&x, &y);
	cout << x << " " << y << endl;
	
}

