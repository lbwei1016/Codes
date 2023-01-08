// #include "BST.h"
#ifndef MAX
    #define MAX
    #define max(x, y) ((x)>(y)?(x):(y))
#endif

class AVL {
    protected:
        struct node {
            int key, val;
            node() {}
            node(int _key, int _val): key(_key), val(_val) {}
        };
    public:
        node data;
        AVL *lch, *rch;
        AVL(): lch(nullptr), rch(nullptr) {
            data = {(int)1e9, (int)1e9};
            height = 0;
        }
        AVL(int _key, int _val): lch(nullptr), rch(nullptr) {
            data = {_key, _val};
            height = 0;
        }
        void insert(const int key, const int val);
        static AVL* erase(AVL *at, const int &key);

    private:
        int height;
        static int get_height(AVL *at);
        bool rotation(); // also update height
        void left_rotation();
        void right_rotation();
        AVL* find_max();
};

int AVL::get_height(AVL *at) {
    if (at == nullptr) return -1;
    else return at->height;
}

bool AVL::rotation() {
    int lh = get_height(this->lch);
    int rh = get_height(this->rch);
    if (lh - rh > 1 || lh - rh < -1) {
        if (lh > rh) {
            if (get_height(this->lch->lch) > get_height(this->lch->rch)) {
                this->right_rotation();
            }
            else {
                this->lch->left_rotation();
                this->right_rotation();
            }
        }
        else {
            if (get_height(this->rch->rch) > get_height(this->rch->lch)) {
                this->left_rotation();
            }
            else {
                this->rch->right_rotation();
                this->left_rotation();
            }
        }
        this->lch->height = max(get_height(this->lch->lch), get_height(this->lch->rch)) + 1;
        this->rch->height = max(get_height(this->rch->lch), get_height(this->rch->rch)) + 1;
        this->height = max(get_height(this->lch), get_height(this->rch)) + 1;
        return true;
    }
    this->height = max(get_height(this->lch), get_height(this->rch)) + 1;
    return false;
}

void AVL::left_rotation() {
    AVL *tmp = this->rch->rch;
    node tmpdata = this->data;    
    this->data = this->rch->data;
    this->rch->data = tmpdata;

    this->rch->rch = this->rch->lch;
    this->rch->lch = this->lch;

    this->lch = this->rch;
    this->rch = tmp;
}

void AVL::right_rotation() {
    AVL *tmp = this->lch->lch;
    node tmpdata = this->data;
    this->data = this->lch->data;
    this->lch->data = tmpdata;

    this->lch->lch = this->lch->rch;
    this->lch->rch = this->rch;

    this->rch = this->lch;
    this->lch = tmp;
}

AVL* AVL::find_max() {
    AVL *to_erase = this;
    if (this->rch != nullptr) {
        to_erase = this->rch->find_max();
        if (to_erase == this->rch) 
            this->rch->height -= 1;

        bool rotated = this->rotation();
        if (rotated && to_erase == this->rch)
            to_erase = this->rch;
    }
    return to_erase;
}

void AVL::insert(const int key, const int val) {
    if (key < this->data.key) {
        if (this->lch == nullptr) 
            this->lch = new AVL(key, val);
        else this->lch->insert(key, val);
    }
    else {
        if (this->rch == nullptr) 
            this->rch = new AVL(key, val);
        else this->rch->insert(key, val);
    }

    this->rotation();
}

AVL* AVL::erase(AVL* at, const int &key) {
    if (at == nullptr) return at;

    if (key < at->data.key)
        at->lch = erase(at->lch, key);
    else if (key > at->data.key) 
        at->rch = erase(at->rch, key);
    else {
        if (at->lch != nullptr && at->rch != nullptr) {
            // 找左子樹的最大值 (successor)
            AVL *left_max = at->lch->find_max();
            at->data = left_max->data;
            at->lch = erase(at->lch, left_max->data.key);
        }
        else {
            AVL *tmp = nullptr;
            if (at->lch == nullptr) tmp = at->rch;
            else if (at->rch == nullptr) tmp = at->lch;

            delete at;
            return tmp;
        }
    }
    at->rotation();
    return at;
}