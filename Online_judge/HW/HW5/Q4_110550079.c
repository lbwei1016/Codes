#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))

int main() {
    int W, H, wall[300] = {0};
    int sum = 0, w;
    scanf("%d %d", &W, &H);
    for(int i=0; i<H;) {
        scanf("%d", &w);
        ++wall[sum];
        sum += w;
        if(sum == W) {
            sum = 0;
            ++i;
        }
    }
    int mx = 0;
    for(int i=1; i<W; ++i) {
        mx = max(mx, wall[i]);
    }
    printf("%d\n", H-mx);
    return 0;
}