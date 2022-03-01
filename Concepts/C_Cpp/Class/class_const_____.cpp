#include <bits/stdc++.h>
using namespace std;

class MyClass {
    public: 
        // below is a "const overloading"
        void sayHi() {
            ++counter1;
            ++counter2;
            cout << "Hi\n";
        }
        // this is a "const member function", which cannot alter members
        void sayHi() const {
            ++counter1;
            // error
            // ++counter2;
            cout << "Hi\n";
        }
        void Hi_times() {
            cout << "cnt1: " << counter1 << '\n';
            cout << "cnt2: " << counter2 << '\n';
        }
    private:
        mutable int counter1 = 0;
        int counter2 = 0;
};

int main() {
    // non-const object can access both "const" and "non-const" member functions
    MyClass mc1;
    // const object can only access "const" member functions
    const MyClass &mc2 = mc1;
    mc1.sayHi();
    mc2.sayHi(); // const overloading; access "void sayHi() const..."
    mc1.Hi_times();

    return 0;
}