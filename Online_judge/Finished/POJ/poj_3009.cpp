/*
***DFS***
*/
#include <cstdio>
#include <algorithm>

#define MAX_W_H 20

using namespace std;

int w, h;
int sx, sy; //start
int G[MAX_W_H+1][MAX_W_H+1]; //graph
int vx[] = {1, 0, -1, 0};
int vy[] = {0, 1, 0, -1};
int min_ans;

//no more than ten moves
void solve(int x, int y, int d)
{
    //pruning first
    if(d > 10) //discard
        return;
    if(d > min_ans)
        return;
    if(G[x][y] == 3)
    {
        min_ans = min(min_ans, d);
        return;
    }
    for(int i=0; i<4; i++)
    {
        int nx = x + vx[i],
            ny = y + vy[i];
        if(0<=nx && nx<h && 0<=ny && ny<w && G[nx][ny] != 1)
        {
            bool go_deeper = true;
            bool resume = false; //resume destroyed block
            while(true)
            {
                if(G[nx][ny] == 3)
                    break;
                nx += vx[i];
                ny += vy[i];

                if(nx<0 || nx>=h || ny<0 || ny>=w)
                {
                    go_deeper = false;
                    break;
                }
                else if(G[nx][ny] == 1)
                {
                    G[nx][ny] = 0;
                    resume = true;
                    nx -= vx[i];
                    ny -= vy[i];
                    break;
                }
            }
            if(go_deeper)
                solve(nx, ny, d+1); //depth+1
            if(resume)
                G[nx+vx[i]][ny+vy[i]] = 1;
        }
    }
}
int main()
{
    while(scanf("%d%d", &w, &h))
    {
        if(!w && !h)
            break;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                scanf("%d", &G[i][j]);
                if(G[i][j] == 2)
                {
                    sx = i; sy = j;
                }    
            }
        }
        min_ans = 10000000;
        solve(sx, sy, 0);
        if(min_ans <= 0 || min_ans > 10)
            printf("-1\n");
        else
            printf("%d\n", min_ans);
    }
    return 0;
}