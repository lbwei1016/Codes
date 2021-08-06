/*
***Sweep Line / DP / DaC***

    O(N)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    ll res = 0, p_max = 0; //prefix sum
    for(int i=0; i<n; i++) {
        int p;
        scanf("%d", &p);
        //若前方為負，則捨棄
        p_max = p_max > 0 ? p_max+p : p;
        res = max(res, p_max);
    }
    printf("%lld", res);
    return 0;
}