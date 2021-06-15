#include <iostream>

using namespace std;

#define N 1000
int s[N+1];
int main()
{
	int c[5] = {2, 5, 10, 20, 25};
	s[0] = 1;

	for(int i=0; i<5; i++)
	{
		for(int j=c[i]; j<N+1; j++)
		{
			s[j] += s[j-c[i]];
		}
	}

	int n;
	cin >> n;
	cout << s[n] << endl;
}