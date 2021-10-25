#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, n, x = 0, y = 0, g;
    while(cin >> a >> n) {
        if(n==1) g = 0;
        else g = extgcd(a, n, x, y);
        if(g != 1) cout << "No Inverse\n";
        else cout << (x+n)%n << '\n';
    }    
    return 0;
}