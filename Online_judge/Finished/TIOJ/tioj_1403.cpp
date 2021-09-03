/*
***Simulation / BIT*** (*)
    Solution:
        超車數量可以輕鬆地以 BIT 計算出來，超車過後車子相對位置
        的改變才是本題重點。
        用 linked list 紀錄車輛位置關係；
        用 set 來記錄可以超車的集合，並持續取出最小值，同時更新車輛相對位置。
    O(X logn + n logV)
        X: 最大超車次數
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6, V = 100, N = 250005, EPS = 1e-8;
typedef long double lb;
int n, x[N], v[N];
int bit[V+1];

struct P { 
    int at, nex;
    lb t; // 超車的時間點
    P (int _at, int _nex) {
        at = _at, nex = _nex;
        t = lb(x[nex]-x[at])/lb(v[at]-v[nex]);
    }
    bool operator < (const P &p) const {
        // 時間早的在前面，否則超車發生位置小的在前
        if(abs(t-p.t) > EPS) return t < p.t;
        return x[at]+v[at]*t < x[p.at]+v[p.at]*p.t;
    }
};
set<P> S; // 可以超車的集合
// linked list
struct L {
    int nex, pre;
} lis[N];

void update(int i) {
    while(i <= V) {
        bit[i] = (bit[i]+1)%MOD; i += i&-i;
    }
}
int query(int i) {
    int res = 0;
    while(i > 0) {
        res = (res+bit[i])%MOD; i -= i&-i;
    }
    return res;
}
void BIT() {
    int res = 0;
    // 由後到前，代表找出 v[i]<v[j]: i>j 的數量
    for(int i=n; i>0; --i) {
        res = (res+query(v[i]-1))%MOD;
        update(v[i]);
    }
    cout << res << '\n';
}
// 確認是否可以超車
void check(int at) {
    int nex = lis[at].nex;
    if(!at || nex>n || v[nex]>=v[at]) return;
    S.insert(P(at ,nex)); // 可以超車
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> x[i] >> v[i];
    }
    BIT();
    // 建構 linked list，紀錄車輛位置前後關係
    for(int i=1; i<=n; ++i) {
        lis[i].nex = i+1;
        lis[i].pre = i-1;
        check(i);
    }
    int cnt = 10000; // 最多只要印 10000 筆
    // 每台車一次只超一台車
    while(!S.empty()) {
        // 類似 heap 用法，只是因為還要刪除，所以使用 set
        P p = *S.begin(); S.erase(S.begin());
        cout << p.at << ' ' << p.nex << '\n';
        // 因為已經超車，所以前後關係改變
        int pree = lis[p.at].pre, nexx = lis[p.nex].nex;
        // 刪除已經不存在的位置關係
        S.erase(P(pree, p.at)); S.erase(P(p.nex, nexx));
        lis[p.at].pre = p.nex; lis[p.at].nex = nexx;
        lis[p.nex].pre = pree; lis[p.nex].nex = p.at;
        lis[pree].nex = p.nex; lis[nexx].pre = p.at;
        // 確認是否可以超車
        check(pree); check(p.at);
        if(!(--cnt)) break;
    }
    return 0;
}