#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_M = 5e4+5;
struct P { ll a, b; };
int n, m;
ll c[MAX_M];
vector<P> L;

bool comp(P &p1, P &p2) {
    return (p1.a == p2.a ? p1.b < p2.b : p1.a < p2.a);
}
ll f(P p, ll x) {
    return p.a * x + p.b;
}
ll rec(int ll, int rl, int lp, int rp) {
    if(lp >= rp) return 0;
    int mid = (lp+rp) / 2;
    long long max_y = LLONG_MIN, at;
    for(int i=ll; i<rl; i++) {
        long long y = f(L[i], c[mid]);
        if(y > max_y) {
            max_y = y;
            at = i;
        }
    }
    return max_y + rec(ll, at+1, lp, mid) + rec(at, rl, mid+1, rp);
}
int main() {
    scanf("%d%d", &n, &m);
    L.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%lld%lld", &L[i].a, &L[i].b);
    }
    for(int i=0; i<m; i++) {
        scanf("%lld", &c[i]);
    }
    sort(L.begin(), L.end(), comp);
    sort(c, c+m);
    printf("%lld\n", rec(0, n, 0, m));
    return 0;
}