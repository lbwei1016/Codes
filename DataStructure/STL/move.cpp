#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct A {
    int val;
    A(): val(0) {
        cout << "Constructed!\n";
    }
    ~A() {
        cout << "Destructed!\n";
    }
};

int main() {
    vector<A> v1(3);
    // std::move() prevents additional destructor called
    auto v2 = std::move(v1);
    // auto v2 = v1; // copying, destructor will be called

    cout << "Print v1:\n";
    for (auto &x: v1) cout << x.val << '\n'; // now v1 is "empty"
    cout << "Print v2:\n";
    for (auto &x: v2) cout << x.val << '\n';
    return 0;
}