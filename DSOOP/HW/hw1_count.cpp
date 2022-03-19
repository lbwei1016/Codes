#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // a[0]: three times
    int a[] = {2, 4, 0, -1, 392, 34, 2, 3, 4, 6, 10, 3, 2, 999};
    cout << count(a, a + sizeof(a)/sizeof(int), a[0]) << '\n';
    return 0;
}