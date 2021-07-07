/*
***Binary Exponentiation*** --Large number
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
char num[205];

ll exp(ll x, ll y, ll p) {
    if(y == 0) return 1;
    if(y & 1) return (exp(x, y-1, p)*x) % p;
    ll t = exp(x, y/2, p);
    return (t*t) % p;
}

int main() {
    ll x = 0, y, p;
    scanf("%s%lld%lld", num, &y, &p);
    int len = strlen(num);
    for(int i=0; i<len; i++) {
        x *= 10;
        x = (x + num[i] - '0') % p;
    }
    printf("%lld", exp(x, y, p));
    return 0;
}