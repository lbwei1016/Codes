/*
***Segment Tree*** --lazy propagation
    Description:
        區間賦值。精隨就是每次「update 或 query 前都要 push」!
    Note:
        複雜版可看 atcoder_abc_237_G。
*/
#include <bits/stdc++.h>
#define LC(v) (2*(v)+1)
#define RC(v) (2*(v)+2)
using namespace std;

struct Seg {
    int tag; // 初始值也儲存在這
    bool marked; // 自己所包含的區間是否被賦值
    Seg(): tag(0), marked(false) {}
} seg[1 << 4];

void build(int v, int l, int r, vector<int> &arr) {
    if (l == r-1) {
        seg[v].tag = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(LC(v), l, mid, arr);
    build(RC(v), mid, r, arr);
}

// update 或 query 前都要 push
void push(int v) {
    if (seg[v].marked) {
        // 將資訊 push 到子節點
        seg[LC(v)].tag = seg[RC(v)].tag = seg[v].tag;
        seg[LC(v)].marked = seg[RC(v)].marked = true;
        // 移除自己的標記
        seg[v].marked = false;
    }
}

void update(int v, int l, int r, int ul, int ur, int val) {
    if (ul<=l && r<=ur) {
        seg[v].tag = val;
        seg[v].marked = true;
        return;
    }
    int mid = (l + r) / 2;
    push(v);
    if (ur <= mid) {
        update(LC(v), l, mid, ul, ur, val);
    }
    else if (ul >= mid) {
        update(RC(v), mid, r, ul, ur, val);
    }
    else {
        update(LC(v), l, mid, ul, ur, val);
        update(RC(v), mid, r, ul, ur, val);
    }
    
}
// 單點查詢
int query(int v, int l, int r, int qu) {
    if (seg[v].marked) return seg[v].tag;
    if (l == r-1) return seg[v].tag;
    push(v);
    int mid = (l + r) / 2;
    if (qu < mid) return query(LC(v), l, mid, qu);
    else return query(RC(v), mid, r, qu);
}

int main() {
    int n = 8;
    vector<int> arr = {5, 7, 1, 0, 3, 6, 4};
    build(0, 0, n, arr);
    printf("first query of arr[3](no update yet): %d\n", query(0, 0, 8, 3));
    update(0, 0, n, 3, 6, 100);
    update(0, 0, n, 2, 5, -100);
    printf("after updating:\n");
    for (int i=0; i<arr.size(); ++i) {
        printf("%d ", query(0, 0, n, i));
    }

    return 0;
}