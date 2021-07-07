#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
char num[205]; //a number larger than long long

//Recursively
ll exp(ll x, ll y, ll p) {
    if(y == 0) return 1;
    if(y & 1) return (exp(x, y-1, p)*x) % p;
    ll t = exp(x, y/2, p);
    return (t*t) % p;
}
//Loop
ll exp_loop(ll x, ll y, ll p) {
    ll res = 1;
    while(y > 0) {
        if(y & 1) res = res * x % p;
        x  = x * x % p;
        y >>= 1;
    }
    return res;
}

int main() {
    ll x = 0, y, p;
    scanf("%s%lld%lld", num, &y, &p);
    int len = strlen(num);
    //mod first
    for(int i=0; i<len; i++) {
        x *= 10;
        x = (x + num[i] - '0') % p;
    }
    printf("%lld", exp(x, y, p));
    return 0;
}