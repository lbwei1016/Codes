/*
***Segment Tree / Greedy***
    Description:
        給定 n 個時間區間，且每個區間必須有 c 秒鐘是「忙碌」的，也
        就是有 c 個區間必須被選上。求選定最少的「忙碌」區間來滿足所
        有條件的區間數量 (秒數)。
    Solution:
        題目可以分成兩部分，首先是貪心:
            claim:
                對於所有區間的時刻選定，皆從區間右界 (結束時刻) 開
                始，因為這樣可以最大化重複使用的區間，即最小化總選定
                區間數量。
            proof:  
                若操作時將所有區間依照右界排列，從右界小的開始處理，
                則當前區間 T 之後的所有區間必定比 T 更晚結束，而 T 
                與之後的區間的交集必定自 T 的右界開始，因此上述成立。
        接著是線段樹 (或是任何可以在線快速查詢區間和的資料結構):
            單純紀錄哪些區間已經被覆蓋。
        
        實作時，利用 stack 來維護所有互不交集的忙碌區間；這是重點 !!!
        (畫圖看看)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
struct T {
    int l, r, c; // 左、右界、忙碌時間
    bool operator < (const T &t) const {
        return r == t.r ? c > t.c : r < t.r;
    }
} arr[N];
struct Seg { 
    int val, tag;
} seg[1<<19];

void init() {
    for(int i=0, j=1<<19; i<j; ++i) 
        seg[i].val = seg[i].tag = 0;
}
void update(int v, int l, int r, int ul ,int ur, int val) {
    if(ul<=l && r<=ur) {
        seg[v].tag += val;
        return;
    }
    int mid = (l+r) >> 1;
    int lc = 2*v+1, rc = 2*v+2;
    if(ur <= mid) update(lc, l, mid, ul, ur, val);
    else if(ul >= mid) update(rc, mid, r, ul, ur, val);
    else {
        update(lc, l, mid, ul, ur, val);
        update(rc, mid, r, ul, ur, val);
    }
    seg[v].val += (min(r, ur) - max(l, ul))*val;
}
int query(int v, int l, int r, int ql, int qr) {
    if(ql<=l && r<=qr) return seg[v].val + (r-l)*seg[v].tag;

    int mid = (l+r) >> 1;
    int lc = 2*v+1, rc = 2*v+2;
    int res = (min(r, qr) - max(l, ql))*seg[v].tag;

    if(qr <= mid) return res + query(lc, l, mid, ql, qr);
    else if(ql >= mid) return res + query(rc, mid, r, ql, qr);
    return res + query(lc, l, mid, ql, qr) + query(rc, mid, r, ql, qr);
}

int main() {
    while(scanf("%d", &n) == 1) {
        if(!n) break;
        init();
        for(int i=0; i<n; ++i) {
            scanf("%d%d%d", &arr[i].l, &arr[i].r, &arr[i].c);
        }
        sort(arr, arr+n);
        stack<pair<int, int> > S;
        for(int i=0; i<n; ++i) {
            // rest: 剩餘所需時數
            int rest = arr[i].c - query(0, 0, N, arr[i].l, arr[i].r);
            if(rest <= 0) continue; // 已滿足
            int now = arr[i].r; // 從右界開始
            // 若當前區間的時刻選定會超出 (完全覆蓋) 最近一個忙碌區間
            while(!S.empty() && now-rest < S.top().second) {
                rest -= now - S.top().second;
                now = S.top().first;
                // 取消原忙碌區間，迴圈結束後會補上
                update(0, 0, N, S.top().first, S.top().second, -1);
                S.pop();
            }
            S.push({now-rest, arr[i].r});
            update(0, 0, N, now-rest, arr[i].r, 1);
        }
        int sum = 0;
        while(!S.empty()) {
            sum += (S.top().second - S.top().first);
            S.pop();
        }
        printf("%d\n", sum);
    }
    return 0;
}