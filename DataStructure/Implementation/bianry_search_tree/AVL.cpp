/*
***AVL Tree*** (2022/5/15)
*/
#include <bits/stdc++.h>
#include "AVL.h"
using namespace std;


// inorder
void print(AVL *root) {
    if (root == nullptr) return;
    print(root->lch);
    printf("key: %d; val: %d\n", root->data.key, root->data.val);
    print(root->rch);
}

int main() {
    // 有一起始 root，key = val = 1e9
    AVL *root = new AVL;
    vector<int> v = {10, 4, 30, 29, 31, -1, 3, 2, 6, 5};
    for (auto x: v) {
        root->insert(x, x);
    }
    print(root);
    AVL::erase(root, 30);
    puts("--------------------------------");
    print(root);
    AVL::erase(root, 10);
    puts("--------------------------------");
    print(root);
    AVL::erase(root, 31);
    puts("--------------------------------");
    print(root);
    AVL::erase(root, 3);
    puts("--------------------------------");
    print(root);
    AVL::erase(root, 6);
    puts("--------------------------------");
    print(root);
    return 0;
}