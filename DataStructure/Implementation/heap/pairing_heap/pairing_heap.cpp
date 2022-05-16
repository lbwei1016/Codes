/*
***Heap*** -- pairing heap
    Description:
        類似 Fibonacci heap、靈感得自 splay tree 的 heap。
        有著很好的 amortized time complexity，而且實作較簡單(?)。
        實測效率甚至比 Fibonacci heap 好 (如: Dijkstra, Prim)。
    Time Complexity (amortized):
        merge: O(log n) (O(1))
        insert: O(1)
        pop: O(log n)

        See: https://brilliant.org/wiki/pairing-heap/
*/
#include <bits/stdc++.h>
using namespace std;

class pairing_heap {
    private:
        struct node {
            int key, val;
        };
        void merge(pairing_heap *h2);
    public:
        node data;
        pairing_heap *chl, *sib;

        pairing_heap(): chl(nullptr), sib(nullptr) {
            data.key = data.val = 1e9; // intial root value, should be omitted
        }
        pairing_heap(int _key, int _val): chl(nullptr), sib(nullptr) {
            data.key = _key;
            data.val = _val;
        }
        void insert(int key, int val);
        void pop();
        int top();
};

// after merge, "this" would still point to the root
void pairing_heap::merge(pairing_heap *h2) {
    if (this->data.key > h2->data.val) {
        swap(this->data, h2->data);
        swap(this->chl, h2->chl);
        swap(this->sib, h2->sib);
    }
    /*         
        Root's child pointer will point to h2, and h2's sibling pointer
        will point to root's initial child.
    */
    pairing_heap *tmp_chl = this->chl, *tmp_sib = h2->sib;
    this->chl = h2;
    if (tmp_chl != nullptr) {
        h2->sib = tmp_chl; 
        if (tmp_sib != nullptr) tmp_chl->sib = tmp_sib;
    }
}

void pairing_heap::insert(int key ,int val) {
    pairing_heap *to_insert = new pairing_heap(key, val);
    this->merge(to_insert);
}

void pairing_heap::pop() {
    deque<pairing_heap*> heaps;
    pairing_heap *at = this;
    
    at = at->chl; // a root doesn't have any sibling
    // all children of root should be merged later
    while (at != nullptr) {
        heaps.push_back(at);
        auto *tmp = at;
        tmp = at;
        at = at->sib;
        tmp->sib = nullptr;
    } 

    pairing_heap *last = nullptr;
    if (heaps.size() & 1) {
        last = heaps.back();
        heaps.pop_back();
    }
    // two-pass merge
    // first pass: take pairs from left to right, merge
    for (int i=0; i<heaps.size(); i+=2) {
        auto h1 = heaps.front(); heaps.pop_front();
        auto h2 = heaps.front(); heaps.pop_front();
        h1->merge(h2);
        heaps.push_back(h1);
    }
    if (last != nullptr) heaps.push_back(last);

    // second pass: merge all other heaps with the rightmost heap
    while (heaps.size() > 1) {
        auto h1 = heaps.back(); heaps.pop_back();
        auto h2 = heaps.back(); heaps.pop_back();
        h1->merge(h2);
        heaps.push_back(h1);
    }
    auto new_root = heaps.front();
    swap(this->data, new_root->data);
    swap(this->chl, new_root->chl);
    swap(this->sib,  new_root->sib);

    delete new_root;
}

int pairing_heap::top() {
    return this->data.val;
}

int main() {
    pairing_heap *root = new pairing_heap;
    vector<int> v = {20, 1, 0, 5, 18, 6, 12, 14, 9, 8, 22};
    for (auto x: v) {
        root->insert(x, x);
    }

    for (int i=0; i<v.size(); ++i) {
        cout << root->top() << '\n';
        root->pop();
    }
    return 0;
}