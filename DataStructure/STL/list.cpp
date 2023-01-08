#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main() {
    list<int> ls; // constructor(size, val)
    auto it = ls.begin();
    /*
        insert(iter pos, val): 
            Insert "val" at "pos", returning an iterator pointing to 
            the first inserted element.
    */
    for(int i=0; i<5; ++i) it = ls.insert(it, i);
    cout << *it << '\n';
    ls.insert(ls.begin(), 100);
    cout << *ls.begin() << '\n';

    /*
        next(iter pos, num):
            Return an iterator to the element n positions 
            away from "pos".
        note: num by default is "1"
    */
    it = next(ls.begin(), 1); // <iterator>
    cout << *it << '\n';
    for(auto x : ls) cout << x << ' ';
    cout << '\n';

    /*
        erase(iter pos):
            Return an iterator pointing to the element that followed the 
            last element erased by the function call.
    */
    it = ls.erase(ls.begin());
    cout << *it << '\n';

    it = next(ls.begin(), 10000); // out of range, undefined behavior ?
    if(it == ls.end()) cout << "End reached!\n";
    else cout << *it << '\n';
    return 0;
}