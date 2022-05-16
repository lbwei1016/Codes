/*
***Binary Search Tree*** (2022/5/15)
*/
#include <bits/stdc++.h>
#include "BST.h"
using namespace std;


// inorder
void print(BST *root) {
    if (root == nullptr) return;
    print(root->lch);
    printf("key: %d; val: %d\n", root->data.key, root->data.val);
    print(root->rch);
}

int main() {
    // 有一起始 root，key = val = -1e9
    BST *root = new BST;
    vector<int> v = {10, 4, 30, 29, 31, -1, 3, 2, 6, 5};
    for (auto x: v) {
        root->insert(x, x);
    }
    print(root);
    root->erase(root, 30);
    puts("--------------------------------");
    print(root);
    root->erase(root, 10);
    puts("--------------------------------");
    print(root);
    root->erase(root, 31);
    puts("--------------------------------");
    print(root);
    root->erase(root, 3);
    puts("--------------------------------");
    print(root);
    root->erase(root, 6);
    puts("--------------------------------");
    print(root);
    return 0;
}