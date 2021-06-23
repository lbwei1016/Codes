/*
***Bipartite Matching / Searching***

    O(V * E) = O((X*Y)^2 * d^2 * p)
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX_X_Y = 12+1;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int X, Y;
char field[MAX_X_Y][MAX_X_Y];
vector<int> dX, dY; //coordinate of doors
vector<int> pX, pY; //coor of people
//dist[y][x][y'][x']: shortest path from door (y, x) to person (y', x')
int dist[MAX_X_Y][MAX_X_Y][MAX_X_Y][MAX_X_Y]; 

vector<int> G[20000]; //bipartite matching graph
int match[20000];
bool used[20000];

//find the shortest path for people to a door
void bfs(int x, int y, int d[MAX_X_Y][MAX_X_Y]) {
    queue<int> qx, qy;
    d[y][x] = 0;
    qx.push(x);
    qy.push(y);
    while(!qx.empty()) {
        x = qx.front(); qx.pop();
        y = qy.front(); qy.pop();
        for(int k=0; k<4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(0<=nx && nx<X && 0<=ny && ny<Y && field[ny][nx]=='.' && d[ny][nx] < 0) {
                d[ny][nx] = d[y][x] + 1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
}

void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v) {
    used[v] = true;
    for(int i=0; i<G[v].size() ;i++) {
        int u = G[v][i], w = match[u];
        if(w < 0 || !used[w] && dfs(w)) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

void solve() {
    int n = X * Y;
    dX.clear(); dY.clear();
    pX.clear(); pY.clear();
    memset(dist, -1, sizeof(dist));

    for(int y=0; y<Y; y++) {
        for(int x=0; x<X; x++) {
            if(field[y][x] == 'D') {
                dX.push_back(x);
                dY.push_back(y);
                bfs(x, y, dist[y][x]);
            }
            else if(field[y][x] == '.') {
                pX.push_back(x);
                pY.push_back(y);
            }
        }
    }

    int d = dX.size(), p = pX.size();
    for(int v=0; v<n*d+p; v++)
        G[v].clear();
    for(int i=0; i<d; i++) {
        for(int j=0; j<p; j++) {
            int d_to_p = dist[dY[i]][dX[i]][pY[j]][pX[j]];
            if(d_to_p >= 0) {
                //to enumerate all possible situations of a person can go
                //k is distance, and is time as well
                for(int k=d_to_p; k<=n; k++) {
                    add_edge((k-1)*d+i, n*d+j);
                }
            }
        }
    }

    //calculate least time to spend -- bipartite 
    if(p == 0) {
        printf("0\n");
        return;
    }
    int num = 0;
    memset(match, -1, sizeof(match));
    for(int v=0; v<n*d; v++) {
        memset(used, 0, sizeof(used));
        if(dfs(v)) {
            if(++num == p) {
                printf("%d\n", v / d + 1);
                return;
            }
        }
    }
    printf("impossible\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &Y, &X);
        for(int y=0; y<Y; y++) {
            scanf("%s", field[y]);
        }
        solve();
    }
    
    
    return 0;
}