/*
***Graph*** -- Floyd-Warshall
    Description:
        求最小環
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 105, INF = 1e9;
int n, d[N][N];

int floyd_warshall() {
    int mn = INF;
    for(int k=0; k<n; ++k) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(i == k) {
                    d[i][j] = min(d[i][j], d[k][j]);
                }
                else if(k == j) {
                    d[i][j] = min(d[i][j], d[i][k]);
                }
                else {
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                    if(i == j) mn = min(mn, d[i][j]);
                }
            }
        }
    }
    return mn == INF ? -1 : mn;
}
int main() {
    while(scanf("%d", &n) == 1) {
        if(n == 0) break;

        for(int i=0; i<n; ++i) {
            int u;
            for(int j=0; j<n; ++j) {
                d[i][j] = INF; // init
                scanf("%d", &u);
                // 自環無用，因所求為除自環以外的最小環
                if(u == 0 || i == j) continue;
                d[i][j] = u;
            }
        }
        printf("%d\n", floyd_warshall());
    }
    return 0;
}