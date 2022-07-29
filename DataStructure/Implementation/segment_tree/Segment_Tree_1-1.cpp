/*
***Segment Tree*** (2022/06/22)
    有鑑於原版 Segment_tree_1.cpp 有誤且寫作風格不佳，故有此新版。
    有別於原版，這裡是 0-indexed、區間前閉後開。
    說明參考原版。

    Note:
        將線段樹大小設為二的次方其實「非必要」，只是為了在單點更新 "update()" 
        時可以快速定位葉節點而已，但真的「不需要」!! 乖乖遞迴下去一樣可以用相同
        的複雜度更新。
*/
#include <bits/stdc++.h>
#define LC(v) (2*(v)+1)
#define RC(v) (2*(v)+2)
using namespace std;

const int INF = 1e9+7;
vector<int> seg, arr;

// 沒必要多此一舉
// int init(const int &n) {
//     int pow2_N = 1;
//     while (pow2_N < n) pow2_N *= 2;
//     arr.resize(n);
//     seg.resize(2*pow2_N, INF);
//     return pow2_N;
// }

void build(int v, int l, int r) {
    if (r - l == 1) {
        seg[v] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(LC(v), l, mid);
    build(RC(v), mid, r);

    seg[v] = min(seg[LC(v)], seg[RC(v)]);
}

// void update(int at, int val, const int &sz) {
//     int v = at + sz - 1;
//     seg[v] = val;
//     while (v > 0) {
//         v = (v-1) / 2;
//         seg[v] = min(seg[LC(v)], seg[RC(v)]);
//     }
// }

void update(int v, int l, int r, int pos, int val) {
    if (r - l == 1) {
        seg[v] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos < mid) update(LC(v), l, mid, pos, val);
    else update(RC(v), mid, r, pos, val);
    seg[v] = min(seg[LC(v)], seg[RC(v)]);
}

int query(int v, int l, int r, const int &ql, const int &qr) {
    if (ql <= l && r <= qr) return seg[v];

    int mid = (l + r) / 2;
    if (qr <= mid)
        return query(LC(v), l, mid, ql, qr);
    else if (ql >= mid)
        return query(RC(v), mid, r, ql, qr);
    else 
        return min(query(LC(v), l, mid, ql, qr), query(RC(v), mid, r, ql, qr));
}

int main() {
    int n = 6;
    // int sz = init(n);
    seg.resize(2 * n); // 記得大小開兩倍
    arr = {0, 2, -1, 9, 3, 5};
    build(0, 0, n);

    int q = 10;
    while (q--) {
        printf("Enter \"1 i val\" to change arr[i] to val.\n");
        printf("Enter \"2 ql qr\" to query min among [ql, qr].\n");
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 1) {
            update(0, 0, n, a, b);
        }
        else {
            printf("min among [ql, qr] is: %d\n", query(0, 0, n, a, b+1));
            puts("----------------");
        }
    }
    return 0;
}