#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll _pow(ll x, int n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res *= x;
        n >>= 1;
        x *= x;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    while(cin >> N) {
        int d = 0;
        ll tmp = N;
        for(ll i=N; i>=10; i/=10, d++);
        
        ll A = 0, B = 0;
        //exception
        if((N / _pow(10, d-1)) == 10) {
            A = _pow(10, d);
        } else {
            for(; d>=0; d--) {
                ll p = _pow(10, d);
                ll r = tmp / p;
                if(!(r & 1)) {
                    A += (r+1) * p;
                    if(r == 0) B = 0;
                    else B += (r-1) * p;
                    break;
                }
                A += r * p;
                B += r * p;
                tmp -= r * p;
            }
        }
        for(int i=d-1; i>=0; i--) {
            ll p = _pow(10, i);
            A += p;
            B += 9 * p;
        }
        cout << min(A-N, N-B) << '\n';
    }
    return 0;
}