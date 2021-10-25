/*
不太清楚如何操作 (2021/07)
*/
#include <bits/stdc++.h>
using namespace std;

const int M = 100;
struct node {
    static node mem[M];
    static int top;
    int val;
    node(int v = 0) : val(v) {}
    struct ptr {
        int c;
        ptr() {}
        ptr(const node *s) : c(s - mem) {} // how to use?
        node *operator-> () { return mem + c; }
    } l, r;
    void *operator new (size_t x) { return mem + top++; }
};
node node::mem[M];
int node::top;

int main() {
    node *np = new node(10);
    cout << np->val << '\n';
    cout << node::top << '\n';
    return 0;
}