/*
***Modular (multiplicative) inverse*** --Fermat's Little Theorem
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, p;

//a^(p-2)

ll exp(ll x, int n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % p;
        x = x * x % p;
        n >>= 1;
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &p);
    for(int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        printf("%lld ", exp(a, p-2));
    }
    return 0;
}