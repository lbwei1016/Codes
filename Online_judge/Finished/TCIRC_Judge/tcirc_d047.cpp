/*
***Greedy***

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

struct cost { int w, f; };
//w / f  越小擺越前面 => 用交叉相乘避免 float
bool cmp(const cost a, const cost b) {
    return a.w*b.f < b.w*a.f;
}
int main() {
    int n;
    scanf("%d", &n);
    vector<cost> v(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i].w);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i].f);
    }
    sort(v.begin(), v.end(), cmp);
    long long res = 0, weight = 0;
    for(int i=1; i<n; i++) {
        weight += v[i-1].w;
        res += weight * (long long)v[i].f;
    }
    printf("%lld\n", res);
    return 0;
}