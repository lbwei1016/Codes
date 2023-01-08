#include <iostream>
#include <iterator> //std::distance()
#include <algorithm> //std::unique()
#include <vector> 

using namespace std;

bool pred(const int &a, const int &b)
{
    return (a == b);
}
int main()
{
    vector<int> v = {1, 1, 1, 2, 2, 2, 2, 3, 3, 2, 2, 1, 1, 1};
    
    /*
        unique(first, last, pred): 
        Function:
            Removes all but the first element from every consecutive 
            group of equivalent elements in the range [first,last).
        Return:
            An iterator to the element that follows the last element not removed.
            => [first, new_last)
        Note:
            The size of the array(container) isn't altered, while the 
            elements between the returned iterator and last are left in a valid 
            but unspecified state.
    */
    auto last_it = unique(v.begin(), v.end(), pred);

    /*
        distance(first, last):
        Return:
            The number of elements between first and last.
    */
    v.resize(distance(v.begin(), last_it));
    
    for(int i : v)
        cout << i << ' ';
    cout << '\n';
    return 0;
}