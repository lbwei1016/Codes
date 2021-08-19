/*
***Tree***
    Solution:
        Binary Search Tree 走訪
*/
#include <bits/stdc++.h>
using namespace std;

struct P { 
    int u, d; 
    P operator + (const P p) {
        return {u+p.u, d+p.d};
    }
};
int m, n;

void traverse(const P &q, P cur, P lb, P rb, P par) {
    // 交叉相乘避免浮點數
    int ch = q.u*cur.d - q.d*cur.u;
    if(ch == 0) return;
    if(ch < 0) {
        putchar('L');
        traverse(q, cur+lb, lb, cur, cur);
    }
    else {
        putchar('R');
        traverse(q, cur+rb, cur, par, par);
    }
}
int main() {
    P x = {0, 1}, y = {1, 0}, z = {1, 1};
    while(scanf("%d%d", &m, &n) == 2) {
        if(m == 1 && n == 1) break;
        if(m < n) {
            putchar('L');
            traverse(P{m, n}, P{1, 2}, x, z, z);
        }
        else {
            putchar('R');
            traverse(P{m, n}, P{2, 1}, z, y, y);
        }
        puts("");
    }
    return 0;
}