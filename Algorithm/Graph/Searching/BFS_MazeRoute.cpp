/*(N = 10, M = 10)
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> P;

const int INF = 100000000;
const int N = 100;
const int M = 100;

char maze[N][M];
int n, m;
int sx, sy; //coordinate of start
int gx, gy; // coordinate of goal

int d[N][M]; //移動至各點的最短距離(因為各點只會被訪問一次，所以最先訪問到的一定是最短距離)

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
//往上下左右四方向移動的向量!!!!!!!!!

int BFS()
{
	queue<P> q;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			d[i][j] = INF; //INF代表還沒走過

	q.push(P(sx, sy));
	d[sx][sy] = 0; // initalize start

	while(!q.empty())
	{
		P p = q.front(); q.pop();

		if(p.first == gx && p.second == gy) // this is optional
			break;

		for(int i=0; i<4; i++)
		{
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]!='#'&& d[nx][ny]==INF)
			{
				d[nx][ny] = d[p.first][p.second] + 1;
				q.push(P(nx, ny));
			}
		}
	}
	return d[gx][gy];
}
int main()
{
	scanf("%d%d", &n, &m);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> maze[i][j];
			if(maze[i][j] == 'S')
			{
				sx = i; 
				sy = j; // x, y座標的指定只要全程式碼一致就好；e.g. x前y後
			}
			else if(maze[i][j] == 'G')
			{
				gx = i; 
				gy = j;
			}
		}
	}

	int res = BFS();
	printf("%d\n", res);

	return 0;
}