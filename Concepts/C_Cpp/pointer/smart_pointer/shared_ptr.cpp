#include <iostream>
#include <memory>
#include "SharedPtr.hpp"
using namespace std;

class A {
public:
    int a;
    A() {
        cout << "defalult called!\n";
    }
    A(int _a): A() {
        a = _a;
        cout << "with param. called!\n";
    }
};

int main() {
    // "shared_ptr" is in <memory>
    // initialize
    shared_ptr<int> p1(new int(30));
    shared_ptr<int> p2 = make_shared<int>(30);
    auto p3 = p1;
    // use_count() returns "reference count" (同一資源被多少 ptr 同時指向)
    cout << p3.use_count() << '\n'; // 2

    // user-defined shared pointer
    SharedPtr<A> pa(new A(10));
    cout << pa->a << '\n'; // 10
    auto pb = pa;
    cout << pb->a << ' ' << pb.use_count() << '\n'; // 10 2
    pb.~SharedPtr(); // destroy
    cout << pa.use_count() << '\n'; // 1  
    return 0;
}