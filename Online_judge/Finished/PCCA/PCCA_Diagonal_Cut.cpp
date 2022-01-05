#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
// actually this is only called twice
ll rec(ll a, ll b) {
    ll g = gcd(a, b);
    if(g == 1) {
        if(a&1 && b&1) return 1;
        else return 0;
    }
    return (g * rec(a/g, b/g));
}
int main() {
    ll a, b;
    cin >> a >> b;
    // cout << gcd(a, b);
    cout << rec(a, b);
    return 0;
}