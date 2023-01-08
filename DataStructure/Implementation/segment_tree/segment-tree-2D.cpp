/*
***Segment Tree*** -- two-dimensional
    Description:
        二維線段樹。值得注意的是，高維的線段樹不能同時提供「區間修改」與
        「區間查詢」兩個功能，只能擇一。原因如下:
            已知兩個節點 A, B，其代表的區域有相交，但是這兩個節點卻不是
            父子關係，因此如果對 A 區間修改，按照遞迴策略，不會更新到 B
            所代表的值，若直接查詢 B 便會發生錯誤。
        細節參照以下程式碼。

        另外，本實作方法使用指標，實現動態加點的功能，對於操作很大而稀疏
        的矩陣有幫助。
    Complexity:
        O((logn)^2): 查詢、更新
*/
#include <bits/stdc++.h>
using namespace std;

int R = 10, C = 5; // 矩陣大小
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
    // range update
    void range_up(int ur1, int ur2, int uc1, int uc2, int k) {
        // 遞迴都是以 row 為判斷基準
        if(ur1<=r1 && r2<=ur2) {
            if(seg2 == nullptr) seg2 = new node2(0, C);
            seg2->update(uc1, uc2, k); // 直接更新行，不須 tag
            return;
        }
        int mr = (r1+r2) >> 1;
        if(ur2 <= mr) {
            if(lc == nullptr) lc = new node1(r1, mr);
            lc->range_up(ur1, ur2, uc1, uc2, k);
        }
        else if(ur1 >= mr) {
            if(rc == nullptr) rc = new node1(mr, r2);
            rc->range_up(ur1, ur2, uc1, uc2, k);
        }
        else {
            if(lc == nullptr) lc = new node1(r1, mr);
            if(rc == nullptr) rc = new node1(mr, r2);
            lc->range_up(ur1, ur2, uc1, uc2, k);
            rc->range_up(ur1, ur2, uc1, uc2, k);
        }
    }
    // single-point
    int sing_qu(int qr, int qc) {
        /*
            所有 seg1 中包含 x = qr 的節點都要做一次 seg2->query()，
            因為區間更新的資訊只儲存在完全被更新區間包含的節點，其父、
            子節點皆無相關資訊，因此對於所有涵蓋查詢點 (qr, qc) 的節點，
            都必須做 seg2->query() 來獲取該 row 範圍更新過的資訊。

            為何不會多算 ?
                在區間更新時，只有完全被更新區間包含的節點才會被更新，因此
                更新是準確的，也就是說，任何被更新過的區間涵蓋的點，必定符合
                更新的資格，也就是應當被更新。
        */
        if(seg2 == nullptr) seg2 = new node2(0, C);
        if(r1+1 == r2) {
            return seg2->query(qc, qc+1);
        }
        int mr = (r1+r2) >> 1;
        if(qr < mr) {
            if(lc == nullptr) lc = new node1(r1, mr);
            return seg2->query(qc, qc+1) + lc->sing_qu(qr, qc);
        }
        else {
            if(rc == nullptr) rc = new node1(mr, r2);
            return seg2->query(qc, qc+1) + rc->sing_qu(qr, qc);
        }
    }
};
int main() {
    node1 *seg1 = new node1(0, R);

    // 單點修改 + 區間查詢
    // seg1->update(0, 0, 2);
    // seg1->update(0, 3, 3);
    // seg1->update(1, 1, 5);
    // seg1->update(2, 2, 1);
    // seg1->update(3, 0, 4);
    // cout << seg1->query(0, 4, 0, 3) << '\n'; 
    // cout << seg1->query(2, 4, 1, 5) << '\n';
    // cout << seg1->query(0, 2, 0, 2) << '\n';

    // 區間修改 + 單點查詢
    // seg1->range_up(1, 3, 0, 2, 6);
    // cout << seg1->sing_qu(1, 1) << '\n';
    // seg1->range_up(1, 4, 3, 5, 9);
    // cout << seg1->sing_qu(1, 3) << '\n';
    // seg1->range_up(0, 2, 1, 4, 7);
    // cout << seg1->sing_qu(1, 3) << '\n';
    return 0;
}