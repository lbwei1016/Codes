#include <iostream>

using namespace std;

#define MAX 1000000
int main()
{
	int t;
	cin >> t;

	for(int i=0; i<t; i++)
	{
		int n, bi_eq=0, sm_eq=0;
		cin >> n;
		int min=0, max=MAX; // long long ; change MAX
		bool equal[10000]={0};

		for(int j=0; j<n; j++)
		{
			string buff, note;
			int num; // long long 
			cin >> buff >> note >> num;
			cout << buff << note << '\n';
			if(note[0] == '>')
			{
				if(note[1] == '=')
					equal[j] = true;
				if(num > min) // 找最大的「>」
				{
					min = num;
					bi_eq = equal[j];
				}
			}
			else 
			{
				if(note[1] == '=')
					equal[j] = true;
				if(num < max) 
				{
					max = num;
					sm_eq = equal[j];
				}
			}
		}
		if(min > max)
			printf("0\n");
		else if(min == 0 || max == MAX)
			printf("INF\n");
		else
		{
			int ans = 0;
			if(bi_eq)
				ans++;
			if(sm_eq)
				ans++;
			ans += max-min-1;
			printf("%d\n", ans);
		}
	}

	return 0;
}