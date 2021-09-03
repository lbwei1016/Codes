/*
***Segment Tree*** (2021/08/30)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 500005;
struct SEG {
    ll val, tag;
    SEG() : val(0), tag(0) {}
} seg[1<<20];
int N, Q, c;

void update(int v, int l, int r, ll val, int ul, int ur) {
    if(ul<=l && r<=ur) {
        // 若完全被更新區間覆蓋，只需更新標籤就好
        // 也就是自己的子節點將仰賴自己的標籤值來加上更新值
        seg[v].tag += val;
        return;
    }
    // if(ur<=l || r<=ul) return;
    int mid = (l+r) >> 1;
    int lc = 2*v+1, rc = 2*v+2;
    if(ur <= mid) update(lc, l, mid, val, ul, ur);
    else if(ul >= mid) update(rc, mid, r, val, ul, ur);
    else {
        update(lc, l, mid, val, ul, ur); 
        update(rc, mid, r, val, ul, ur);
    }
    // 若不完全被更新區間覆蓋，直接更新區間值
    // 子節點則視自身情形 (完全或不完全覆蓋) 來更新
    seg[v].val += (ll)(min(r, ur) - max(l, ul))*val;   
}
ll query(int v, int l, int r, int ql, int qr) {
    // 記得加上標籤值
    if(ql<=l && r<=qr) return seg[v].val + seg[v].tag*(r-l);
    // if(r<=ql || qr<=l) return 0;
    int mid = (l+r) >> 1;
    int lc = 2*v+1, rc = 2*v+2;

    // 不完全被查詢區間覆蓋，只在被查詢的區間加上標籤值
    ll res = (ll)(min(r, qr) - max(l, ql))*seg[v].tag;
    if(qr <= mid) return res + query(lc, l, mid, ql, qr);
    else if(ql >= mid) return res + query(rc, mid, r, ql, qr);

    return res + query(lc, l, mid, ql, qr) + query(rc, mid, r, ql, qr);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int n = 1;
    while(n < N) n <<= 1;
    for(int i=0; i<N; ++i) {
        int val; 
        cin >> val;
        // 不需再另外寫 build()
        update(0, 0, n, val, i, i+1);
    }
    cin >> Q;
    while(Q--) {
        int x, y, k;
        cin >> c >> x >> y;
        if(c == 1) {
            cin >> k;
            update(0, 0, n, k, x-1, y);
        } 
        else 
            cout << query(0, 0, n, x-1, y) << '\n';
    }
    return 0;
}