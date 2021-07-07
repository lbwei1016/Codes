/*
***Recursion / Enumeration***

    O(2^N)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P = 10009;
ll n, arr[26];
int ans;

void rec(ll prod, int d) {
    if(d >= n) {
        if(prod == 1) ans++;
        return;
    }
    rec(prod, d+1); //not counting arr[d]
    rec((prod*arr[d])%P, d+1); //count arr[d]
    return;
}

int main() {
    scanf("%lld", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }
    ans = 0;
    rec(1, 0);
    printf("%d\n", ans-1); //-1 for subset {0}
    return 0;
}
/* Sol II: O(n * 2^n)
for(int s=1; s<(1<<n); s++) {
    int p = 1;
    for(int i=0; i<n; i++) {
        if(s & (1<<i)) p = (p*arr[i])%P
    }
    if(p == 1) ans++;
}
printf("%d\n", ans);
*/