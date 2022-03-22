/*
    Description:
        Given a distinct sequence of keys representing the postorder traversal 
        of a binary search tree, find its "preorder" traversal.
    Solution:
        Every time find a root first, and then search for the node that indicates
        the edge of left and right subtree (in the postorder traversal). Do it 
        recursively so that left subtree is traversed first.
    Note:
        This is an awful method; the only good point is it saves memory.
    O(n^2)
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

vector<int> node, res;
void rec(int from, int to) {
    if (to - from <= 0) {
        // < 0: no such subtree
        // = 0: exactly one node
        if (to - from == 0)
            res.push_back(node[from]);
        return;
    }
    int root = node[to];
    res.push_back(root);

    // "chl" will be the first node appear in the right subtree (if right subtree exists)
    int chl;
    for (chl=from; node[chl]<root; ++chl); 

    rec(from, chl-1); // left subtree
    rec(chl, to-1); // right subtree
}

int main() {
    // io;
    int val;
    while (cin >> val) {
        node.push_back(val);
    }
    rec(0, node.size()-1);
    for (auto x: res) {
        cout << x << ' ';
    }

    return 0;
}