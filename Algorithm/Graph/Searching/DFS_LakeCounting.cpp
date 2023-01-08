/*
W........WW.
.WWW.....WWW
....WWW..WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
*/

#include <iostream>
#include <cstdio> // scanf, printf較快

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;
int N, M;
char field[MAX_N][MAX_M];

void DFS(int x, int y)
{
	field[x][y] = '.'; //把走過的換成'.'

	for(int dx=-1; dx<=1; dx++)
	{
		for(int dy=-1; dy<=1; dy++)
		{
			int nx = x+dx;
			int ny = y+dy;

			if(0<=nx && nx<N && 0<=ny && ny<M && field[nx][ny]=='W')
				DFS(nx, ny);
		}
	}
	return ; //整個DFS結束一次代表探測過一灘積水
}
int main()
{
	int res = 0;

	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> field[i][j];

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(field[i][j] == 'W')
			{
				DFS(i, j);
				res++;
			}
		}
	}
	cout << res << '\n';

	return 0;
}