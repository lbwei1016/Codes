/*
***Modular multiplicative inverse***
    Description:
        Find x such that (a * x) mod P = 1, and "a and P are relatively prime".
    Solution I: 
        Fermat's Little Theorem: "when P is a prime", a^(P-1) ≡ 1(mod P)
        => a^(P-2) ≡ a^(-1)(mod P)
        => a * a^(P-2) ≡ a * a^(-1) ≡ a^(P-1) ≡ 1(mod P)
        Hence, a^(P-2) is a "Modular multiplicative inverse" of "a".
            O(log n)
    Solution II:
        Extended Euclidean algorithm: (a * x) mod P = 1
        => ax - Py = 1 = gcd(a, P)
            O(log n)
*/
#include <iostream>
using namespace std;

typedef long long ll;
int n, p;

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