/*
***Unknown reason WA***
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAX_M 50000
#define MAX_COOR 305
#define INF 1000000000

using namespace std;

struct Data
{
    int x, y, t;
};

int M;
int last;
int vx[] = {0, 1, 0, -1},
    vy[] = {1, 0, -1, 0};
int G[MAX_COOR+1][MAX_COOR+1]; //value: when to be hit -> 0 means safe；1, 2... isn't
bool visited[MAX_COOR+1][MAX_COOR+1];

int solve()
{
    queue<Data> q; //x, y, moves
    Data d = {0, 0, 0};
    q.push(d);

    while(!q.empty())
    {
        Data d = q.front(); q.pop();

        Data curr = d;
        for(int i=0; i<4; i++)
        {
            curr.x = d.x + vx[i];
            curr.y = d.y + vy[i];
            curr.t++;
            if(0<=curr.x && 0<=curr.y && curr.t<G[curr.x][curr.y] && !visited[curr.x][curr.y])
            {
                visited[curr.x][curr.y] = true;
                if(G[curr.x][curr.y] > last)
                    return curr.t;
                q.push(curr);
            }
        }
    }
    return -1;
}

int main()
{
    // while(scanf("%d", &M))
    // {
        scanf("%d", &M);
        for(int i=0; i<=MAX_COOR; i++)
            for(int j=0; j<=MAX_COOR; j++)
            {
                G[i][j] = INF;
                visited[i][j] = false;
            }
        // memset(G, 0x7f, sizeof(G));
        // memset(visited, 0, sizeof(visited));
        last = 0;
        
        for(int i=0; i<M; i++)
        {
            int x, y, t;
            scanf("%d%d%d", &x, &y, &t);
            
            if(t < G[x][y]) //choose quick-landing meteor
            {
                G[x][y] = t;
                last = max(last, t);
            }   
                
            for(int j=0; j<4; j++)
            {
                int nx = x + vx[j],
                    ny = y + vy[j];
                if(0<=nx && 0<=ny && t<G[nx][ny])
                {
                    G[nx][ny] = t; //choose quick-landing meteor
                    last = max(last, t);
                }  
            }
        }
        if(G[0][0] == 0)
            printf("-1\n");
        else if(G[0][0] == INF)
            printf("0\n");
        else
        {
            int res = solve();
            printf("%d\n", res);
        }
    // }
    return 0;
}