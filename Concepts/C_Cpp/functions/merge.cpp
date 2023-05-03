#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = {1, 3, 6, 7, 5};
    vector<int> v2 = {2, 4, 9, 8, 0};
    vector<int> v_merge(10);

    //elements must be sorted first before merge
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    //merge(first1, last1, first2, last2, result, [comp])
    //use operator< by default
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v_merge.begin());

    //the result is a modified vector sorted in ascending order
    for(auto i: v_merge) {
        cout << i << ' ';
    }
    cout << '\n';

    //Array is okay as well
    /*
        int v1[] = {1, 3, 6, 7, 5};
        int v2[] = {2, 4, 9, 8, 0};
        int v_merge[10];

        //elements must be sorted first before merge
        sort(v1, v1+5);
        sort(v2, v2+5);

        //merge(first1, last1, first2, last2, result, [comp])
        //use operator< by default
        merge(v1, v1+5, v2, v2+5, v_merge);

        //the result is a modified array sorted in ascending order
        for(auto i: v_merge) {
            cout << i << ' ';
        }
        cout << '\n';
    */
    return 0;
}