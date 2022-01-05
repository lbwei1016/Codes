#include <stdio.h>
#define LR 10005
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

int main() {
    int n, H[LR] = {0}, L = LR+10, R = 0;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        int l, h, r;
        scanf("%d %d %d", &l, &h, &r);
        for(int j=l; j<r; ++j) {
            H[j] = max(H[j], h);
        }
        L = min(L, l);
        R = max(R, r);
    }
    if(H[1] == 0) printf("1 0 ");
    for(int i=L; i<=R; ++i) {
        if(H[i] != H[i-1]) {
            printf("%d %d ", i, H[i]);
        }
    }
    puts("");
    return 0;
}