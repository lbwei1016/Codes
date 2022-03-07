#include <bits/stdc++.h>
using namespace std;

// Declare "Node" first so that List's function prototype can have a "Node" parameter.
class Node;
class F_Node;

class List {
    public:
        // 成為 friend 之前 prototype 要先出來
        void print_val(Node node);
        void rrr(Node node);
};

class Node {
    private:
        int val;
        Node *nxt;
    public:
        Node(int val_, Node *nxt_ = nullptr): val(val_), nxt(nxt_) {}
        friend void List::print_val(Node); // only the function is granted friendship
        friend class F_Node; // the whole class is granted friendship
};

class F_Node {
    public:
        void print_val(Node node) {
            cout << node.val << '\n';
        }
        void set_val(Node &node, int val) {
            node.val = val;
        }
};

// A function must be declared as "friend" first before it can access "private or protected" members.
// That's why the definition of "print_val()" is below the definition of "Node".
void List::print_val(Node node) {
    cout << node.val << '\n';
}
// not a friend function, error
// void List::rrr(Node node) {
//     cout << node.val << '\n';
// }

int main() {
    Node nod(10);
    List lis;
    F_Node fn;
    
    lis.print_val(nod);
    fn.set_val(nod, 10000);
    fn.print_val(nod);
    return 0;
}