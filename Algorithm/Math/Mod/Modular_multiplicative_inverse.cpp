/*
***Modular multiplicative inverse***
    Description:
        Find x such that (a * x) mod P = 1, when "a and P are relatively prime".
    Solution I: (only when "P" is prime)
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

2022/07
    Warning:
        盡量使用 extgcd，因為 Fermat's 限制較嚴格(P 不是 prime 時未必成立)，但 extgcd
        只需兩者互質就好。例如當 a = 4, P = 9:
            Fermat's: inv = 4 (X)
            extgcd: inv = 7 (V)
*/
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int n, p;
// vector<pair<int, int>> Procedure;

int extgcd(int a, int b, int &x, int &y) {
    int d = a; // gcd(a, b)
    if(b != 0) {
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }
    else {
        x = 1; y = 0;
    }
    // Procedure.push_back({x, y});
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

        // two methods
        res = exp(a, p-2);
        int GCD = extgcd(a, p, x, y);
        if (GCD != 1) printf("No inverse!\n"); 
        else {
            printf("Fermat's: %lld\nEuclidean: %d\n", res, (x+p)%p);
        }
        // This is not correct. Fix it later.
        // puts("procedures:\n");
        // int id = 0;
        // for (auto s: Procedure) {
        //     printf("(%d): %d*%d + %d*%d = 1\n", ++i, s.first, a, s.second, p);
        // }
    }
    return 0;
}