#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    //use built-in randomness¡Fwe can also designate our own random function
    random_shuffle(v.begin(), v.end()); 
    for(auto i : v) cout << i << ' ';
    return 0;
}