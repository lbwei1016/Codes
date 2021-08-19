/*
***Divide and Conquer*** --  The Closest Pair Problem (tj_d056)
    Solution:
        要在遞迴前先取中點 x 值，因為遞迴後就變成依照 y 排序 !!!
*/
#include <bits/stdc++.h>
using namespace std;

struct P { double x, y; };
const double INF = 1e10, EPS = 1e-8;
int n;

inline bool cmp(P p1, P p2) { return p1.x < p2.x; };
// reduce calling sqrt()
inline double dis(P p1, P p2) {
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
// [)
double dac(int l, int r, vector<P> &ps) {
    if(l+1 == r) return INF;
    int m = (l+r) >> 1;
    double mid_x = ps[m].x; // 要在遞迴前先取中點 x 值，因為遞迴後就變成依照 y 排序
    double d = min(dac(l, m, ps), dac(m, r, ps));

    vector<P> tmp(r-l);
    int cnt = 0, j = m;
    // sort ps[] by "y"
    for(int i=l; i<m; ++i) {
        while(j<r && ps[j].y < ps[i].y) {
            tmp[cnt++] = ps[j++];
        }
        tmp[cnt++] = ps[i];
    }
    for(int i=l; i<j; ++i) ps[i] = tmp[i-l];
    // sieve by "x"
    cnt = 0;
    for(int i=l; i<r; ++i) {
        if((abs(mid_x-ps[i].x) < d)) tmp[cnt++] = ps[i];
    }
    for(int i=0; i<cnt; ++i) {
        for(j=i+1; j<cnt && tmp[j].y-tmp[i].y<d; ++j) {
            double dd = dis(tmp[i], tmp[j]);
            // reduce calling sqrt()
            if(dd < d*d) 
                d = sqrt(dd);
        }  
    }
    return d;
}
int main() {
    while(scanf("%d", &n) == 1) {
        if(n == 0) break;
        vector<P> ps(n);
        for(int i=0; i<n; ++i) 
            scanf("%lf%lf", &ps[i].x, &ps[i].y);
        sort(ps.begin(), ps.end(), cmp);
        double ans = dac(0, n, ps);
        if(ans >= 10000.0-EPS) puts("INFINITY");
        else printf("%.4lf\n", ans);
    }
    return 0;
}