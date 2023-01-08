#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    // Create a range of sequentially increasing values. 
    // For each element in the range [first,last) assigns 
    // value and increments value as if by ++value.
    vector<int> v(10);
    iota(v.begin(), v.end(), 0); // fill v with 0,1,...,9
    for (auto x: v) cout << x << '\n';
    return 0;
}