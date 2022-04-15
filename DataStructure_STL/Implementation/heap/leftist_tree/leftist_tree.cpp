/*
***leftist tree (heap)***
    Description:
        With all features an average heap has, two leftist trees can be "merged" 
        in O(log n).
*/
#include <bits/stdc++.h>
using namespace std;

// min heap
class leftist {
    public:
        // constructor for external node
        leftist (int _val, int _sval): val(_val), sval(_sval), lch(nullptr), rch(nullptr) {}
        leftist(int _val): val(_val), sval(1) {
            // generate external node
            lch = new leftist(-1, 0);
            rch = new leftist(-1, 0);
        }
        // build a leftist tree with scattered nodes; O(n)
        static leftist* build(queue<leftist*> &nodes);

        // key function, meld two leftist trees; O(log n)
        leftist* meld(leftist *t2);
        leftist* push(leftist* t);
        leftist* pop() const;
        int top() const;

        // to traverse
        void inorder() const;
        void level_order() const;
    private:
        int val, sval;
        leftist *lch, *rch;
};

int main() {
    queue<leftist*> nodes;
    vector<int> v = {7, 1, 2, 4, 8, 3, 6, 10};
    for (int i=0; i<v.size(); ++i) {
        nodes.push(new leftist(v[i]));
    }
    auto root = leftist::build(nodes);
    root->inorder(); cout << '\n';

    root = root->push(new leftist(9));
    root->inorder(); cout << '\n';

    root = root->pop();
    root->inorder(); cout << '\n';
    return 0;
}

leftist* leftist::build(queue<leftist*> &nodes) {
    // pop two nodes and melds them, and then push the melded tree back to the queue
    // until there's only one node left, which is root
    while (nodes.size() > 1) {
        auto t1 = nodes.front(); nodes.pop();
        auto t2 = nodes.front(); nodes.pop();
        nodes.push(t1->meld(t2));
    }
    return nodes.front();
}

leftist* leftist::meld(leftist *t2) {
    leftist* t1 = this;
    stack<leftist*> subtrees;
    while (t1->sval && t2->sval) {
        if (t1->val < t2->val) {
            subtrees.push(t1);
            t1 = t1->rch;
        }
        else {
            subtrees.push(t2);
            t2 = t2->rch;
        }
    }
    leftist *node = t1->sval ? t1 : t2;
    while (subtrees.size()) {
        auto sub = subtrees.top(); subtrees.pop();
        sub->rch = node;
        // the s-value of right subtree must not not be larger than that of left subtree
        if (sub->lch->sval < sub->rch->sval) {
            swap(sub->lch, sub->rch);
        }
        // update s-value
        sub->sval = min(sub->lch->sval, sub->rch->sval) + 1;
        node = sub;
    }
    return node;
}

leftist* leftist::push(leftist* t) { 
    return this->meld(t); 
}

leftist* leftist::pop() const {
    leftist node = *this;
    delete this;
    return node.lch->meld(node.rch);
}

int leftist::top() const {
    return this->val;
}

void leftist::inorder() const {
    cout << this->val << ' ';
    if (this->lch->sval) this->lch->inorder();
    if (this->rch->sval) this->rch->inorder();
}

void leftist::level_order() const {
    queue<pair<const leftist*, int> > que;
    que.push(make_pair(this, 0));
    int pre = 0;
    while (que.size()) {
        auto p = que.front(); que.pop();
        if (p.second > pre) cout << '\n';
        cout << p.first->val << ' ';
        if (p.first->lch->sval)
            que.push(make_pair(p.first->lch, p.second+1));
        if (p.first->rch->sval)
            que.push(make_pair(p.first->rch, p.second+1));
        pre = p.second;
    }
    cout << "\n----------------\n\n";
}