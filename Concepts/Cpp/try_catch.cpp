#include <iostream>
#include <exception>
using namespace std;

int main() {
    string s = "aa";
    try {
        cout << s.at(2);
    } catch (const exception &e) { 
        // catches everything (out_of_range actually)
        /*
            exception should be caught by reference 
            (capturing by reference, captures all related classes)
        */
        cout << "error\n" << e.what();
    }
    cout << __cplusplus << '\n'; // cool
    return 0;
}