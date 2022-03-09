/*
***Divide and Conquer***
    Description:
        找出所有點對其距離小於等於 K。
    Solution:
        解法同最近點對。值得注意的是，此處求的是歐幾里德距離，為避免 floating point
        誤差，於是不開根號而直接以平方比較，惟須開到 unsigned loong long。
    O(n logn)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

struct Point { ll x, y, id; };
const int MAX_N = 2e5+5;
int n;
ll K;
Point P[MAX_N]; // points

set<pair<ll, ll> > S;

bool cmp(Point p1, Point p2) {
    return p1.x < p2.x;
}

ll dist(ll x, ll y, ll a, ll b) {
    if (x < a) swap(x, a);
    if (y < b) swap(y, b);
    return (x-a)*(x-a) + (y-b)*(y-b);
}

ll rec(int l, int r) {
    if(l+1 >= r) return 0;
    int m = (l+r) >> 1;
    ll mid_x = P[m].x; // 要在遞迴前先取中點 x 值，因為遞迴後就變成依照 y 排序 !!!
    // int dis = min(rec(l, m), rec(m, r));
    ll cnt = rec(l, m) + rec(m, r);

    int j = m;
    /*
        This array is used for two purposes:
            1. a temporary memory for merge sort
            2. to store valid points whose x coordinate is 
               [P[m].x - dis, P[m].x + dis]
    */
    Point t[r-l];
    // merge sort by "y"
    for(int i=l, k=0; i<m; i++) {
        while(j<r && P[j].y < P[i].y) {
            t[k++] = P[j++];
        }
        t[k++] = P[i];
    }
    for(int i=l; i<j; i++) {
        P[i] = t[i-l];
    }

    int k = 0;
    // go over every element (sorted by "y") and check their "x"
    for(int i=l; i<r; i++) {
        int mx = max(P[i].x, mid_x);
        int mn = min(P[i].x, mid_x);
        if(mx-mn <= K)
            t[k++] = P[i];
    }
    // sweep from the point with least "y"
    for(int i=0; i<k; i++) {
        // O(1): the loop will maximally execute 8 times
        for(j=i+1; j<k && t[j].y-t[i].y<=K; j++) {
            ll dis = dist(t[i].x, t[i].y, t[j].x, t[j].y);
            if (dis <= K*K) {
                int mx = max(t[i].id, t[j].id);
                int mn = min(t[i].id, t[j].id);
                if (S.count(make_pair(mn, mx))) continue;
                ++cnt;
                S.insert(make_pair(mn, mx));
            } 
        }
    }
    return cnt;
}
int main() {
    scanf("%d %llu", &n, &K);
    for(int i=0; i<n; i++) {
        scanf("%llu %llu", &P[i].x, &P[i].y);
        P[i].id = i+1;
    }
    // sort first by "x"
    sort(P, P+n, cmp);
    printf("%llu\n", rec(0, n));
    for (auto &x: S) {
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}