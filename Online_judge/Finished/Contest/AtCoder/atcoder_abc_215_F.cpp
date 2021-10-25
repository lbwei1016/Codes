/*
***Binary Search / Sliding Window*** (poj_2187) (*)
    Description:
        給定平面上的 N 個點，求任兩點的距離最大值。
        距離定義: 
            min(abs(x1-x2), abs(y1-y2))
        與 poj_2187 不同在於，該題求的是歐基里德距離，因此凸包上必然
        可以得到答案；但本題的距離定義不同，因此兩點極大的 x 差值可能
        會被極小的 y 差值「稀釋」，因而無法成為最大距離，導致答案未必在
        凸包上，要小心。
    Solution:
        可以看出題目要求的是「最大化的最小值」，可以二分搜。
        排序後再進行二分搜，找出在當前搜尋的距離 k 之中是否有
        可能的解使得兩點的 x 和 y 差值都大於 k。(二分性、單調性)
    O(n log(max(xi)))
*/
#include <bits/stdc++.h>
using namespace std;

int n;
struct P {
    int x, y;
    bool operator < (const P &p) const {
        return x < p.x;
    }
};
vector<P> ps;
bool check(int k) {
    queue<P> que;
    // 只需保留最大和最小的 y 座標 (因為 x 座標已經小於當前點的 x 減去 k 了)
    int mn = 1e9+1, mx = 0;
    // sliding window
    for(auto p : ps) {
        while(!que.empty()) {
            // If "que.front().x <= p.x-k", it means that "∆x > k".
            if(que.front().x > p.x-k) break;
            mn = min(mn, que.front().y), mx = max(mx, que.front().y);
            que.pop();
        }
        if(mx-p.y >= k || p.y-mn >= k) return true; // 符合
        que.push(p);
    }
    return false;
}
int main() {
    scanf("%d", &n);
    ps.resize(n);
    for(int i=0; i<n; ++i) scanf("%d%d", &ps[i].x, &ps[i].y);
    sort(ps.begin(), ps.end()); // sort by x first
    int lb = 0, ub = 1e9+1;
    while(ub - lb > 1) {
        int mid = (lb+ub) >> 1;
        if(check(mid)) lb = mid;
        else ub = mid; 
    }
    printf("%d\n", lb);
    return 0;
}