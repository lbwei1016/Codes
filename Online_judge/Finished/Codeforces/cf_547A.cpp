/*
***Math*** (*)
    Description:
        Given m, h1, a1, x1, y1, h2, a2, x2, y2；for every second, do the following
        operation:
            h1 = (x1*h1 + y1) % m
            h2 = (x2*h2 + y2) % m
        Calculate the minimum time needed to reach the state such that 
        "h1 = a1" and "h2 = a2", simultaneously.
    Solution:
        The point is to "break down the problem" and "use cycle".

        1. Calc the min time needed("t1") for "h1" to be equal to "a1".
        2. Let "h2" be operated "t1" times (which means two op. is done at the same time).
        3. If "h2 = a2", then the answer is "t1". End procedure.
        4. Otherwise, calc the time for a "cycle" for "h1" to reach "a1" again.
        5. Suppose g(x) = x2*x + y2, and f(x) = g(...g(g(x))) (for c1 times)
           (which represents "h2" undergoes "c1" times of op..). Calc f(x).
        6. Calc how many times of "f(x) op." is needed to let "h2 = a2".
    O(m)
*/
#include <bits/stdc++.h>
using namespace std;

const int M = 1e6+1;
long long m;

inline int f(int p, int q, int x) {
    return (1LL*p*x + 1LL*q) % m;
}
bool calc(int h, int a, int &t, bool vis[], int x, int y) {
    while(true) {
        // re-visited, which means a invalid cycle occurs.
        if(vis[h]) {
            cout << "-1\n";
            return 0;
        } 
        vis[h] = 1;
        h = f(h, y, x);
        ++t;
        if(h == a) return 1;
    }   
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool vis[M];
    int h1, h2, a1, a2;
    int x1, x2, y1_, y2;
    int t1, t2, c1, c2;
    cin >> m;
    cin >> h1 >> a1 >> x1 >> y1_;
    cin >> h2 >> a2 >> x2 >> y2;
    memset(vis, 0, sizeof(vis));
    if(!calc(h1, a1, t1, vis, x1, y1_)) return 0;
    t2 = t1;
    while(t2--) {
        // h2 = (1LL*x2*h2 + 1LL*y2) % m;
        h2 = f(x2, y2, h2);
    }
    if(h2 == a2) {
        cout << t1 << '\n';
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    if(!calc(a1, a1, c1, vis, x1, y1_)) return 0;
    // calculate f(x)
    int p = 1, q = 0;
    for(int i=0; i<c1; ++i) {
        // p = (1LL*p*x2) % m;
        // q = (1LL*q*x2 + y2) % m;
        p = f(p, 0, x2);
        q = f(q, y2, x2);
    }
    memset(vis, 0, sizeof(vis));
    t2 = 0;
    // 計算共需要幾個 c1 週期 (重要!!! 直接計算週期數量而非呆呆的一次一次跑)
    if(!calc(h2, a2, t2, vis, p, q)) return 0;
    cout << (t1 + 1LL*c1*t2) << '\n';
    return 0;
}