/*
***Math*** -- Chinese Remainder Theorem
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll p[5], k[5], M, mx;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if(b != 0) {
        d = extgcd(b, a%b, y, x);
        y -= x*(a/b);
    }
    else {
        x = 1; y = 0;
    }
    return d;
}
ll CRT() {
    ll res = 0, x = 0, y = 0;
    for(int i=0; i<3; ++i) {
        ll Mi = M / p[i];
        extgcd(Mi, p[i], x, y);
        res = (res + k[i]*Mi*x) % M;
    }
    res = (res+M)%M;
    return res <= mx ? res+M : res;
}
int main() {
    while(cin >> p[0]) {
        cin >> p[1] >> p[2];
        cin >> k[0] >> k[1] >> k[2];
        mx = max(max(p[0], p[1]), p[2]);
        M = p[0]*p[1]*p[2];
        cout << CRT() << '\n';
    }
    return 0;
}