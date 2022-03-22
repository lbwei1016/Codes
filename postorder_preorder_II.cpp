/*
    Construct the binary search tree first.
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
Node* rec(int &id, int mn, int mx) {
    if (id < 0) return nullptr;

    int cur = vals[id];
    if (cur < mn || cur > mx) 
        return nullptr;
    
    Node *root = new Node(cur);
    --id;
    root->rch = rec(id, cur+1, mx);
    root->lch = rec(id, mn, cur-1);

    return root;
}

void preorder(Node *node) {
    if (node == nullptr) return;
    cout << node->val << ' ';
    preorder(node->lch);
    preorder(node->rch);
}

int main() {
    io;
    int val;
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> val;
        vals.push_back(val);
    }
    --n;
    Node *root = rec(n, -INF, INF);
    preorder(root);
    return 0;
}