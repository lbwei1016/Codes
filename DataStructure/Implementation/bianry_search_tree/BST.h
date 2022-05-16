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
        virtual void erase(BST *par, int key);
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

void BST::erase(BST *par, const int key) {
    if (key < this->data.key) {
        if (this->lch == nullptr) return;
        this->lch->erase(this, key);
    }
    else if (key > this->data.key) {
        if (this->rch == nullptr) return;
        this->rch->erase(this, key);
    }
    else {
        BST *to_erase = nullptr, *root = this;
        // case1: 左右子節點皆存在
        while (root->lch && root->rch) {
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
    }
}