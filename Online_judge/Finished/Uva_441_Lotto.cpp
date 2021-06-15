//這題是算組合；zero c074是同一題

#include <bits/stdc++.h>

using namespace std;

int N;
const int k = 6;
vector<int> num;
vector<int> v;

void dfs(int n, int s)
{
	if(n != k)
	{
		for(int i=s+1; i<N-k+n+1; ++i)
		{
			v.push_back(num[i]);
			dfs(n+1, i);
		}
		v.pop_back(); //dfs結束後取出用過的數字
	}
	else
	{
		for(int i=0; i<v.size(); ++i)
		{
			if(i == v.size()-1)
				cout << v[i];
			else 
				cout << v[i] << ' ';
		}
		cout << '\n';
		v.pop_back();
	}
}
int main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);

	for(int r=0; cin >> N; ++r)
	{
		if(!N)
			break;
		if(r)
			cout << '\n';

		for(int i=0; i<N; ++i)
		{
			int temp;
			cin >> temp;
			num.push_back(temp);
		}

		for(int i=0; i<N-k+1; ++i)
		{
			v.push_back(num[i]);
			dfs(1, i);
			//此時 vector "v" 為空
		}

		num.clear(); //換一組數字
	}
	return 0;
}