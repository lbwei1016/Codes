#include <bits/stdc++.h>
using namespace std;

class B {
    public:
        void print(int n) {
            cout << n << '\n';
        }
};

class D: public B {
    public:
        void print(string s) {
            cout << s+'\n';
        } 
        // void print(int n) {
        //     cout << n << '\n';
        // }
};

int main() {
    B *ptr = new D();
    // ptr->print("opo"); // error
    ptr->print(12);
    D *ptrr = new D();
    // ptrr->print(12); // error if print() is not overloaded in D
    ptrr->print("odfpsf");
    return 0;
}