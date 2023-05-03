/*
    A nice references: 
        http://c-faq.com/decl/spiral.anderson.html
        https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 10, b = 20;
    const int *ptr1; // "pointer to const int", which is equal to "int const *ptr1"
    ptr1 = &a;
    // *ptr = 10; error
    ptr1 = &b;

    int* const ptr2 = &a; // "const pointer to int"
    *ptr2 = 200;
    // ptr2 = &b; error
    return 0;
}