#include <bits/stdc++.h>
using namespace std;

int pow2 = 1;

struct seg_tree {
    int val, tag01, tag; // tag; all 0 or all 1
    // int l, r;
    seg_tree *lch, *rch;
    seg_tree(seg_tree *lc, seg_tree *rc): lch(lc), rch(rc), val(0), tag(0), tag01(-1) {};
    seg_tree(int v=0): val(v), tag(0), tag01(-1) {};
    void pull() { val += lch->val + rch->val; };
};

void modify(seg_tree *s, int l, int r, int ml, int mr, int val) {
    if(ml == mr) return;
    if(ml<=l && r<=mr) s->tag = s->tag01 = val;
    else {
        int mid = (l + r) / 2;
        if(mr <= mid) modify(s->lch, l, mid, ml, mr, val);
        else if(ml >= mid) modify(s->rch, mid, r, ml, mr, val);
        else {
            modify(s->lch, l, mid, ml, mr, val);
            modify(s->rch, mid, r, ml, mr, val);
        }
        s->tag01 = -1;
        s->val += (min(r, mr)-max(l, ml)) * val;
    }
}

int query(seg_tree *s, int l ,int r, int pos) {
    if(s->tag != -1) return s->tag;
    if(r - l == 1) return s->val;
    int mid = (l + r) / 2;
    if(pos < mid) query(s->lch, l, mid, pos);
    else query(s->rch, mid, r, pos);
}

int rquery(seg_tree *s, int l ,int r, int ql, int qr) {
    // if(s->tag == 1) return 1;
    if(ql<=l && r<=qr) return s->val + s->tag*(r-l);
    int mid = (l + r) / 2;
    int res = (min(r, qr)-max(l, ql))* (s->tag);
    
    if(qr <= mid) return res + query(s->lch, l, mid, ql, qr);
    else if(ql >= mid) return res + query(s->rch, mid, r, ql, qr);
    else 
        return res + query(s->lch, l, mid, ql, qr) + query(s->rch, mid, r, ql, qr);
}

seg_tree* build(int lb, int rb, vector<int> &v) {
    if(rb - lb == 1) {
        return new seg_tree(v[lb]);
    }
    int mid = (lb + rb) / 2;
    seg_tree *lch = build(lb, mid, v), *rch = build(mid, rb, v);
    seg_tree *s = new seg_tree(lch, rch);
    s->pull();
    return s;
}

int n, q, x;
// vector<int> v;

void solve(vector<int> &v, vector<int> &C, vector<int> &L, vector<int> &R) {
    seg_tree *seg = build(0, pow2, v);
    // cout << seg->val;
    for(int i=0; i<q; ++i) {
        int num1 = rquery(seg, 0, pow2, L[i], R[i]);
        int num0 = R[i] - L[i] - num1;
        if(C[i] == 1) {
            modify(seg, 0, pow2, L[i], L[i]+num0, 0);
            modify(seg, 0, pow2, R[i]-num1, R[i], 1);
        }
        else {
            modify(seg, 0, pow2, L[i], L[i]+num1, 1);
            modify(seg, 0, pow2, R[i]-num0, R[i], 0);
        }
    }
    for(int i=0; i<n; ++i) {
        v[i] = query(seg, 0, pow2, i);
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main() {
    cin >> n >> q >> x;
    vector<int> v1(n), v2(n);
    vector<int> C(q), L(q), R(q);

    for(int i=0; i<n; ++i) {
        int k; cin >> k;
        v1[i] = (k > x);
        v2[i] = (k > x-1); 
    }

    while(pow2 < n) pow2 <<= 1;
    v1.resize(pow2); v2.resize(pow2);
    for(int i=0; i<q; ++i) {
        cin >> C[i] >> L[i] >> R[i];
        ++R[i];
    }
    solve(v1, C, L, R);

    return 0;
}