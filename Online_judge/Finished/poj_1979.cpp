#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
int W, H;
char G[20+1][20+1];
pii start;
int vx[] = {1, 0, -1, 0},
    vy[] = {0, 1, 0, -1};

int bfs()
{
    int ans = 1;
    queue<pii> q;
    q.push(start);

    while(!q.empty())
    {
        pii p = q.front(); q.pop();
        int x = p.first,
            y = p.second;
        
        for(int i=0; i<4; i++)
        {
            int nx = x + vx[i],
                ny = y + vy[i];
            
            if(0<=nx && nx<H && 0<=ny && ny<W && G[nx][ny] == '.')
            {
                G[nx][ny] = '#';
                q.push(pii(nx, ny));
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    while(scanf("%d%d", &W, &H))
    {
        if(!W && !H)
            break;
        for(int i=0; i<H; i++)
        {
            for(int j=0; j<W; j++)
            {
                scanf("%c", &G[i][j]);
                if(G[i][j] == '\n' || G[i][j] == ' ')
                {
                    j--;
                    continue;
                }
                if(G[i][j] == '@')
                    start.first = i, start.second = j;
            }
        }
        int ans = bfs();
        printf("%d\n", ans);
    }
    return 0;
}