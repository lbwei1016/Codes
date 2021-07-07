/*
***Binary Search***
    Solution:
        Since N is rather large (n < 37), so we divide the whole numbers
        into two groups to accelerate.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, P;
map<ll, ll> sa, sb;
//enumerate the product of elements in a[]
void subset(ll *a, map<ll, ll> &prod, int len_a, int d, ll num) {
    if(d >= len_a) {
        if(!prod.count(num)) prod[num] = 0;
        prod[num]++;
        return;
    }
    subset(a, prod, len_a, d+1, (num * a[d] % P));
    subset(a, prod, len_a, d+1, num);
    return;
}
//for modulor inverse
ll exp(ll x, int n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % P;
        x = x * x % P;
        n >>= 1;
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &P);
    ll a[20], b[20];
    int len_a = n / 2;
    int len_b = n - len_a;
    for(int i=0; i<len_a; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i=0; i<len_b; i++) {
        scanf("%lld", &b[i]);
    }
    subset(a, sa, len_a, 0, 1);
    subset(b, sb, len_b, 0, 1);
    sa[1]--; sb[1]--;

    ll res = 0;
    res = (sa[1] + sb[1]) % P;
    for(auto m : sa) {
        ll x = m.first, num = m.second;
        ll inverse = exp(x, P-2);
        auto it = sb.find(inverse);
        if(it != sb.end()) {
            res = (res + num * it->second) % P;
        }
    }
    printf("%lld\n", res);
    return 0;
}