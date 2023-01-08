/*
預先設好 memory pool，省去 delete 的麻煩；只要重設 memory pool 的 pointer 就好。
*/
#include <bits/stdc++.h>
using namespace std;

const int MEM = 100;
struct Node {
    static Node mem[MEM]; // memory pool
    static Node *ptr;
    Node *lc, *rc;
    int sum; // 只是 data
    Node(): lc(nullptr), rc(nullptr), sum(0) {}
    Node(Node *_node): lc(_node->lc), rc(_node->rc), sum(_node->sum) {}
    void pull() {
        sum = lc->sum + rc->sum;
    }
};
Node Node::mem[MEM], *ptr = Node::mem; // remember to declare static variable

int main() {
    // initalize
    ptr = Node::mem;
    Node *node = new(ptr++) Node();
    return 0;
}