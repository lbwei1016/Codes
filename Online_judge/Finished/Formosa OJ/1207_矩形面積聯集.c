/*
 -- tioj 1224
*/
#include <stdio.h>
#define COOR 65540
#define MAX_N 1005
#define LC(v) (2*(v)+1)
#define RC(v) (2*(v)+2)

typedef long long ll;
typedef struct {
    int dn, up, y, st; 
} Edge;

Edge E [MAX_N];

struct SEG {
    ll val, tag;
} seg[1<<20]; // 開大一點


void update(int v, int l, int r, int ul, int ur, const int val) {
    if(ul<=l && r<=ur) {
        seg[v].tag += val;
        return;
    }
    int mid = (l + r) >> 1;
    if(ur <= mid) update(LC(v), l, mid, ul, ur, val);
    else if(ul >= mid) update(RC(v), mid, r, ul, ur, val);
    else {
        update(LC(v), l, mid, ul, ur, val);
        update(RC(v), mid, r, ul, ur, val);
    }
    seg[v].val = (seg[LC(v)].tag ? mid-l : seg[LC(v)].val) + 
                (seg[RC(v)].tag ? r-mid : seg[RC(v)].val);
}

void _sort_y(int l, int r, Edge E[]) {
    if(r-l <= 1) return;
    int mid = (l + r) >> 1;
    _sort_y(l, mid, E); _sort_y(mid, r, E);

    Edge tmp[r-l];
    int j = mid;
    for(int i=l, cnt=0; i<mid; ++i) {
        while(j<r && E[j].y<E[i].y) {
            tmp[cnt++] = E[j++];
        }
        tmp[cnt++] = E[i];
    }
    for(int i=l; i<j; ++i) {
        E[i] = tmp[i-l];
    }
}

void init() {
    for(int i=0; i<4*COOR; ++i) 
        seg[i].val = seg[i].tag = 0;
    for(int i=0; i<1005; ++i) 
        E[i] = (Edge){0, 0, 0, 0};
}

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        init();
        scanf("%d", &n);
        for(int i=0, j=0; i<n; ++i) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            E[j++] = (Edge){.dn=x1, .up=x2, .y=y1, .st=1};
            E[j++] = (Edge){.dn=x1, .up=x2, .y=y2, .st=-1};
        }
        _sort_y(0, 2*n, E);

        ll res = 0, val = 0;
        int pre = 0;
        for(int i=0; i<2*n; ++i) {
            Edge e = E[i];
            res += (ll)(e.y-pre) * val;
            if(e.dn != e.up)
                update(0, -COOR, COOR, e.dn, e.up, e.st);
            pre = e.y;
            val = seg[0].val;
        }
        printf("%lld\n", res);
    }
    return 0;
}