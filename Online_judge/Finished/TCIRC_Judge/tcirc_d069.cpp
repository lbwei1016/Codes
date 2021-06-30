/*
***DP*** -- watch out border
*/
#include <bits/stdc++.h>

using namespace std;

int G[205][205];
int M, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=N; j++) {
            cin >> G[i][j];
        }
    }

    int sum = 0;
    //border
    for(int i=2; i<=M; i++) G[i][1] += G[i-1][1];
    for(int j=2; j<=N; j++) G[1][j] += G[1][j-1];

    for(int i=2; i<=M; i++) {
        for(int j=2; j<=N; j++) {
            G[i][j] += max(G[i-1][j], G[i][j-1]);
        }
    }
    cout << G[M][N] << '\n';
    return 0;
}