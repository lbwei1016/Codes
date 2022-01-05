/*
***Modular multiplicative inverse***
    Description:
        Find x such that (a * x) mod P = 1, and "a and P are relatively prime".
    Solution I: 
        Fermat's Little Theorem: "when P is a prime", a^P ≡ a(mod P).
        If gcd(a, P) = 1, a^(P-1) ≡ 1(mod P).
        => a^(P-2) ≡ a^(-1)(mod P)
        => a * a^(P-2) ≡ a * a^(-1) ≡ a^(P-1) ≡ 1(mod P)
        Hence, a^(P-2) is a "Modular multiplicative inverse" of "a (mod P)".
            O(log n)
    Solution II:
        Extended Euclidean algorithm: (a * x) mod P = 1
        => ax - Py = 1 = gcd(a, P) (互質!!!!!!!!!!)
            O(log n)
    Note:
        若 n | (a-b)，則可以說「在模 n 下，a 同餘 b」，即 a ≡ b(mod n)。
        (這個定義比較容易思考和驗證。)
*/
#include <iostream>
using namespace std;

typedef long long ll;
int n, p;

int extgcd(int a, int b, int &x, int &y) {
    int d = a; // gcd(a, b)
    if(b != 0) {
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }
    else {
        x = 1; y = 0;
    }
    return d;
}
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
    printf("How many inverses to find?\n");
    scanf("%d", &n);
    printf("To mod what?\n");
    scanf("%d", &p);
    for(int i=0; i<n; i++) {
        int a, x = 0, y = 0;
        ll res;
        printf("Whose inverse?\n");
        scanf("%d", &a);
        res = exp(a, p-2);
        extgcd(a, p, x, y);
        // cout << x << '\n';
        // printf("%lld %d\n", res, (x+p)%p);
        // printf("x: %d y: %d\n", x, y);
        printf("Your inverse is here: %d\n", (x+p)%p);
    }
    return 0;
}