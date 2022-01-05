#include <stdio.h>

int G[(1<<9)+5][(1<<9)+5];
int pow_2[20];
void div(int x, int y, int n, int val) {
    if(n == 1) {
        G[x][y] = val;
        G[x][y+1] = val+1;
        G[x+1][y] = val+2;
        G[x+1][y+1] = val+3;
        return;
    }
    div(x, y, n-1, val);
    div(x, y+pow_2[n-1], n-1, val+pow_2[2*n-2]);
    div(x+pow_2[n-1], y, n-1, val+2*pow_2[2*n-2]);
    div(x+pow_2[n-1], y+pow_2[n-1], n-1, val+3*pow_2[2*n-2]);
}
int main() {
    int n, x, ex, ey;
    scanf("%d %d", &n, &x);

    pow_2[0] = 1;
    for(int i=1; i<20; ++i) {
        pow_2[i] = 2* pow_2[i-1];
    }

    div(1, 1, n, 1);
    for(int i=1; i<=pow_2[n]; ++i) {
        for(int j=1; j<=pow_2[n]; ++j) {
            printf("%d ", G[i][j]);
            if(G[i][j] == x) {
                ex = i, ey = j;
            }
        }
        puts("");
    }
    printf("%d %d\n", ex, ey);
    return 0;
}