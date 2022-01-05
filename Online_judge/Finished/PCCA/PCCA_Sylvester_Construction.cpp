/*
***Find Pattern***
    Solution:
        因為左上、右上、左下的子矩陣都相同，且右下只是多了負號，
        重點是，矩陣大小是 2 的冪次。於是，從給定的 n 開始，不斷
        將矩陣減半，其中只要決定是否要加負號就好(在右下角)。
*/
#include <stdio.h>

int calc(int x, int y, long long n) {
    // x -= n: 平移(因為子矩陣除了負號，是完全相同的)
    int v = 1;
    while(n > 1) {
        n >>= 1;
        if(x < n) {
            if(y >= n) y -= n;
        }
        else {
            x -= n; 
            // 如果在右下角
            if(y >= n) {
                v = -v;
                y -= n;
            }
        }
    }
    return v;
}
int main() {
    long long n;
    int t, x, y, w, h;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld %d %d %d %d", &n, &x, &y, &w, &h);
        for(int r=y; r<y+h; ++r) {
            if(w) printf("%d", calc(x, r, n));
            for(int c=x+1; c<x+w; ++c) {
                printf(" %d", calc(c, r, n));
            }
            puts("");
        }
        puts("");
    }
    return 0;
}