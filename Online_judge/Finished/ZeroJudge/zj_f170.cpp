#include <iostream>
#include <queue>
#include <cmath>
//#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
const int N = 1000;
bool visit[N][N];
int map[N][N]; 
int n, x0, yy; //yy is a substitution for y0
int ans = 0;
int vx[] = {1, 0, -1, 0},
    vy[] = {0, 1, 0, -1};

void bfs()
{
    ans = 0;
   /* for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visit[i][j] = false;*/

    visit[x0][yy] = true;
    ans++;

    queue<ii> q;
    q.push(make_pair(x0, yy));
    while(q.size())
    {
        ii temp = q.front(); q.pop();
        int x = temp.first,
            y = temp.second;

        for(int i=0; i<4; i++)
        {
            int nx = x+vx[i],
                ny = y+vy[i];
            if(!(0<=nx&&nx<n && 0<=ny&&ny<n))
                continue;

            int dh = abs(map[x][y] - map[nx][ny]);
            if(dh < 3 && !visit[nx][ny])
            {
                ans++;
                visit[nx][ny] = true;
                q.push(ii(nx, ny));
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> x0 >> yy;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> map[i][j];
    bfs();
    cout << ans << '\n';
    return 0;
}