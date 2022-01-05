#include <stdio.h>
#define N 20

typedef long long ll;

ll calc(int n, int x, int coff[]) {
    ll x_pow[N] = {1}, res = 0;
    for(int i=1; i<=n; ++i) {
        x_pow[i] = x_pow[i-1] * x;
    }
    for(int i=1; i<=n; ++i) {
        res += (ll)coff[i]*(ll)i*x_pow[i-1];
    }
    return res;
}
int main() {
    int n, x, coff[N];
    scanf("%d %d", &n, &x);
    for(int i=0; i<=n; ++i) {
        scanf("%d", &coff[i]);
    }
    printf("%lld\n", calc(n, x, coff));
    return 0;
}