/*
***Recursion***
*/
#include <bits/stdc++.h>
using namespace std;

struct P { int x, y; };
int m, n;
int G[20][20];

int rec(P b1, P b2) {
    if(b1.x == b2.x || b1.y == b2.y) return 0;

    int c0 =  0, c1 = 0;
    int sum = 0;
    for(int x=b1.x; x<=b2.x; x++) {
        G[x][b1.y] == 0 ? c0++ : c1++;
    }
    int a = rec(P{b1.x, b1.y+1}, b2) + min(c0, c1);
    c0 = c1 = 0;
    for(int x=b1.x; x<=b2.x; x++) {
        G[x][b2.y] == 0 ? c0++ : c1++;
    }
    int b = rec(b1, P{b2.x, b2.y-1}) + min(c0, c1);
    c0 = c1 = 0;
    for(int y=b1.y; y<=b2.y; y++) {
        G[b1.x][y] == 0 ? c0++ : c1++;
    }
    int c = rec(P{b1.x+1, b1.y}, b2) + min(c0, c1);
    c0 = c1 = 0;
    for(int y=b1.y; y<=b2.y; y++) {
        G[b2.x][y] == 0 ? c0++ : c1++;
    }
    int d = rec(b1, P{b2.x-1, b2.y}) + min(c0, c1);
    return min(a, min(b, min(c, d)));
}
int main() {
    scanf("%d%d", &m, &n);
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    printf("%d\n", rec(P{0, 0}, P{m-1, n-1}));
    return 0;
}