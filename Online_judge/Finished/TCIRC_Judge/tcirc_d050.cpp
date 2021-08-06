/*
***Sweep Line***

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

struct Seg { int l, r; };
bool cmp(Seg &s1, Seg &s2) {
    return s1.l < s2.l;
}
int main() {
    int n;
    scanf("%d", &n);
    vector<Seg> seg(n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &seg[i].l, &seg[i].r);
    }
    sort(seg.begin(), seg.end(), cmp);
    Seg last = seg[0];
    int res = 0;
    for(int i=1; i<n; i++) {
        if(seg[i].l > last.r) {
            //結算目前線段長
            res += last.r - last.l;
            //更新末端
            last = seg[i];
        //延長末端
        } else last.r = max(last.r, seg[i].r);
    }
    res += last.r - last.l;
    printf("%d\n", res);
    return 0;
}