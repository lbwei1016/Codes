#include <bits/stdc++.h>
using namespace std;

template<class T>
class Cool {
    public:
        // similar to "Cool() {}", but actually quite complicated
        // Cool() = default; 

        Cool() {
            cout << "Cool()\n";
        }
        // destructor should better be "virtual", or "leak" may happen 
        // (when using pointer of "base" class pointing to "derived" class)
        virtual ~Cool() {
            cout << "~Cool()\n";
        }

        // pure virtual function;
        // a class with at least one pure vir. func. is an "abstract class"
        // derived class(es) must implement all "pure virtual functions", or compilation error will occur
        virtual void pureVir() = 0;  

        virtual void Vir() {} // "not pure" virtual func.
        void ordin() {} // ordinary member function

    protected:
        int a; 
        int *arr;
};

// "Cool" is class template; "Cool<int>" is class
// publicly inherit from base class "Cool<T>"
template<class T>
class Nice: public Cool<T> {
    public: 
        // Nice(): a(0) {} // error: "a" is not Nice's member variable, cannot be init. like this
        Nice() {
            // "a" can only be accessed by "this->a", for "Cool" is a "class template"
            this->a = 0; 
            cout << "Nice()\n";
        }
        ~Nice() {
            cout << "~Nice()\n";
        }
        void pureVir() {
            cout << "Pure virtual function\n";
        }
};

int main() {
    // both constructors will be called
    Nice<int> *N = new Nice<int>();

    // both destructors will be called
    delete N; 
    return 0;
}