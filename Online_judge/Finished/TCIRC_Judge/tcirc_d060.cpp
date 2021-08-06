/*
***Sweep Line***
    Solution:
        將開始以及結束點皆放入同一以時間排序的陣列中，自小而大，
        每當遇到開始點(s, id=1)，加入人數，結束點(t, id=-1)反之。

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

struct P { int id, t, m; }; //id: 1: start, -1: end

bool cmp(P p1, P p2) {
    return (p1.t == p2.t ? p1.id > p2.id : p1.t < p2.t);
}
int main() {
    int n;
    scanf("%d", &n);
    vector<P> v;
    for(int i=0; i<n; i++) {
        int m, s, t;
        scanf("%d%d%d", &m, &s, &t);
        v.push_back(P{1, s, m});
        v.push_back(P{-1, t, m});
    }
    sort(v.begin(), v.end(), cmp);
    int mx = 0, num = 0;
    for(auto p : v) {
        //以乘以負一來刪除人數
        num += p.id * p.m;
        mx = max(mx, num);
    }
    printf("%d\n", mx);
    return 0;
}