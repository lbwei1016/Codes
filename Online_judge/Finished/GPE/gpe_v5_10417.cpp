#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll S, D;

bool calc(ll s, const ll &m) {
    ll num = (s+1LL)*s / 2LL;
    num -= m;
    if(num >= D) return true;
    else return false;
}
int main() {
    while(cin >> S >> D) {
        --S;
        ll m = (S+1LL)*S / 2LL;
        int lb = 0, ub = (int)1e9;
        while(ub-lb > 1) {
            int mid = (lb+ub) >> 1;
            if(calc(mid, m)) ub = mid;
            else lb = mid;
        }
        cout << ub << '\n';
    }
    return 0;
}