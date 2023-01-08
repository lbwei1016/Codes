#include <iostream>
#include <queue>
using namespace std;

bool arr[5][5];
bool visit[5];

void BFS()
{
	queue<int> q;

	for(int i=0; i<5; i++) 
		visit[i] = false;

	for(int i=0; i<5; i++)
	{
		if(!visit[i])
		{
			q.push(i);
			visit[i] = true;

			while(!q.empty())
			{
				int j = q.front();
				q.pop();

				for(int k=0; k<5; k++)
					if(arr[j][k] && !visit[k])
					{
						q.push(k);
						visit[k] = true;
					}
			}
		}
	}
}
int main()
{
	BFS();
	return 0;
}