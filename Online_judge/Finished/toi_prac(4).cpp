#include <iostream>
#include <queue>

using namespace std;

typedef pair<int ,int> pii;
const int N = 1000, INF = 10000000;
int city[N][N];
bool visited[N][N] = {false};
int vx[4] = {1, 0, -1, 0}, vy[4] = {0, 1, 0, -1};

int abs(int x)
{
	if(x > 0)
		return x;
	else
		return -x;
}
int bfs(int n, int x0, int y0)
{
	int count = 1; //原地也算
	queue<pii> q;
	q.push(pii(x0, y0));
	visited[x0][y0] = true;

	while(!q.empty())
	{
		pii p = q.front(); q.pop();
		int x = p.first,
			y = p.second;

		for(int i=0; i<4; ++i)
		{
			int nx = x + vx[i],
				ny = y + vy[i];

			if(0<=nx && nx<n && 0<=ny && ny<n && !visited[nx][ny])
				if(abs(city[nx][ny]-city[x][y]) <= 2)
				{
					q.push(pii(nx, ny));
					visited[nx][ny] = true;
					++count;
				}
		}
	}
	return count;
}
int main()
{
	int n;
	int x0, y0; //last seen

	cin >> n >> x0 >> y0;

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin >> city[i][j]; //H:i, L:j

	int ans = bfs(n, x0, y0);
	cout << ans << '\n';


	return 0;
}
