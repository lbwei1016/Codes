/*
***Segment Tree*** -- two-dimensional
    Solution:
        二維線段樹。
    Note:
        像這種單純的單點修改 + 區間查詢，而且矩形不大，用 BIT 的時間和空間
        效率都比 Segment Tree 好得多。
    Complexity:
        O((logn)^2): 查詢、更新
*/
#include <bits/stdc++.h>
using namespace std;

int R, C; // 矩陣大小
// 內層，掌管 column
struct node2 {
    int val, tag;
    int l, r; // [l, r): 將區間包含在結構內，優點方便呼叫，缺點耗空間
    node2 *lc, *rc;
    node2(int _l, int _r) : val(0), tag(0), l(_l), r(_r), lc(nullptr), rc(nullptr) {}

    // range-update
    void update(int ul, int ur, int k) {
        if(ul<=l && r<=ur) {
            tag += k; return;
        }
        int mid = (l+r) >> 1;
        if(ur <= mid) {
            if(lc == nullptr) lc = new node2(l, mid);
            lc->update(ul, ur, k);
        }
        else if(ul >= mid) {
            if(rc == nullptr) rc = new node2(mid, r);
            rc->update(ul, ur, k);
        }
        else {
            if(lc == nullptr) lc = new node2(l, mid);
            if(rc == nullptr) rc = new node2(mid, r);
            lc->update(ul, ur, k);
            rc->update(ul, ur, k);
        }
        val += (min(r, ur) - max(l, ul))*k;
    }
    int query(int ql, int qr) {
        if(ql<=l && r<=qr) return val + (r-l)*tag;
        int mid = (l+r) >> 1;
        int res = (min(r, qr)-max(l, ql)) * tag;
        if(qr <= mid) {
            if(lc == nullptr) {
                lc = new node2(l, mid);
                return res;
            }
            return res + lc->query(ql, qr);
        }
        else if(ql >= mid) {
            if(rc == nullptr) {
                rc = new node2(mid, r);
                return res;
            }
            return res + rc->query(ql, qr);
        }
        if(lc == nullptr) lc = new node2(l, mid);
        if(rc == nullptr) rc = new node2(mid, r);
        return res + lc->query(ql, qr) + rc->query(ql, qr);
    }
}; 
// 外層，掌管 row
struct node1 {
    int r1, r2; // [r1, r2): row 的上下界
    node1 *lc, *rc;
    node2 *seg2; 
    node1(int _r1, int _r2) : r1(_r1), r2(_r2) {
        lc = rc = nullptr;
        seg2 = nullptr;
    }
    
    // single-point update
    void update(int ur, int uc, int k) {
        if(r1+1 == r2) {
            if(seg2 == nullptr) seg2 = new node2(0, C);
            seg2->update(uc, uc+1, k);
            return;
        }
        int mr = (r1+r2) >> 1;
        if(ur < mr) {
            if(lc == nullptr) lc = new node1(r1, mr);
            lc->update(ur, uc, k);
        }
        else {
            if(rc == nullptr) rc = new node1(mr, r2);
            rc->update(ur, uc, k);
        }
        if(seg2 == nullptr) seg2 = new node2(0, C);
        seg2->update(uc, uc+1, k); // pull
    }
    // range query
    int query(int qr1, int qr2, int qc1, int qc2) {
        if(qr1<=r1 && r2<=qr2) {
            if(seg2 == nullptr) {
                seg2 = new node2(0, C);
                return 0; // 以下為空，直接回傳 0
            }
            // tag 標記的部分直接交給 seg2->query()
            return seg2->query(qc1, qc2);
        }
        int mr = (r1+r2) >> 1;
        if(qr2 <= mr) {
            if(lc == nullptr) lc = new node1(r1, mr);
            return lc->query(qr1, qr2, qc1, qc2);
        }
        else if(qr1 >= mr) {
            if(rc == nullptr) rc = new node1(mr, r2);
            return rc->query(qr1, qr2, qc1, qc2);
        }
        if(lc == nullptr) lc = new node1(r1, mr);
        if(rc == nullptr) rc = new node1(mr, r2);
        return lc->query(qr1, qr2, qc1, qc2) + rc->query(qr1, qr2, qc1, qc2);
    }
};
int main() {
    int n, c;
    scanf("%d", &n);
    R = C = n;
    node1 *seg1 = new node1(0, R);
    while(scanf("%d", &c) == 1) {
        if(c == 1) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            seg1->update(x, y, z);
        }
        else {
            int xa, ya, xb, yb;
            scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
            printf("%d\n", seg1->query(xa, xb+1, ya, yb+1));
        }
    }
    return 0;
}