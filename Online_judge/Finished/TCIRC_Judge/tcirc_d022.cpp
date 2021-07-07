/*
***Binary Exponentiation*** -- irrational number
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll P = 1e9+9;

void exp(ll x, ll y, ll n) {
    ll res_x = 1, res_y = 0;
    while(n > 0) {
        if(n & 1) {
            ll tres_x = res_x;
            res_x = ((res_x*x % P) + (2LL*res_y*y) % P) % P;
            res_y = ((x*res_y % P) + (y*tres_x % P)) % P;
        }
        ll tx = x;
        x = ((x*x) % P + (2LL*y*y) % P) % P;
        y = (2LL*tx*y) % P;
        n >>= 1;
    }
    printf("%lld %lld\n", res_x, res_y);
}

int main() {
    ll x, y, n;
    scanf("%lld%lld%lld", &x, &y, &n);
    exp(x, y, n);
    return 0;
}