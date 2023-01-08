/*
    Description:
        Given a distinct sequence of keys representing the postorder traversal 
        of a binary search tree, construct the corresponding binary search tree.
    Note: 
        Left subtree is always smaller than root. 
    O(n)
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int INF = 1e9;

struct Node {
    int val;
    Node *lch, *rch;
    Node(int _v): val(_v), lch(nullptr), rch(nullptr) {}
};
vector<int> vals;

// remember the "&" before id
// 子樹允許的值域: (mn, mx)，若不再範圍內即不在目前子樹
// build from postorder traversal
Node* from_post(int &id, int mn, int mx) {
    if (id < 0) return nullptr;

    int cur = vals[id];
    if (cur < mn || cur > mx) 
        return nullptr;
    
    Node *root = new Node(cur);
    --id;
    root->rch = from_post(id, cur+1, mx);
    root->lch = from_post(id, mn, cur-1);

    return root;
}

// build from preorder traversal
Node* from_pre(const int &n, int &id, int mn, int mx) {
    if (id == n) return nullptr;

    int cur = vals[id];
    if (cur < mn || cur > mx) {
        return nullptr;
    }

    Node *root = new Node(cur);
    ++id;
    root->lch = from_pre(n, id, mn, cur-1);
    root->rch = from_pre(n, id, cur+1, mx);

    return root;
}

// Node* from_in(); 
// 僅 Inorder 無法決定單一 BST

void preorder(Node *node) {
    if (node == nullptr) return;
    cout << node->val << ' ';
    preorder(node->lch);
    preorder(node->rch);
}

void postorder(Node *node) {
    if (node != nullptr) {
        postorder(node->lch);
        postorder(node->rch);
        cout << node->val << ' ';
    }
}

int main() {
    io;
    int val, id;
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> val;
        vals.push_back(val);
    }
    // Node *root = from_post(n, -INF, INF);
    // preorder(root);
    id = 0;
    Node *root = from_pre(n, id, -INF, INF);
    postorder(root);
    return 0;
}