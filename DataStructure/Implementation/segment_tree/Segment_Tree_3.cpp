/*
***Segment Tree*** -- pointer
    Description:
        指標版線段樹，優點是清楚明瞭，缺點是耗費空間。因此還有
        另一種「偽指標」方法可以動態分配空間，並擁有和指標類似
        的操作，見 "/Concept/pseudo_pointer.cpp"。
    Complexity: (Master Theorem)
        build: O(n)
        modify: O(log n)
        query: O(log n)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
struct node {
    int val;
    node *l, *r;
    node(int v=0) : val(v) {}
    node(node *_l, node *_r) : l(_l), r(_r) { pull(); }
    void pull() { val = min(l->val, r->val); } // 向上更新
};

int arr[N]; // 原陣列
node *build(int l, int r) {
    if(l+1 == r) return new node(arr[l]);
    int mid = (l+r) >> 1;
    // construct 的同時也會更新 (constructor)
    return new node(build(l, mid), build(mid, r));
}
// 單點修改
void modify(node *a, int l, int r, int pos, int val) {
    if(l+1 == r) {
        a->val = val; return;
    }
    int mid = (l+r) >> 1;
    if(pos < mid) modify(a->l, l, mid, pos, val);
    else modify(a->r, mid, r, pos, val);
    a->pull(); // 記得更新
}
int query(node *a, int l, int r, int ql, int qr) {
    if(ql<=l && r<=qr) return a->val;
    int mid = (l+r) >> 1;
    if(qr <= mid) return query(a->l, l, mid, ql, qr);
    else if(ql >= mid) return query(a->r, mid, r, ql, qr);
    return min(query(a->l, l, mid, ql, qr), query(a->r, mid, r, ql, qr));
}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) cin >> arr[i];
    node *seg = build(0, n);
    cout << query(seg, 0, n, 0, n) << '\n';
    modify(seg, 0, n, 5, -888);
    cout << query(seg, 0, n, 0, n) << '\n';
    return 0;
}