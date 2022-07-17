#include <bits/stdc++.h>
using namespace std;

struct node {
    int key, pri;
    node *l, *r;
};

// merge two treap
node* merge(node *a, node *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->pri > b->pri) {
        a->r = merge(a->r, b);
        return a;
    }
    b->l = merge(a, b->l);
    return b;
}    

// split "at" from value "k" into "a" and "b"
void split(node *at, const int k, node *&a, node *&b) {
    if (!at) a = b = nullptr;
    else if (at->key <= k) {
        a = at;
        split(at->r, k, a->r, b);
    }
    else {
        b = at;
        split(at->l, k, a, b->l);
    }
}

// insert "a" into "at"
void insert(node *at, node *a) {
    node *l, *r;
    // l = r = nullptr;
    split(at, a->key, l, r);
    merge(at, l); merge(at, r);
}

void erase(node *at, const int key) {
    if (at->key == key) {
        node *tmp = at;
        merge(at->l, at->r);
        delete at;
    }
    else {
        if (key > at->key) erase(at->r, key);
        else erase(at->l, key);
    }
}

int main() {

    return 0;
}