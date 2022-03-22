#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    Node *lch, *rch;
    void print() {
        cout << id << ' ';
    }
};

void preorder(Node *node) {
    if (node != nullptr) {
        node->print();
        preorder(node->lch);
        preorder(node->rch);
    }
}

void inorder(Node *node) {
    if (node != nullptr) {
        inorder(node->lch);
        node->print();
        inorder(node->rch);
    }
}

void postorder(Node *node) {
    if (node != nullptr) {
        postorder(node->lch);
        postorder(node->rch);
        node->print();
    }
}

int main() {

    return 0;
}