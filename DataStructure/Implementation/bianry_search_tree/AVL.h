#include "BST.h"
class AVL: public BST {
    public:
        node data;
        BST *lch, *rch;
        AVL(): lch(nullptr), rch(nullptr) {
            data = {-1e9, -1e9};
            height = 0;
        }
        AVL(int _key, int _val): lch(nullptr), rch(nullptr) {
            data = {_key, _val};
            height = 0;
        }
        void insert(const int key, const int val);
        void erase(BST *par, int key);

    private:
        int height;
        void update_height();
        void left_rotation();
        void right_rotation();
};

void AVL::update_height() {
    if (this->lch == nullptr && this->rch == nullptr) {
        this->height = 0;
        return;
    }
    if (this->lch != nullptr) this->lch->
}

void AVL::insert(const int key, const int val) {
    this->BST::insert(key, val);
}