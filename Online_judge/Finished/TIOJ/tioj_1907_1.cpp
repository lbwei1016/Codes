/*
***DP / Binary Search*** -- LIS
    Description:
        求兩鍵值的 LIS。
    Solution:
        先對其中一個鍵值 (w) sort，此時若 w1 = w2，則 h 大的要放前面，理由:
            若 h 小的放前面，對後方更大的值而言，是有利的，但是前面已經選擇的
            娃娃將有可能無法被當前 h 容納。
            若 h 大的放前面，則可以順利容納前面的元素，並且後方與自身 w 相同的
            元素將可以持續更新當前 w 的 h，讓 h 變得更小，以利後方容納。
    O(n logn)
*/
#include <bits/stdc++.h>
using namespace std;

struct P { int x, y; };
int t, m;
vector<P> v, res;

inline bool cmpx(P p1, P p2) { 
    return p1.x==p2.x ? p1.y>p2.y : p1.x<p2.x; 
};
inline bool cmpy(P p1, P p2) { return p1.y<p2.y; };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> m;
        v.resize(m); res.clear();
        for(int i=0; i<m; ++i) {
            int w, h;
            cin >> w >> h;
            v[i] = P{w, h};
        }
        sort(v.begin(), v.end(), cmpx);
        for(auto y : v) {
            auto it = lower_bound(res.begin(), res.end(), y, cmpy);
            if(it == res.end()) res.push_back(y); // 加入
            else *it = y; // 更新，增加潛力
        }
        cout << res.size() << '\n';
    }
    return 0;
}