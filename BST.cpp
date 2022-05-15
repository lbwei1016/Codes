#include <bits/stdc++.h>
using namespace std;

class BST {
    private:
        struct node {
            int key, val;
            node(int _k, int _v): key(_k), val(_v) {}
        };

    public:
        node *cur;
        BST *lch, *rch;
        BST(): lch(nullptr), rch(nullptr) {
            cur = new node(-1e9, -1e9);
        }
        BST(const int &_k, const int &_v) {
            cur = new node(_k, _v);
            lch = rch = nullptr;
        }
        ~BST() {
            delete cur;
        }
        void insert(const int key, const int val);
        static bool erase(BST *cur, const int key);
};

void BST::insert(const int key, const int val) {
    if (key < this->cur->key) {
        if (this->lch == nullptr) {
            this->lch = new BST(key, val);
            return;
        }
        this->lch->insert(key, val);
    }
    else {
        if (this->rch == nullptr) {
            this->rch = new BST(key, val);
            return;
        }
        this->rch->insert(key, val);
    }
}

bool BST::erase(BST *root, const int key) {
    while (true) {
        BST *tmp;
        if (key < root->cur->key) {
            if (root->lch == nullptr) {
                return false;
            }
            tmp = root;
            root = root->lch;
        }
        else if (key > root->cur->key) {
            if (root->rch == nullptr) {
                return false;
            }
            tmp = root;
            root = root->rch;
        }
        else {
            while (root->lch != nullptr) {
                swap(root->cur, root->lch->cur);
                tmp = root;
                root = root->lch;
            }
            tmp->lch = nullptr;
            
            if (root->rch != nullptr) {
                node *to_append = root->rch->cur;
                while (true) {
                    if (to_append->key < tmp->cur->key) {
                        if (tmp->lch == nullptr) {
                            tmp->lch = root->rch;
                            break;
                        }
                        else tmp = tmp->lch;
                    }
                    else {
                        if (tmp->rch == nullptr) {
                            tmp->rch = root->rch;
                            break;
                        }
                        else tmp = tmp->rch;
                    }
                }
            }
            delete root;
            return true;
        }
    }
}

void print(BST *root) {
    if (root == nullptr) return;
    print(root->lch);
    printf("key: %d; val: %d\n", root->cur->key, root->cur->val);
    print(root->rch);
}

int main() {
    BST *root = new BST;
    vector<int> v = {10, 4, 30, 29, 31, -1, 3, 2, 6, 5};
    for (auto x: v) {
        root->insert(x, x);
    }
    print(root);
    BST::erase(root, 10);
    puts("--------------------------------");
    print(root);
    return 0;
}