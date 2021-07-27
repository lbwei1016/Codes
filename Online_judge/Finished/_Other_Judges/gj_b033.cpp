//LCS: Longest Common Subsequence
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100+1;
int length[N][N];
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	s1 = " " + s1; //to make index start from 1
	s2 = " " + s2;
	int s1_l = s1.length(), 
		s2_l = s2.length();

	for(int i=1; i<s1_l; i++)
	{
		for(int j=1; j<s2_l; j++)
		{
			if(s1[i] == s2[j])
				length[i][j] = length[i-1][j-1]+1;
			else
				length[i][j] = max(length[i-1][j], length[i][j-1]);
		}
	}

	cout << length[s1_l-1][s2_l-1] << '\n';
	return 0;
}
