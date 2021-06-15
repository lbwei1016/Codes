#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000;
int S[N+1]; //開始時間
int T[N+1]; //結束時間

pair<int, int> T_S[N];

void Greed(int n) //選擇結束時間最早的工作
{
	for(int i=0; i<n; i++)
	{
		T_S[i].first = T[i]; //因為要以結束時間來排序，所以結束時間放first
		T_S[i].second = S[i];
	}
	sort(T_S, T_S+n); //小到大

	int ans = 0;
	int t = 0; // t是最後選擇的工作的結束時間
	for(int i=0; i<n; i++)
	{
		if(t < T_S[i].second) //重點！！！！
		{
			t = T_S[i].first;
			ans++;
		}
	}

	cout << ans << '\n';
}
int main()
{
	int n;
	cin >> n;

	for(int i=0; i<n; i++)
		cin >> S[i];
	for(int i=0; i<n; i++)
		cin >> T[i];

	Greed(n);

	return 0;
}