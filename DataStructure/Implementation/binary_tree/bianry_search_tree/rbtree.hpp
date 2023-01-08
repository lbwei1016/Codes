class RBtree {
    protected:
        struct Node {
            int key, val;
            bool is_red;
            Node(): key(-1), val(-1), is_red(1) {}
            Node(int _key, int _val, bool _red): key(_key), val(_val), is_red(_red) {}
        };
    public:
        static RBtree *NIL; // sentinel
        Node node;
        RBtree *lch, *rch, *par;
        RBtree() {
            lch = rch = par = NIL;
        }
        RBtree(int _key, int _val, bool _red): node(_key, _val, _red) {
            lch = rch = par = NIL;
        }
        static void insert(RBtree *(&root), const int &key, const int &val);
        static bool erase(RBtree *(&root), const int &key);
    private:
        static void left_rotation(RBtree *(&root), RBtree *at);
        static void right_rotation(RBtree *(&root), RBtree *at);

        static void insert_fixup(RBtree *(&root), RBtree *at);

        RBtree* find(const int &key); // find the node associated with the given key
        static void transplant(RBtree *(&root), RBtree *u, RBtree *v);
        static RBtree* tree_minimum(RBtree *at, RBtree *par);
        static void erase_fixup(RBtree *(&root), RBtree *at);
};

// initialize sentinel (black)
RBtree *RBtree::NIL = new RBtree(0, 0, 0);

void RBtree::left_rotation(RBtree *(&root), RBtree *at) {
    RBtree *Y = at->rch;
    at->rch = Y->lch;
    if (Y->lch != NIL) 
        Y->lch->par = at;
    Y->par = at->par;
    if (at->par == NIL) 
        root = Y;
    else if (at == at->par->lch) 
        at->par->lch = Y;
    else 
        at->par->rch = Y;
    Y->lch = at;
    at->par = Y;
}

void RBtree::right_rotation(RBtree *(&root), RBtree *at) {
    RBtree *Y = at->lch;
    at->lch = Y->rch;
    if (Y->rch != NIL) 
        Y->rch->par = at;
    Y->par = at->par;
    if (at->par == NIL) 
        root = Y;
    else if (at == at->par->rch) 
        at->par->rch = Y;
    else 
        at->par->lch = Y;
    Y->rch = at;
    at->par = Y;
}

// check the case of NIL
void RBtree::insert_fixup(RBtree *(&root), RBtree *at) {
    while (at->par->node.is_red) {
        if (at->par == at->par->par->lch) {
            RBtree *ppr = at->par->par->rch;
            if (ppr->node.is_red) {
                at->par->node.is_red = 0;
                ppr->node.is_red = 0;
                at->par->par->node.is_red = 1;
                at = at->par->par;
            }
            else {
                if (at == at->par->rch) {
                    at = at->par;
                    left_rotation(root, at);
                }
                at->par->node.is_red = 0;
                at->par->par->node.is_red = 1;
                right_rotation(root, at->par->par);
            }
        }
        else {
            RBtree *ppl = at->par->par->lch;
            if (ppl->node.is_red) {
                at->par->node.is_red = 0;
                ppl->node.is_red = 0;
                at->par->par->node.is_red = 1;
                at = at->par->par;
            }
            else {
                if (at == at->par->lch) {
                    at = at->par;
                    right_rotation(root, at);
                }
                at->par->node.is_red = 0;
                at->par->par->node.is_red = 1;
                left_rotation(root, at->par->par);
            }
        }
    }
    root->node.is_red = 0;
}

void RBtree::insert(RBtree *(&root), const int &key, const int &val) {
    RBtree *pre = NIL, *at = root;
    RBtree *X = new RBtree(key, val, 1);
    while (at != NIL) {
        pre = at;
        if (key < at->node.key) at = at->lch;
        else at = at->rch;
    }

    if (pre == NIL) root = X;
    else if (key < pre->node.key) 
        pre->lch = X;
    else pre->rch = X;

    X->par = pre;
    insert_fixup(root, X);
}

RBtree* RBtree::find(const int &key) {
    if (this == NIL || this->node.key == key) 
        return this;
    if (key < this->node.key) 
        return this->lch->find(key);
    else    
        return this->rch->find(key);
}

void RBtree::transplant(RBtree *(&root), RBtree *u, RBtree *v) {
    if (u->par == NIL) 
        root = v;
    else if (u == u->par->lch)
        u->par->lch = v;
    else 
        u->par->rch = v;
    v->par = u->par;
}

RBtree* RBtree::tree_minimum(RBtree *at, RBtree *par) {
    if (at == NIL) 
        return par;
    return tree_minimum(at->lch, at);
}

void RBtree::erase_fixup(RBtree *(&root), RBtree *at) {
    while (at != root && !at->node.is_red) {
        if (at == at->par->lch) {
            RBtree *Y = at->par->rch;
            if (Y->node.is_red) {
                Y->node.is_red = 0;
                at->par->node.is_red = 1;
                left_rotation(root, at->par);
                Y = at->par->rch;
            }
            if (!Y->lch->node.is_red && !Y->rch->node.is_red) {
                Y->node.is_red = 1;
                at = at->par;
            }
            else {
                if (!Y->rch->node.is_red) {
                    Y->lch->node.is_red = 0;
                    Y->node.is_red = 1;
                    right_rotation(root, Y);
                    Y = at->par->rch;
                }
                Y->node.is_red = at->par->node.is_red;
                at->par->node.is_red = 0;
                Y->rch->node.is_red = 0;
                left_rotation(root, at->par);
                at = root;
            }
        }
        else {
            RBtree *Y = at->par->lch;
            if (Y->node.is_red) {
                Y->node.is_red = 0;
                at->par->node.is_red = 1;
                left_rotation(root, at->par);
                Y = at->par->lch;
            }
            if (!Y->lch->node.is_red && !Y->rch->node.is_red) {
                Y->node.is_red = 1;
                at = at->par;
            }
            else {
                if (!Y->lch->node.is_red) {
                    Y->rch->node.is_red = 0;
                    Y->node.is_red = 1;
                    left_rotation(root, Y);
                    Y = at->par->lch;
                }
                Y->node.is_red = at->par->node.is_red;
                at->par->node.is_red = 0;
                Y->lch->node.is_red = 0;
                right_rotation(root, at->par);
                at = root;
            }
        }
    }
    at->node.is_red = 0;
}

bool RBtree::erase(RBtree *(&root), const int &key) {
    RBtree *X = root->find(key);
    if (X == NIL) return false;

    RBtree *Xch = nullptr; // some children of X; maybe not
    RBtree *Y = X;
    bool Y_was_red = Y->node.is_red;

    if (X->lch == NIL) {
        Xch = X->rch;
        transplant(root, X, X->rch);
    }
    else if (X->rch == NIL) {
        Xch = X->lch;
        transplant(root, X, X->lch);
    }
    else {
        Y = tree_minimum(X->rch, X);
        Y_was_red = Y->node.is_red;
        Xch = Y->rch;
        if (Y->par == X) 
            Xch->par = Y;
        else {
            transplant(root, Y, Y->rch);
            Y->rch = X->rch;
            Y->rch->par = Y;
        }
        transplant(root, X, Y);
        Y->lch = X->lch;
        Y->lch->par = Y;
        Y->node.is_red = X->node.is_red;
    }

    if (!Y_was_red) 
        erase_fixup(root, Xch);
    delete X;
    return true;
}