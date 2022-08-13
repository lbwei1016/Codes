/*
***Graph / Math*** --  Stern-Brocot Tree
*/
#include <bits/stdc++.h>
using namespace std;

const int D = 5, Block = 3;
struct Node {
    int numerator, denominator;
    Node() {}
    Node(int _n, int _d): numerator(_n), denominator(_d) {}
    Node operator+(const Node &p) {
        return Node(numerator + p.numerator, denominator + p.denominator);
    }
} tree[(1 << D) + 5];

vector<int> level;

void print(const Node &p, const int &dep) {
    for (int i=1; i<(1 << (D-dep)); ++i) {
        for (int j=0; j<Block; ++j) printf(" ");
    }
    printf("%d/%d", p.numerator, p.denominator);
    for (int i=0; i<(1 << (D-dep)); ++i) {
        for (int j=0; j<Block; ++j) printf(" ");
    }
}

void build(int at, int dep) {
    if (dep > D) return;
    int left = at - (1 << (D-dep));
    int right = at + (1 << (D-dep));
    tree[at] = tree[left] + tree[right];

    int lch = at - (1 << (D-dep-1));
    int rch = at + (1 << (D-dep-1));
    build(lch, dep+1); build(rch, dep+1);
}

// level-order traversal
void trav(int root) {
    queue<pair<int, int>> que;
    que.push({root, 1});
    int pre_dep = 1;
    while (que.size()) {
        auto who = que.front(); que.pop();
        int at = who.first, dep = who.second;
        if (dep != pre_dep) puts("\n");
        print(tree[at], dep);
        
        pre_dep = dep;

        if (dep == D) continue;
        int lch = at - (1 << (D-dep-1));
        int rch = at + (1 << (D-dep-1));
        que.push({lch, dep+1}); que.push({rch, dep+1});
    }
}

int main() {
    tree[0] = {0, 1}; tree[1 << D] = {1, 0}; // initial
    int root = 1 << (D-1);
    build(root, 1);
    trav(root);
    return 0;
}