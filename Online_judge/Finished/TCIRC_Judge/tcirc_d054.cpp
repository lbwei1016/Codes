/*
***Binary Search***

    O(N * log (max P))
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, M, mx;
int p[100005];

bool enough(ll F) {
    if(F < mx) return false;
    int m = M;
    ll f = F;
    for(int i=0; i<n; i++) {
        if(f < p[i]) {
            f = F - p[i];
            m--;
        } else f -= p[i];
        if(m < 0) return false;
    }
    return true;
}
int main() {
    scanf("%d%d", &n, &M);
    mx = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &p[i]);
        mx = max(mx, p[i]);
    }

    ll lb = -1, ub = 1e10;
    while(ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        if(enough(mid)) ub = mid;
        else lb = mid;
    }
    printf("%lld\n", ub);
    return 0;
}