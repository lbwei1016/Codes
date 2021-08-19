/*
***Tree***
    Solution:
        Binary Search Tree 走訪
*/
#include <bits/stdc++.h>
using namespace std;

int m, n;

int main() {
    while(scanf("%d%d", &m, &n) == 2) {
        if(m == 1 && n == 1) break;
        // u: up；d: down
        int lu = 0, ld = 1; // left
        int ru = 1, rd = 0; // right
        int mu = 1, md = 1; // middle
        while(m!=mu || n!=md) {
            // 交叉相乘避免浮點數
            if(m*(ld+rd) < n*(lu+ru)) {
                ru = mu; rd = md; // 縮小右界
                mu += lu; md += ld; // 移動至下一節點 (分數)
                putchar('L');
            }
            else {
                lu = mu; ld = md; // 擴大左界
                mu += ru; md += rd;
                putchar('R');
            }
        }
        puts("");
    }
    return 0;
}