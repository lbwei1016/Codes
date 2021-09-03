/*
***DP / BIT*** -- LIS (*)
    Description:
        求兩鍵值的 LIS。
    Solution:
        先 sort，然後進入正題。
        定義:
            c[x]: 以 x 為結尾的 LIS 長度
        而 c[] 作為 BIT 的本體進行資料維護，紀錄前綴最大值，也就是說
        c[x] 代表的是 max{c[y]: y<x}。更新與查詢皆與一般 BIT 無異。
    Comparison:
        與二分搜方法複雜度相同，多出來的特性是可以求以原陣列中任意值為結尾
        的 LIS。
    O(n logn)
*/
#include <bits/stdc++.h>
using namespace std;

const int M = 2e4+5, H = 1005;
struct P { int w, h; };
int t, m, mxh; // mxh: 最大的 h
vector<P> v;
// c[x]: 以 x 為結尾的 LIS 長度
// c[] 是 BIT 本體
int c[H];

inline bool cmpw(P p1, P p2) {
    return p1.w==p2.w ? p1.h>p2.h : p1.w<p2.w;
}
void update(int i, int val) {
    while(i <= mxh) {
        c[i] = max(c[i], val);
        i += i & -i;
    }
}
int query(int i) {
    int mx = 0;
    while(i > 0) {
        mx = max(mx, c[i]);
        i -= i & -i;
    }
    return mx;
}
void LIS() {
    for(int i=0; i<m; ++i) {
        // 更新以 v[i].h 結尾的 LIS (小於 v[i].h 的 LIS +1)
        update(v[i].h, query(v[i].h-1) + 1);
    }
    // [0, mxh]
    cout << *max_element(c, c+mxh+1) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> m;
        v.resize(m); mxh = 0;
        memset(c, 0, sizeof(c));
        for(int i=0; i<m; ++i) {
            cin >> v[i].w >> v[i].h;
            mxh = max(mxh, v[i].h);
        }
        sort(v.begin(), v.end(), cmpw);
        LIS();
    }
    return 0;
}