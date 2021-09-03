/*
***Segment Tree / Sweep Line*** (*)
    Description:
        給定 n 個矩形的邊界，求所有矩形面積的聯集。
    Solution:
        首先簡化問題: 當問題限縮到一維空間，則所求變為線段聯集，可以
        用 "Sweep Line" 求解。
        回到原問題，我們可以仿照一維的情形，對於二維的其中一個維度採用
        "Sweep Line" 找出聯集區域，而另一維度則利用 "Segment Tree" 
        來記錄矩形覆蓋的部分。實作:
            1.  Sweep Line: (x 方向)
                對於每個矩形，將其左界標記為 "+1"，右界標為 "-1"，並依
                照 x 座標由小到大排。從左往右掃，每掃到一條邊，判定為左
                或是右界，並更新左方已知的矩形面積，再加入 (+1) 或移除 (-1) 
                該矩形的覆蓋範圍 (y 方向，線段樹負責)
            2.  Segment Tree: (y 方向)
                本題的重頭戲。對於平面任意一處，只有被覆蓋或不被覆蓋
                兩種情形，即使同時被數個矩形覆蓋，對於面積的貢獻仍相同。
                因此，線段樹不可以直接紀錄 「區間和」，也就是 「被覆蓋的
                面積和」，因為這樣將會重複計算被數個矩形覆蓋的面積。要
                紀錄的是: 「區間是否有被覆蓋」，要達成這點，線段樹的 "tag"
                紀錄的是: 「當前節點 (區間) 被覆蓋幾次」，tag 是非負實數；
                而 "val" 則紀錄: 「子節點被覆蓋的總長度」。當子節點的 
                "tag" 不為 0，val 等於子節點所代表的區間大小，代表覆蓋，
                否則等於子節點的 "val"，以上往父節點更新的過程稱為 "pull"。
                由於在進行 "pull" 時父節點只關心子節點「tag 是否為零」，
                因此不會產生重複覆蓋的問題，可以正確地表示聯集了 !
        畫圖看看還是很重要的 !
    O(n log(COOR))
        COOR: 最大座標
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int COOR = 1e6+5; // 最大座標值
int n, a1, a2, b1, b2;
struct Edge {
    // x 座標；下 y 座標；上 y 座標；加入(+1)還是移除(-1)
    int x, dn, up, id;
    bool operator < (const Edge &e) const {
        return x == e.x ? id > e.id : x < e.x;
    }
};
vector<Edge> es;

struct Seg { int val, tag; } seg[1<<21];

void update(int v, int l, int r, int ul, int ur, int val) {
    if(ul<=l && r<=ur) {
        seg[v].tag += val; 
        return;
    }
    // if(ul>=r || l>=ur) return;
    int mid = (l+r) >> 1, lc = 2*v+1, rc = 2*v+2;
    // 雖然也可以遞迴下去再判斷邊界，但是先檢查、減少呼叫可以提高效率
    if(ur <= mid) update(lc, l, mid, ul, ur, val);
    else if(ul >= mid) update(rc, mid, r, ul, ur, val);
    else {
        update(lc, l, mid, ul, ur, val); 
        update(rc, mid, r, ul, ur, val);
    }
    // pull !!!
    seg[v].val = (seg[lc].tag ? mid-l : seg[lc].val) +
            (seg[rc].tag ? r-mid : seg[rc].val);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    es.resize(2*n);
    for(int i=0; i<n; ++i) {
        cin >> a1 >> a2 >> b1 >> b2;
        es[i] = Edge{a1, b1, b2, 1}; // 加入: 左邊界
        es[n+i] = Edge{a2, b1, b2, -1}; // 移除: 右邊界
    }
    sort(es.begin(), es.end());

    ll res = 0, pre = 0, val = 0;
    for(int i=0; i<2*n; ++i) {
        res += (ll)(es[i].x-pre) * val; // 更新左方已知的矩形面積
        update(0, 0, COOR, es[i].dn, es[i].up, es[i].id); // 加入或移除 y 方向的覆蓋範圍
        pre = es[i].x;
        val = seg[0].val; // seg[0] 代表全範圍，seg[0].val 就是所有矩形在 y 方向上覆蓋的長度
    }
    cout << res << '\n';
    return 0;
}