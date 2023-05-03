#include <iostream>
#include <memory>
using namespace std;

void function(int a = 0) {
    // hold the name of the current function
    cout << __PRETTY_FUNCTION__ << '\n';
    cout << __func__ << '\n';
}

int main() {
    function();
    return 0;
}