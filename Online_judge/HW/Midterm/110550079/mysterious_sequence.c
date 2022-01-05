#include <stdio.h>
#define T 8

typedef long long ll;
const ll MOD = 1e7+7;
int t;

void mul(ll A[T][T], ll B[T][T]) {
    ll tmp[T][T] = {0};
    for(int i=0; i<t; ++i) {
        for(int j=0; j<t; ++j) {
            for(int k=0; k<t; ++k) {
                tmp[i][j] = (tmp[i][j] + A[i][k]*B[k][j]) % MOD;
            }
        }
    }
    for(int i=0; i<t; ++i) 
        for(int j=0; j<t; ++j) 
            A[i][j] = tmp[i][j];
}
void _pow(ll res[T][T], int n) {
    // 傳入的必須作為結果
    ll M[T][T];
    for(int i=0; i<t; ++i) {
        for(int j=0; j<t; ++j)
            M[i][j] = res[i][j];
    }
    while(n > 0) {
        if(n & 1) {
            mul(res, M);
        }
        n >>= 1;
        mul(M, M);
    }
}
int main() {
    ll M[T][T] = {0}, X[T];
    int n;
    scanf("%d", &t);
    for(int i=0; i<t; ++i) scanf("%lld", &X[t-i-1]);
    for(int i=0; i<t; ++i) scanf("%lld", &M[0][i]);
    for(int i=1; i<t; ++i) {
        for(int j=0; j<t; ++j) 
            if(i-1 == j) M[i][j] = 1;
    }
    scanf("%d", &n);

    if(n < t) {
        printf("%lld\n", X[t-n-1]);
        return 0;
    }
    
    _pow(M, n-t);
    ll ans = 0;
    for(int i=0; i<t; ++i) {
        ans = (ans + M[0][i]*X[i]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}