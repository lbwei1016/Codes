#include <bits/stdc++.h>
using namespace std;

const int N = 300;
int64_t f[N], m[N];
int main() {
    f[0] = 1;
    for(int i=1; i<N; i++) {
        m[i] = m[i-1] + f[i-1];
        f[i] = m[i-1] + 1;
    }
    int n;
    while(scanf("%d", &n) == 1) {
        if(n == -1) break;
        printf("%lld %lld\n", m[n], f[n]+m[n]);
    }
    return 0;
}