#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PP;

const int INF = 1e9;
int L, R, S; //z, x, y

int sx, sy, sz; //start position
int ex, ey, ez; //end position

int vx[] = {1, 0, -1, 0, 0, 0}, 
    vy[] = {0, 1, 0, -1, 0, 0}, 
    vz[] = {0, 0, 0, 0, 1, -1}; //方向向量

int bfs()
{
    char dun[L][R][S]; //map: z, x, y
    int d[L][R][S]; //distance

    queue<PP> q;

    for(int i=0; i<L; ++i)
        for(int j=0; j<R; ++j)
            for(int k=0; k<S; ++k)
            {
                cin >> dun[i][j][k];
                if(dun[i][j][k] == 'S')
                {
                    sz = i;
                    sx = j; 
                    sy = k;
                }
                else if(dun[i][j][k] == 'E')
                {
                    ez = i;
                    ex = j;
                    ey = k;
                }

                d[i][j][k] = INF;
            }
    
    q.push(make_pair(sz, make_pair(sx, sy)));
    d[sz][sx][sy] = 0;

    while(!q.empty())
    {
        PP pp = q.front(); q.pop();

        int z = pp.first,
            x = pp.second.first,
            y = pp.second.second;
        if(z == ez && x == ex && y == ey)
            break;

        for(int i=0; i<6; ++i)
        {
            int nz = z + vz[i], //after moving
                nx = x + vx[i],
                ny = y + vy[i];
                

            if(0<=nz && nz<L && 0<=nx && nx<R && 0<=ny && ny<S && dun[nz][nx][ny]!='#' && d[nz][nx][ny]==INF)
            {
                q.push(make_pair(nz, make_pair(nx, ny)));
                d[nz][nx][ny] = d[z][x][y]+1;
            }
        }
    }
    return d[ez][ex][ey];
}
int main() 
{
    while(cin >> L >> R >> S)
    {
        if(L == 0)
            break;

        int ans = bfs();

        if(ans == INF)
            cout << "Trapped!" << '\n';
        else
            cout << "Escaped in " << ans << " minute(s)." << '\n';
    }
    return 0;
}