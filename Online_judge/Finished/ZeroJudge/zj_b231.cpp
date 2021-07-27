/*
***Greedy***
*/
#include <bits/stdc++.h>
using namespace std;

struct P { int p, t; };
bool cmp(P p1, P p2) {
    return p1.t > p2.t;
}
int main() {
    int n;
    scanf("%d", &n);
    vector<P> v(n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &v[i].p, &v[i].t);
    }
    sort(v.begin(), v.end(), cmp);
    int pres = 0, res = 0;
    for(int i=0; i<n; i++) {
        pres += v[i].p;
        res = max(res, pres + v[i].t);
    }
    printf("%d\n", res);
    return 0;
}