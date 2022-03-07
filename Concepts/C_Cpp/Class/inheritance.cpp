#include <bits/stdc++.h>
using namespace std;

class Animal {
    public:
        Animal(string name_): name(name_) {}
        string name;
        void say_hello() { cout << name + " says hi!\n"; }
};

// pubilcly inheritance (check "./inheritance_modifier.png")
class Chicken: public Animal {
    public:
        Chicken(string name_): Animal(name_) {}
        // override
        void say_hello() { cout << name + " GERRR\n"; }
};

int main() {
    Animal ani("anii");
    ani.say_hello();
    Chicken ch1("turk");
    ch1.say_hello();
    
    return 0;
}