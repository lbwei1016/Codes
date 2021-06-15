#include <bits/stdc++.h>

using namespace std;

#define MAX_ 1001
typedef pair<int, int> pii;

char maze[MAX_][MAX_];
queue<pii> F;
int vx[] = {1, 0, -1, 0},
    vy[] = {0, 1, 0, -1};
int L, W, xx, yy;

int bfs()
{
    queue<pii> J;
    J.push(make_pair(xx, yy));

    int cnt = 0;
    while(J.size())
    {
        // BFS fire
        int num1 = F.size();
        for(int i=0; i<num1; i++)
        {
            pii f = F.front(); F.pop();
            int fire_x = f.first,
                fire_y = f.second;
            for(int j=0; j<4; j++)
            {
                int fire_nx = fire_x + vx[j],
                    fire_ny = fire_y + vy[j];
                
                if(0<=fire_nx&&fire_nx<L && 0<=fire_ny&&fire_ny<W)
                {
                    char nf = maze[fire_nx][fire_ny];
                    if(nf!='#' && nf!='F')
                    {
                        maze[fire_nx][fire_ny] = 'F';
                        F.push(make_pair(fire_nx, fire_ny));
                    }
                }
            }
        }

        //BFS Joe
        int num2 = J.size();
        bool flag = false;
        for(int k=0; k<num2; k++)
        {
            pii j = J.front(); J.pop();
            int x = j.first,
                y = j.second;

            
            for(int i=0; i<4; i++)
            {
                int nx = x + vx[i],
                    ny = y + vy[i];
                if(nx<0 || nx>=L || ny<0 || ny>=W)
                {
                    cnt++;
                    return cnt;
                }
                    
                char go = maze[nx][ny];
                if(go == '.')
                {
                    flag = true;
                    J.push(make_pair(nx, ny));
                }
            } 
        }
        if(flag)
            cnt++;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    int n;
    cin >> n;

    while(n--)
    {
        while(F.size())
            F.pop();
        cin >> W >> L;
        for(int i=0; i<L; i++)
        {
            for(int j=0; j<W; j++)
            {
                cin >> maze[i][j];
                if(maze[i][j] == 'J')
                {
                    xx = i;
                    yy = j;
                }
                if(maze[i][j] == 'F')
                    F.push(make_pair(i, j));
            }
        }

        int ans = bfs();
        if(ans == -1)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}