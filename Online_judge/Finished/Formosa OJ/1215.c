#include <stdio.h>

void dac(int l, int r, int n) {
    if(l+1 == r) {
        printf("%d ", r);
        return;
    }
    int mid = (l + r) / 2;
    if(n & 1) --r;
    dac(mid, r, r-mid); dac(l, mid, mid-l);
    if(n & 1) dac(r, r+1, 1);
}
int main() {
    int n;
    scanf("%d", &n);
    dac(0, n, n);
    return 0;
}