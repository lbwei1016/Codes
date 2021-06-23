/*
***BFS***
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int MAX_N = 100+5;
const int MAX_M = 100+5;
const int INF = 1e9;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
int arr[MAX_N][MAX_M];
int sx, sy;

long long bfs() {
    long long res = 0;
    queue<pii> que;
    que.push(pii(sx, sy));
    res += arr[sx][sy];
    arr[sx][sy] = INF;
    while(!que.empty()) {
        pii p = que.front(); que.pop();
        int x = p.first, y = p.second;

        int px = -1, py = -1;
        int mn = INF;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && arr[nx][ny]<mn) {
                mn = arr[nx][ny];
                px = nx;
                py = ny;
            }
        }
        if(px < 0) break;
        que.push(pii(px, py));
        res += arr[px][py];
        arr[px][py] = INF;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int mn = INF;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] < mn) {
                mn = arr[i][j];
                sx = i;
                sy = j;
            }
        }
    }

    cout << bfs() << '\n';
    
    return 0;
}