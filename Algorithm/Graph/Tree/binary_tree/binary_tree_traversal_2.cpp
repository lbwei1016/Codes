#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id, level;
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

// 其實 button up 比較好，但現在是用 pointer 存
// 最後: sort(nodes)
void level_order(Node *node, vector<Node> &nodes, int level) {
    if (node != nullptr) {
        node->level = level++;
        nodes.push_back(*node);
        level_order(node->lch, nodes, level);
        level_order(node->rch, nodes, level);
    }
}

int main() {

    return 0;
}