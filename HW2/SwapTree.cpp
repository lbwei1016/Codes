#include <iostream>
using namespace std;

struct BST {
    int val;
    BST *lch, *rch;
    BST(int _val): val(_val), lch(nullptr), rch(nullptr) {}
};

void SwapTree(BST *node) {
    if (node == nullptr) return;
    SwapTree(node->lch);
    SwapTree(node->rch);
    swap(node->lch, node->rch);
}

BST* add(int val) {
    return new BST(val);
}

void trav(BST *node) {
    cout << node->val << ' ';
    if (node->lch != nullptr) trav(node->lch);
    if (node->rch != nullptr) trav(node->rch);
}

int main() {
    BST *root = add(0);
    root->lch = add(1);
    root->rch = add(2);
    root->lch->lch = add(3);
    root->rch->rch = add(4);
    trav(root);
    cout << '\n';
    SwapTree(root);
    trav(root);
    return 0;
}