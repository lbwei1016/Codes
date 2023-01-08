//next_permutation: 依字典順序 (小到大)列舉所有狀態(共n!個狀態)
//利用原陣列進行操作
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    clock_t s, e;
    vector<int> v = {0, 2, 1, 3, 4, 5};
    // to ensure full permutation, sort first
    sort(v.begin(), v.end());
    int cnt = 0;
    s = clock();
    do
    {
        for(int i : v)
            cout << i << ' ';
        cout << '\n';
        cnt++;
    } while(next_permutation(v.begin(), v.end())); // increase lexicographically
    e = clock();
    cout << "n! = " << cnt << '\n';
    cout << "Time spent: " << e-s << " ms\n";

    reverse(v.begin(), v.end());
    do {
        for(int i : v)
            cout << i << ' ';
        cout << '\n';
    } while(prev_permutation(v.begin(), v.end())); // decrease lexicographically
    
    return 0;
}