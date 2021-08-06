//看UVA原文!!!!!
//unidentified error
#include <iostream>
#include <cmath>

using namespace std;

#define N 21
char Map[N][N]; //Map[y][x]
bool visit[N][N];
int dx[] = {-1, 0, 1, 0}, 
    dy[] = {0, -1, 0, 1};
int m, n;
int sum = 0;
char land;

void dfs(int y, int x)
{   
    //Map[y][x] = 'w';
    visit[y][x] = true;
    sum++;
    for(int i=0; i<4; i++)
    {
        int nx = x+dx[i],
            ny = y+dy[i];
        if(nx >= m)
            nx = 0;
        if(nx < 0)
            nx = m-1;

        if(0<=ny&&ny<n &&Map[ny][nx] == land &&(!visit[ny][nx]))
        {
            dfs(ny, nx);
        }
    }                                     
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    int x0, y0, ans = 0;
    //char temp;
    while(cin >> m >> n) //m:x, n:y  x0 x1 x2 ...
    {
        ans = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                visit[n][m] = false;

        /*for(int i=0; i<n; i++) //y
            for(int j=0; j<m; j++) //x
                cin >> Map[i][j];*/
        string s;
        for(int i=0; i<n; i++)
        {
            cin >> s;
            for(int j=0; j<m; j++)
            {
                Map[i][j] = s[j];
            }
        }
        cin >> x0 >> y0;

        land = Map[y0][x0];
        dfs(y0, x0); //clear the land he is standing on

        for(int i=0; i<n; i++) //y
        {
            for(int j=0; j<m; j++) //x
            {
                if(Map[i][j] == land &&(!visit[i][j]))
                {
                    sum = 0;
                    dfs(i, j);
                    if(sum > ans)
                        ans = sum;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}