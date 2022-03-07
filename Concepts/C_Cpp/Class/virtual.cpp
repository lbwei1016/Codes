#include <bits/stdc++.h>
using namespace std;

class Animal {
    public:
        virtual void say() {
            cout << "Animal say~\n";
        }

        void shout() {
            cout << "Animal shout\n";
        }
};

class Cat: public Animal {
    public:
        // say() is already a virtual function, but adding "virtual" can increase readability
        void say() {
            cout << "Cat say~\n";
        }

        void shout() {
            cout << "Cat shout\n";
        }
};

class Kitty: public Cat {
    public:
        void say() {
            cout << "Kitty say~\n";
        }
};

int main() {
    Animal *ap;
    Cat cat;
    ap = &cat;
    ap->say(); // with "virtual", Cat::say() is called (runtime polymorphism)
    ap->shout(); // no virtual, Animal::say() is called

    Cat *cp;
    Kitty kt;
    cp = &kt;
    cp->say(); // virtual
    return 0;
}