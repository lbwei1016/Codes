#include <iostream>
#include <vector>
#include "rbtree.hpp"
using namespace std;

char table[2][10] = {
    "black",
    "red"
};

void print(RBtree *root) {
    if (root == RBtree::NIL) return;
    print(root->lch);

    printf("key: %d parent: ", root->node.key);
    if (root->par->node.key != 0)
        printf("%d ", root->par->node.key);
    else printf("  ");
    printf("color: %s\n", table[root->node.is_red]);

    print(root->rch);
}

int main() {
    RBtree *root = RBtree::NIL;
    int t; scanf("%d", &t);
    while (t--) {
        int op, n; scanf("%d %d", &op, &n);
        if (op == 1) printf("Insert: ");
        else printf("Delete: ");
        for (int i=0; i<n; ++i) {
            int x; scanf("%d", &x);
            printf("%d%s", x, (i == n-1 ? "\n" : ", "));
            if (op == 1) RBtree::insert(root, x, x);
            else RBtree::erase(root, x);
        }
        print(root);
    }
}
