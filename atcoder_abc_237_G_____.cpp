#include <bits/stdc++.h>
using namespace std;
#define LC(v) (2*(v)+1)
#define RC(v) (2*(v)+2)

const int SIZE = 1 << 4;
struct SEG {
    // tag: children are all 1s or all 0s, or neither(-1)
    int val, tag;
    SEG(): val(0), tag(0) {};
} seg[SIZE];

struct QUERY {
    int c, l, r;
};

void build(int v, int l, int r, vector<int> &P) {
    // seg[v].tag = seg[v].val = -1;
    if(r-l == 1) {
        seg[v].val = P[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(LC(v), l, mid, P);
    build(RC(v), mid, r, P);
    seg[v].val += seg[LC(v)].val + seg[RC(v)].val;
}

void modify(int v, int l, int r, int ml, int mr, int mval) {
    if(mr - ml <= 0) return;
    if(ml<=l && r<=mr) {
        seg[v].tag += mval;
        seg[v].tag = max(0, min(seg[v].tag, 1));
        return;
    }
    int mid = (l + r) >> 1;
    if(mr <= mid) 
        modify(LC(v), l, mid, ml, mr, mval);
    else if(ml >= mid)
        modify(RC(v), mid, r, ml, mr, mval);
    else {
        modify(LC(v), l, mid, ml, mr, mval);
        modify(RC(v), mid, r, ml, mr, mval);
    }
    seg[v].val += (min(r, mr)-max(l, ml)) * mval;
    seg[v].val = max(0, min(seg[v].val, (min(r, mr)-max(l, ml))));
}

// query the no. of 1s
int query(int v, int l, int r, int ql, int qr) {
    if(ql<=l && r<=qr) {
        if(seg[v].tag) return r - l;
        else return seg[v].val;
    }
    int mid = (l + r) >> 1;
    int tagv = (min(r, qr) - max(l, ql)) * seg[v].tag;
    if(qr <= mid) 
        return tagv + query(LC(v), l, mid, ql, qr);
    else if(ql >= mid)
        return tagv + query(RC(v), mid, r, ql, qr);
    else 
        return tagv + query(LC(v), l, mid, ql, qr) + query(RC(v), mid, r, ql, qr);
}

// int srh(int v, int l, int r, int sv) {
//     if(seg[v].tag != -1) return seg[v].tag;
//     if(r-l == 1) return seg[v].val;

//     int mid = (l + r) >> 1;
//     if(sv < mid) return srh(LC(v), l, mid, sv);
//     else return srh(RC(v), mid, r, sv);
// }

void solve(int n, vector<QUERY> &qs, vector<int> &P) {
    for(auto x: qs) {
        int c = x.c, l = x.l, r = x.r;
        int num_of_1 = query(0, 0, n, l, r);
        int num_of_0 = r - l - num_of_1;
        if(c == 1) {
            modify(0, 0, n, l, l+num_of_0, -1);
            modify(0, 0, n, l+num_of_0, r, 1);
        }
        else {
            modify(0, 0, n, l, l+num_of_1, 1);
            modify(0, 0, n, l+num_of_1, r, -1);
        }
    }
    // int mcnt = 1;
    // while(mcnt < n) mcnt *= 2;
    // --mcnt;
    for(int i=0; i<n; ++i) {
        // if(seg[i+n-1].tag != -1) P[i] = seg[i+n-1].tag;
        P[i] = query(0, 0, n, i, i+1);
        cout << P[i] << ' ';
    }
    puts("");
}

int main() {
    int n, q, x;
    cin >> n >> q >> x;

    int N = 1;
    while(N < n) N <<= 1;

    vector<int> BP(N), SP(N); // big: all minus (X-1); small: all minus X
    vector<QUERY> qs(q);
    for(int i=0; i<n; ++i) {
        int tmp; cin >> tmp;
        BP[i] = (tmp - (x-1) > 0);
        SP[i] = ((tmp - x) > 0);
    }

    for(auto &x: qs) {
        cin >> x.c >> x.l >> x.r;
        --x.l;
    }
    
    
    
    build(0, 0, N, BP);
    solve(N, qs, BP);
    build(0, 0, N, SP);
    solve(N, qs, SP);

    for(int i=0; i<n; ++i) {
        if(BP[i] != SP[i]) {
            cout << i+1 << '\n';
            break;
        }
    }
    return 0;
}