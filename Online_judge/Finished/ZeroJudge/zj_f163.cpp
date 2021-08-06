/*
***Segment Tree*** -- Range Sum

    O(M * log n)
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 1e4+5;
struct node { 
    int lc, rc, w; 
    node() {
        lc = rc = w = 0;
    }
};

node seg[1 << 22];
int N, M;
int W[MAX_M];

void build(int v) {
    int lc = seg[v].lc, rc = seg[v].rc;
    if(lc == rc) {
        return;
    }
    build(lc);
    build(rc);
    seg[v].w = seg[lc].w + seg[rc].w;
}
int query(int v, int x) {
    int lc = seg[v].lc, rc = seg[v].rc;
    int res = 1;
    seg[v].w += x;
    if(lc == rc) return v;
    if(seg[lc].w > seg[rc].w) {
        res = query(rc, x);
    } else res = query(lc, x);

    return res;
}

void solve() {
    build(1);
    for(int i=0; i<M; i++) {
        //直接在查詢過程中修改節點資訊，省時又免去紀錄父節點後記憶體不足的問題！！！
        int v = query(1, W[i]);
        printf("%d%c", v, i==M-1 ? '\n' : ' ');
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) {
        int w;
        scanf("%d", &w);
        seg[N+i].w = w;
    }
    for(int i=0; i<M; i++) {
        scanf("%d", &W[i]);
    }
    for(int i=0; i<N-1; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        seg[a].lc = b;
        seg[a].rc = c;
    }

    solve();
    
    return 0;
}