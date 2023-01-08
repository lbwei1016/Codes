#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

class A {
    public:
        int a1, a2;
};

class B {
    public:
        int b1, b2;
        B(const A &_a): b1(_a.a1), b2(_a.a2) {}
        B(int _b1, int _b2): b1(_b1), b2(_b2)  {}
        explicit B(int _b): b1(_b), b2(_b) {} // no implicit conversion with "a single int"
        operator A() {
            return {b1+1, b2+1};
        }
};

int main() {
    B bb = A{10, 20}; // explicit conversion (constructor) ("copy initialization")
    cout << bb.b1 << bb.b2 << '\n';
    A aa = bb; // implicit conversion from B tp A (operator A()) ("copy initialization")
    cout << aa.a1 << aa.a2 << '\n';

    B bb0 = {1, 2};
    // B bb1 = 3; error, since "explicit" is decorated before "B(int _b)", and hence no "copy initialization"
    B bb2(3);
    B bb3 = static_cast<B>(3); // OK: static_cast performs "direct-initialization"
    return 0;
}