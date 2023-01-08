/*
***Cartesian Tree***
    Description:
        此處實作僅 build() 和 treap 有大不同；見 treap*.cpp。
        若將某序列轉換為 Cartesian Tree，序列的 RMQ 問題可以轉為樹上的 LCA 問題。
    Note:
        Cartesian Tree 可能退化!!!
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Cart {
    int val, sz; // "val" is the priority in heap
    Cart *l, *r;
    Cart(int _v): val(_v), sz(1), l(nullptr), r(nullptr) {}
};

int getSize(Cart *at) {
    if (!at) return 0;
    return at->sz;
}

void Size(Cart *at) {
    at->sz = getSize(at->l) + getSize(at->r) + 1;
}

Cart* build(vector<int> &v) {
    vector<Cart*> stack(v.size());
    Cart *at = nullptr;
    int top = -1, mn = 1e9;
    for (auto x: v) {
        int k = top;
        while (k >= 0 && stack[k]->val > x) --k;
        Cart *cur = new Cart(x);
        if (k >= 0) stack[k]->r = cur;
        if (k < top) cur->l = stack[k+1];
        stack[++k] = cur;
        top = k;

        if (x < mn) {
            at = cur; 
            mn = x;
        }
    }
    return at;
}

Cart* merge(Cart *a, Cart *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->val > b->val) {
        a->r = merge(a->r, b);
        Size(a);
        return a;
    }
    b->l = merge(a, b->l);
    Size(b);
    return b;
}

void split(Cart *at, const int k, Cart *&a, Cart *&b) {
    if (!at) a = b = nullptr;
    else if (getSize(at->l) < k) {
        a = at;
        split(at->r, k-getSize(at->l)-1, a->r, b);
        Size(a);
    }
    else {
        b = at;
        split(at->l, k, a, b->l);
        Size(b);
    }
}

void trav(Cart *at, int type) {
    if (!at) return;
    trav(at->l, type); 
    if (type) cout << at->val << ' ';
    trav(at->r, type);    
    Size(at);
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) cin >> v[i];
    Cart *at = build(v);
    trav(at, 0); // calculate size after build()
    trav(at, 1);
    return 0;
}