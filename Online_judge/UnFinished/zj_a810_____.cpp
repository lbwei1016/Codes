#include <bits/stdc++.h>

using namespace std;

#define LLINF 0x7fffffffffffffff
typedef long long ll;
ll a, b, x, y;

ll gcd(ll x, ll y)
{
    if(y == 0LL) 
        return x;
    return gcd(y, x%y);
}
ll lcm(ll x, ll y)
{
    ll r = gcd(x, y);
    if(r == 0)
        return 0;
    return x * y / r;
}
ll LCM(ll aa, ll bb)
{
    ll t,a=aa,b=bb;
    if( a < b ) t=b, b=a, a=t;
    if( b == 0ll ) return 0ll;
    while( t = a%b ) a=b, b=t;

    aa /= b;
    if ( aa > LLINF/bb ) return LLINF;
    else return aa*bb;
}
ll factor(ll n, ll x, ll y, ll l)
{
    ll ans = (x == 0LL ? 0LL : n/x);
    ans += (y == 0LL? 0LL : n/y);
    ans -= (l == 0LL ? 0LL : n/l);

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> x >> y;

    int zero = (a==0LL || b==0LL || a*b<0LL);
    x = abs(x); y = abs(y);
    if(a == 0LL) 
        a++;
    else if(b == 0LL) 
        b--;

    ll res = 0LL;
    ll l = LCM(x, y);
    if(a < 0LL && b < 0LL)
        res = factor(-a, x, y, l) - factor(-b-1, x, y, l) + zero;
    else if(a > 0LL && b > 0LL)
        res = factor(b, x, y, l) - factor(a-1, x, y, l) + zero;
    else
        res = factor(b, x, y, l) + factor(-a, x, y, l) + zero;


    cout << res << '\n';

    return 0;
}