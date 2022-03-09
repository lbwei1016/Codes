/*
***Segment Tree***
    Description:
        給定一 1~N 的 permutation，進行 Q 次以下操作:
            1. 對於範圍 [l, r] 進行 ascending sorting
            2. 對於範圍 [l, r] 進行 descending sorting
        1 <= l <= r <= N，共 Q 組。

        最終找出 X 的所在位置 (1 <= X <= N)。
    Solution:
        因為最後只要找出 X 在哪，所以其他數字的資訊並不重要。
        於是，定義兩數列:
            BP: 將「大於等於」X 的數設為 1，小於 X 的數設為 0
            SP: 將「大於」 X 的數設為 1，小於 X 的數設為 0
        此二數列的差異僅在於值本為 X 的位置。因此，分別對兩數列
        進行 Q 次操作後，兩者相異之處就是 X 的所在位置 !

        關於排序區間 [l, r]: 只需計算出區間 "1" 的數量 (e.g. n1)，
        再將 [l, r-n1] 全設為 0、[r-n1+1, r] 設為 1 即可 ! 
        (descending 則反之)

        值得一提的是，計算 1 的數量相當於計算「區間和」；為了要同時具備
        區間賦值和區間和查詢，我把當前 range 的區間和拆成兩部分: 左子樹
        和右子樹的區間和。詳見實作。
    O(N + QlogN)
*/
#include <bits/stdc++.h>
using namespace std;
#define LC(v) (2*(v)+1)
#define RC(v) (2*(v)+2)

const int SIZE = 1 << 20;
struct SEG {
    int tag; // 區間被 assign 的值
    // 子樹區間和 (lval: 僅左子樹; rval: 僅右子樹)
    int lval, rval; 
    bool mark; // 區間是否被賦值 (或可省略)
    SEG(): tag(0), lval(0), rval(0), mark(false) {};
} seg[SIZE];

struct QUERY { int c, l, r; };

void build(int v, int l, int r, vector<int> &P) {
    seg[v].lval = seg[v].rval = seg[v].mark = seg[v].tag = 0;
    if(r-l == 1) {
        seg[v].lval = P[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(LC(v), l, mid, P);
    build(RC(v), mid, r, P);

    // pull
    seg[v].lval = seg[LC(v)].lval + seg[LC(v)].rval;
    seg[v].rval = seg[RC(v)].lval + seg[RC(v)].rval;
}

void push(int v) {
    // 取消自己的標記，推至子樹
    if (seg[v].mark) {
        seg[LC(v)].tag = seg[RC(v)].tag = seg[v].tag;
        seg[LC(v)].mark = seg[RC(v)].mark = true;
        seg[v].mark = false;
    }
}

void update(int v, int l, int r, int ml, int mr, int mval) {
    if(mr - ml <= 0) return;
    if(ml<=l && r<=mr) {
        seg[v].tag = mval;
        seg[v].mark = true;
        return;
    }
    push(v);
    int mid = (l + r) >> 1;
    if(mr <= mid) 
        update(LC(v), l, mid, ml, mr, mval);
    else if(ml >= mid)
        update(RC(v), mid, r, ml, mr, mval);
    else {
        update(LC(v), l, mid, ml, mr, mval);
        update(RC(v), mid, r, ml, mr, mval);
    }

    // pull
    // 注意此處使用 "=" 而非 "+="
    if (seg[LC(v)].mark)
        seg[v].lval = seg[LC(v)].tag * (mid-l);
    else 
        seg[v].lval = seg[LC(v)].lval + seg[LC(v)].rval;
    if (seg[RC(v)].mark)
        seg[v].rval = seg[RC(v)].tag * (r-mid);
    else 
        seg[v].rval = seg[RC(v)].lval + seg[RC(v)].rval;
}

// query the no. of 1s (range sum query)
int query(int v, int l, int r, int ql, int qr) {
    if(ql<=l && r<=qr) {
        if (seg[v].mark) return (r - l)*seg[v].tag;
        else return seg[v].lval + seg[v].rval;
    }
    push(v);
    int mid = (l + r) >> 1;
    if(qr <= mid) 
        return query(LC(v), l, mid, ql, qr);
    else if(ql >= mid)
        return query(RC(v), mid, r, ql, qr);
    else 
        return query(LC(v), l, mid, ql, qr) + query(RC(v), mid, r, ql, qr);
}

void solve(int n, vector<QUERY> &qs, vector<int> &P) {
    for(auto x: qs) {
        int c = x.c, l = x.l, r = x.r;
        int num_of_1 = query(0, 0, n, l, r);
        if(c == 1) {
            update(0, 0, n, l, r-num_of_1, 0);
            update(0, 0, n, r-num_of_1, r, 1);
        }
        else {
            update(0, 0, n, l, l+num_of_1, 1);
            update(0, 0, n, l+num_of_1, r, 0);
        }
    }
    // update
    for(int i=0; i<n; ++i)
        P[i] = query(0, 0, n, i, i+1);
}

int main() {
    int n, q, x;
    cin >> n >> q >> x;

    int N = 1;
    while(N < n) N <<= 1;

    // big, small
    vector<int> BP(N), SP(N); // BP: all minus (X-1); SP: all minus X
    vector<QUERY> qs(q);
    for(int i=0; i<n; ++i) {
        int tmp; cin >> tmp;
        BP[i] = ((tmp - (x-1)) > 0);
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