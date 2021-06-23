/*
***Simulation***
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 50;
int G[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, op;
    vector<int> dx, dy;

    cin >> N >> op;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> G[i][j];
        }
    }

    if(op == 0) {
        dx = {-1, 0, 1, 0};
        dy = {0, -1, 0, 1};
    }
    else if(op == 1) {
        dx = {0, 1, 0, -1};
        dy = {-1, 0, 1, 0};
    }
    else if(op == 2) {
        dx = {1, 0, -1, 0};
        dy = {0, 1, 0, -1};
    }
    else {
        dx = {0, -1, 0, 1};
        dy = {1, 0, -1, 0};
    }

    int res = 1; //when reaches N^2 ends
    int x = N/2, y =  N/2;
    int t = 1, cnt = 0;
    printf("%d", G[x][y]);
    while(true) {
        for(int i=0; i<4; i++) {
            if(cnt == 2) {
                cnt = 0;
                t++;
            }
            for(int j=1; j<=t; j++) {
                x += dx[i], y += dy[i];
                printf("%d", G[y][x]);
                res++;
                if(res == N * N) return 0;
            }
            cnt++;
        }
    }
    
    return 0;
}