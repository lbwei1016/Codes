/*
***Recursion***
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define MAXN 20

int n, s, t;
int h[MAXN], c[MAXN]; 
int color_table[MAXN][MAXN]; // color[0] is used to store the quantity of each color
bool vis[MAXN];

int mx_ener, mx_jump;

int calc(int i, int j) {
    return abs((i-j) * (h[i]-h[j]));
}

void rec(int at, int cost, int d) {
    if(at == t) {
        if(cost == mx_ener) 
            mx_jump = max(mx_jump, d);
        else if(cost > mx_ener) {
            mx_ener = cost;
            mx_jump = d;
        }
        return;
    }
    
    int to;
    if(at > 1 && !vis[at-1]) {
        to = at - 1;
        vis[to] = true;
        rec(to, cost+calc(at, to), d+1);
        vis[to] = false;
    }
    if(at < n && !vis[at+1]) {
        to = at + 1;
        vis[to] = true;
        rec(to, cost+calc(at, to), d+1);
        vis[to] = false;
    }
    for(int i=0; i<color_table[0][c[at]]; ++i) {
        to = color_table[c[at]][i];
        if(vis[to]) continue;
        vis[to] = true;
        rec(to, cost+calc(at, to), d+1);
        vis[to] = false;
    }
}
int main() {
    scanf("%d %d %d", &n, &s, &t);
    for(int i=1; i<=n; ++i) scanf("%d", &h[i]);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &c[i]);
        int num = color_table[0][c[i]]++;
        color_table[c[i]][num] = i; // a new member for current color
    }
    vis[s] = true;
    rec(s, 0, 0);
    printf("%d %d\n", mx_ener, mx_jump);

    return 0;
}