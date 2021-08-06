/*
***Sweep Line***

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

struct P { int s, t; };
int n, X, Y;
vector<P> v;

bool cmp(P p1, P p2) {
    return (p1.s == p2.s ? p1.t > p2.t : p1.s < p2.s);
}
int solve() {
    if(v[0].s > X) return -1;
    if(v[0].t >= Y) return 1;
    P last = v[0], next = v[0];
    int cnt = 2;
    for(int i=1; i<n && next.t<Y; i++) {
        //替換為較晚結束的來延長
        if(v[i].s <= last.t) {
            if(v[i].t > next.t) {
                next = v[i];
            }
        } else {
        //新增
            if(v[i].s <= next.t) {
                last = next;
                next = v[i];
                cnt++;
            } else return -1;
        }
    }
    return cnt;
}
int main() {
    scanf("%d%d%d", &n, &X, &Y);
    v.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &v[i].s, &v[i].t);
        //開始時間不需早於所求區段
        v[i].s = v[i].s < X ? X : v[i].s;
    }
    sort(v.begin(), v.end(), cmp);
    printf("%d\n", solve());
    return 0;
}