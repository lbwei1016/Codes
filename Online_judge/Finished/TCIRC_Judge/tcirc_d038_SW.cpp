/*
***Convex Hull*** 

    O(N)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_M = 5e4+5;
struct L { ll a, b; };
int n, m;
ll c[MAX_M];
vector<L> line;
vector<L> dq; //存放可用的直線 (凸包)

bool comp(L &l1, L &l2) {
    return (l1.a == l2.a ? l1.b > l2.b : l1.a < l2.a);
}
inline ll f(L l, ll x) {
    return l.a * x + l.b;
}

int main() {
    scanf("%d%d", &n, &m);
    line.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%lld%lld", &line[i].a, &line[i].b);
    }
    for(int i=0; i<m; i++) {
        scanf("%lld", &c[i]);
    }
    sort(line.begin(), line.end(), comp);
    sort(c, c+m);

    dq.push_back(line[0]);
    for(int i=1; i<n; i++) {
        L l = line[i];
        //不斷向前檢查，是否可以更新直線
        while(dq.size() > 1) {
            ll a1 = dq[dq.size()-2].a, b1 = dq[dq.size()-2].b;
            ll a2 = dq[dq.size()-1].a, b2 = dq[dq.size()-1].b;
            /*
                判斷 l1, l 以及 l2, l 的交點 x 座標 (畫圖看看)
                小技巧:
                    將原本兩者的 x 值交叉相乘，以避免浮點數；
                    因為斜率 a 遞增，因此分母恆正，不等式不變
            */
            if((b1 - l.b) * (l.a - a2) >= (b2 - l.b) * (l.a - a1)) {
                dq.pop_back(); //丟棄 l2
            } else break;
        }
        dq.push_back(l);
    }
    ll res = 0;
    int p = 0, len = dq.size();
    for(int i=0; i<m; i++) {
        //單調順序
        while(p < len-1 && f(dq[p], c[i]) <= f(dq[p+1], c[i])) {
            p++;
        }
        res += f(dq[p], c[i]);
    }
    printf("%lld\n", res);
    return 0;
}