#include <iostream>

using namespace std;

bool arr[5][5];
bool visit[5];
void DFS(int i)
{
	visit[i] = true;

	for(int j=0; j<5; j++)
		if(arr[i][j] && !visit[j])
			DFS(j);
}
void traversal()
{
	for(int i=0; i<5; i++)
		visit[i] = false;

	for(int i=0; i<5; i++)
		if(!visit[i])
			DFS(i);
}
int main()
{
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			cin >> arr[i][j];
		
	traversal();
	return 0;
}