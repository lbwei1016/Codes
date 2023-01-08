#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    // io;
    set<int> S = {2, 3, 7, 8}, pre = {2, 6, 7, 9};
    set<int> diff;
    set_difference(S.begin(), S.end(), pre.begin(), pre.end(), inserter(diff, diff.begin()));
    for (auto x: diff) cout << x;
    return 0;
}