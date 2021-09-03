/*
***Geometry*** -- Covex Hull: Andrew's Monotone Chain (*)
    Description:
        已知一平面上的點集，求點集中距離平方最大的兩點
    Solution:
        可以證明，距離最大的兩點必定都在凸包上，因此本題最大任務就
        是求出凸包。
    Note:
        求距離可用 "Rotating Caliper" 優化
    排序 + 凸包 + 距離: O(n logn) + O(n) + O(m^2)
        m: 凸包頂點數 = O(sqrt(X)) (為何?)
        X: 最大座標值 
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
struct P {
    ll x, y;
    // 行列式值
    ll det(P p) {
        return x*p.y - y*p.x;
    }
    // 距離平方
    ll dis(P p) { 
        return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
    }
    P operator - (P p) {
        return {x-p.x, y-p.y};
    }
    bool operator < (const P &p) const{
        return x==p.x ? y<p.y : x<p.x;
    }
};
int n;
vector<P> ps, cov;

void covex_hull() {
    sort(ps.begin(), ps.end()); // x 遞增；ps[0] 和 ps[n-1] 必定在凸包內
    cov.resize(n);  
    int k = 0;
    // 建構下凸包
    for(int i=0; i<n; ++i) {
        // 去除不必要的點
        while(k>1 && (cov[k-1]-cov[k-2]).det(ps[i]-cov[k-1]) <= 0) --k;
        cov[k++] = ps[i];
    }
    // 建構上凸包；i=0 是為了回到出發點，去除不必要的點
    for(int i=n-2, t=k; i>=0; --i) {
        while(k>t && (cov[k-1]-cov[k-2]).det(ps[i]-cov[k-1]) <= 0) --k;
        cov[k++] = ps[i];
    }
    cov.resize(k-1);
}
int main() {
    while(scanf("%d", &n) != EOF) {
        ps.clear(); ps.resize(n);
        cov.clear();
        for(int i=0; i<n; ++i) scanf("%lld%lld", &ps[i].x, &ps[i].y);
        covex_hull();
        ll mx = 0;
        int s = cov.size();
        // 兩兩列舉凸包上的點求距離；另可用旋轉卡尺優化
        for(int i=0; i<s; ++i) {
            for(int j=i+1; j<s; ++j) {
                mx = max(mx, cov[i].dis(cov[j]));
            }
        }
        printf("%lld\n", mx);
    }
    return 0;
}