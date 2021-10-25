#include <stdio.h>
#include <string.h>
#define MOD 10000007

// 乘完的結果會存在 m1
void mul(long long (*m1)[2], long long (*m2)[2]) {
    long long tmp[2][2] = {0};
    for(int i=0; i<2; ++i) {
        for(int j=0; j<2; ++j) {
            for(int k=0; k<2; ++k) {
                tmp[i][j] += m1[i][k] * m2[k][j];
                tmp[i][j] %= MOD;
            }
        }
    }
    memcpy(m1, tmp, sizeof(tmp));
}
// int (*a)[2]: 長度為2的陣列的指標；int *a[2]: 長度為2的指標陣列(兩個指標)
void power(long long (*res)[2], long long (*m)[2], int n) {
    while(n > 0) {
        if(n & 1) mul(res, m);
        mul(m, m);
        n >>= 1;
    }
}
int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        long long res[2][2] = {{1, 1}, {1, 0}};
        long long m[2][2] = {{1, 1}, {1, 0}};
        scanf("%d", &n);
        if(n <= 1) {
            printf("%d\n", n);
            continue;
        }
        power(res, m, n-2);
        printf("%lld\n", res[0][0]);
    }
    
    return 0;
}