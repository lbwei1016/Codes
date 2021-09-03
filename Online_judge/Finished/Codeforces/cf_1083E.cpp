/*
***DP*** -- Covex Hull Optimization (https://codeforces.com/blog/entry/63823)
    Description:
        有 n 個長方形，左下頂點在 (0, 0)，右上頂點在 (xi, yi)，且每一長方形
        有一權重 ai。選擇一些長方形，使得長方形面積的聯集扣去權重和有最大值，
        求該最大值。保證沒有一個長方形完全被另一個長方形包覆。
    Solution:
        f(i) 為「選擇第 i 個長方形的最大值」。因為「保證沒有一個長方形完全被
        另一個長方形包覆」，所以當我們先把長方形依照 x 座標由小到大排序，就能
        確保 y 座標是遞減的，並得出遞迴式:
            f(i) = xi*yi - ai + max{-xj*yi + f(j) | 0<=j<i}
        naive 算法是 O(n^2)，太慢，又因為遞迴式中，「-xj*yi + f(j)」直線的特
        性，因此可以採取「斜率 (凸包) 優化」。
        為避免原長方形的平面座標與凸包的座標搞混，令遞迴式:
            f(i) = pi*qi - ai + max{-pj*qi + f(j) | 0<=j<i}

        我們需要維護的凸包結構須包含兩部分: 插入和查詢。
            查詢是對於還沒更新的 f(i)，查詢「max{-pj*qi + f(j) | 0<=j<i}」。
            因為已經將長方形依照 "pi" (x 座標)遞增排序，可以知道 "qi" 是遞減的；
            也就是說，若凸包中的直線 L 在 "x = qi" 不能產出最大函數值，那麼在接下
            來的 "x = qk: k>i => qk<qi" 也不可能產出最大函數值，於是 L 可以被捨棄，
            並持續向後檢查。

            插入是將代表第 i 個長方形的資訊加入凸包。由上述可知，長方形 i 的資訊是:
            「-pi*x + f(i)」，而 pi 是遞增的，因此斜率 "-pi" 將遞減，也就是說，直線
            必定由凸包左端加入；此時要檢查，當前直線 Li 與原斜率最小直線 L0 的交點，
            是否在 L0 與斜率次小的直線 L1 的交點的右邊。若是，則 L0 可以捨棄 (畫圖)，
            並持續向後檢查。(判斷凸包平面的 x 座標)
        綜合查詢與插入的需求，可以看出，前後兩端都必須是動態的，因此實作使用 deque。
    Note: 
        在函式 "intersectX()" 中，求取的交點是用整數來儲存，但交點可能為浮點數；其實
        實際上，這題的座標都是整數，即使求出浮點數的、可以得到最大值的區間，也不會被查
        詢；因此，可以直接判斷無條件捨去後的整數就好。
    Complexity:
        每個長方形至多進入和離開 deque 一次，O(n)；排序 O(n logn)
        => O(n logn)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6+5;
struct RECT { 
    ll p, q, a; 
    bool operator < (const RECT &r) const {
        return p < r.p;
    }
};
int n;
RECT rect[N];
struct LINE {
    ll m, c;
    ll eval(ll x) { return m*x + c; }
    ll intersectX(LINE l) { return (c-l.c) / (l.m-m); }
};

ll covex_hull_optimization() {
    deque<LINE> dq;
    dq.push_back({0, 0});
    ll ans = 0;
    for(int i=0; i<n; ++i) {
        while(dq.size()>=2 && dq.back().eval(rect[i].q)<=dq[dq.size()-2].eval(rect[i].q))
            dq.pop_back();
        // f(i) = xi*yi - ai + max{-xj*yi + f(j) | 0<=j<i}
        ll f = rect[i].q*rect[i].p - rect[i].a + dq.back().eval(rect[i].q);
        ans = max(ans, f);
        // -pi*x + f(i)
        LINE cur = {-rect[i].p, f};
        while(dq.size()>=2 && cur.intersectX(dq[0])>=dq[0].intersectX(dq[1]))
            dq.pop_front();
        dq.push_front(cur);
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        scanf("%lld%lld%lld", &rect[i].p, &rect[i].q, &rect[i].a);
    }
    sort(rect, rect+n);
    printf("%lld\n", covex_hull_optimization());
    return 0;
}