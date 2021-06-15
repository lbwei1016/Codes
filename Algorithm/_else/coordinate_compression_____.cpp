//¡u°ö¾i¡v p.169
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX_N = 500;
int W, H, n;
int X1[MAX_N+5], X2[MAX_N+5], Y1[MAX_N+5], Y2[MAX_N+5];
int fld[MAX_N*6][MAX_N*6]; //not sure why MAX_N*6

int dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1};

int compress(int *x1, int *x2, int w)
{
    vector<int> xs;

    for(int i=0; i<n; i++)
    {
        for(int d=-1; d<=1; d++)
        {
            int nx1 = x1[i] + d,
                nx2 = x2[i] + d;
            if(1<=nx1 && nx1<=w) xs.push_back(nx1);
            if(1<=nx2 && nx2<=w) xs.push_back(nx2);
        }
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for(int i=0; i<n; i++)
    {
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }
    return xs.size();
}

void solve()
{
    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);

    memset(fld, 0, sizeof(fld));
    for(int i=0; i<n; i++)
    {
        for(int y=Y1[i]; y<=Y2[i]; y++)
        {
            for(int x=X1[i]; x<=X2[i]; x++)
                fld[y][x] = true;
        }
    }

    int ans = 0;
    for(int y=0; y<H; y++)
    {
        for(int x=0; x<W; x++)
        {
            if(fld[y][x]) 
                continue;
            ans++;

            queue<pair<int, int> > que;
            que.push(make_pair(x, y));
            while(!que.empty())
            {
                int sx = que.front().first, sy = que.front().second;
                que.pop();
                for(int i=0; i<4; i++)
                {
                    int nx = sx + dx[i], ny = sy + dy[i];
                    if(nx<0 || nx>=W || ny<0 || ny>=H)
                        continue;
                    if(fld[nx][ny])
                        continue;
                    que.push(make_pair(nx, ny));
                    fld[nx][ny] = true;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    cin >> W >> H >> n;
    for(int i=0; i<n; i++)
        cin >> X1[i];
    for(int i=0; i<n; i++)
        cin >> X2[i];
    for(int i=0; i<n; i++)
        cin >> Y1[i];
    for(int i=0; i<n; i++)
        cin >> Y2[i];
    solve();
    return 0;
}