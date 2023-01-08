#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    forward_list<int> fls(10, 0);
    auto it = fls.begin();
    /*
        insert_after(iter pos, val):
            Insert "val" aftre "pos"；hence "fls" should
            not be empty.
    */
    fls.insert_after(it, 1); ++it;
    cout << *it << '\n';
    fls.erase_after(fls.begin());
    for(auto x : fls) cout << x << ' ';
    cout << '\n';
    return 0;
}