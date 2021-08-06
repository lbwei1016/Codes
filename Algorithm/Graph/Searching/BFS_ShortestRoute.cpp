#include <iostream>
#include <queue>
using namespace std;

bool arr[6][6];
bool visit[6];

int BFS(int from, int to)
{
	queue<int> q;
	int steps[6];

	for(int n=0; n<6; n++)
	{
		visit[n] = false;
		steps[n] = 0;
	}

	if(!visit[from])
	{
		q.push(from);
		visit[from] = true;

		while(!q.empty()) //?????舐?∪????????頝臬??閮?蝞?
		{
			int i = q.front(); 
			q.pop();

			for(int j=0; j<6; j++)
			{
				if(arr[i][j] && !visit[j])
				{
					q.push(j);
					visit[j] = true;
					steps[j] = steps[i]+1;
					if(j == to)
						return steps[j];
				}
			}
		}
	}
	return -1;
}
int main()
{
	int from, to;

	for(int i=0; i<6; i++)
		for(int j=0; j<6; j++)
			cin >> arr[i][j];

	cin >> from >> to;

	cout << BFS(from , to) << endl;
	return 0;
}