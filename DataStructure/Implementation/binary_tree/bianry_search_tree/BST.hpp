class BST {
    protected:
        struct node {
            int key, val;
            node() {}
            node(int _k, int _v): key(_k), val(_v) {}
        };

    public:
        node data;
        BST *lch, *rch;
        BST(): lch(nullptr), rch(nullptr) {
            data = node(-1e9, -1e9);
        }
        BST(const int &_k, const int &_v): lch(nullptr), rch(nullptr) {
            data = node(_k, _v);
        }
        virtual void insert(const int key, const int val);
        virtual void erase(int key);
};

void BST::insert(const int key, const int val) {
    if (key < this->data.key) {
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

// loop 寫法，AVL.h 有更簡潔的遞迴寫法
void BST::erase(int key) {
    BST *at = this, *par = this;
    while (true) {
        if (key < at->data.key) {
            if (at->lch == nullptr) return;
            par = at;
            at = at->lch;
        }
        else if (key > at->data.key) {
            if (at->rch == nullptr) return;
            par = at;
            at = at->rch;
        }
        else {
            BST *to_erase = nullptr, *root = at;
            // case1: 左右子節點皆存在
            if (root->lch && root->rch) {
                par = to_erase = root;
                // 找左子樹中最大的 key，找到之後該 node 即為新的要被 erase 的 node
                // 所以 while loop 繼續
                root = root->lch;
                while (root->rch != nullptr) {
                    par = root;
                    root = root->rch;
                }

                to_erase->data = root->data;
            }
            // case2: 左右子節點僅存在其一
            if (root->lch != nullptr) {
                if (par->lch == root) par->lch = root->lch;
                else par->rch = root->lch;
            }
            else if (root->rch != nullptr) {
                if (par->lch == root) par->lch = root->rch;
                else par->rch = root->rch;
            }
            else {
                // case3: leaf
                if (par->lch == root) par->lch = nullptr;
                else par->rch = nullptr;
            }
            delete root;
            return;
        }
    }
}