/*
***Binary Search***
    Solution:
        Since N is rather large (n < 37), so we divide the whole numbers
        into two groups to accelerate.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, P;
vector<ll> sa, sb;

void rec(vector<ll> &v, vector<ll> &s, int len, int d, ll num) {
    if(d >= len) {
        if(num <= P) s.push_back(num);
        return;
    }
    rec(v, s, len, d+1, num);
    if(num + v[d] > 0) //prevent overflow ?
        rec(v, s, len, d+1, num+v[d]);
}

int main() {
    vector<ll> a, b;
    scanf("%lld%lld", &n, &P);
    int i;
    for(i=0; i<n/2; i++) {
        ll t;
        scanf("%lld", &t);
        a.push_back(t);
    }
    for(; i<n; i++) {
        ll t;
        scanf("%lld", &t);
        b.push_back(t);
    }
    rec(a, sa, a.size(), 0, 0);
    rec(b, sb, b.size(), 0, 0);
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    ll res = 0;
    for(auto e : sb) {
        int it = lower_bound(sa.begin(), sa.end(), P-e) - sa.begin() - 1;
        if(it >= 0) res = max(res, sa[it]+e);
        if(it+1 < sa.size() && sa[it+1] <= P-e) {
            res = max(res, sa[it+1]+e);
        }
    }
    printf("%lld\n", res);
    return 0;
}