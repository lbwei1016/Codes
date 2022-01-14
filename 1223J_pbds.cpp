/*
***逆序數對***
    Solution:
        用 __gnu_pbds::tree 實作，主要使用到 "order_of_key()"。
        order_of_key(k):
            Return the number of items in a set that are strictly smaller than k.
*/
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

template<typename K, typename M = null_type>
using _set = tree<K, M, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int n;

int inv(vector<int> &v) {
    _set<int> S(v.begin(), v.end());
    int sum = 0;
    for (int i=n-1; i>=0; --i) {
        sum += S.order_of_key(v[i]); 
        S.erase(v[i]);
    }
    return sum % 2;
}
int main() {
    cin >> n;
    vector<int> v1(n), v2(n);
    for (auto &x: v1) cin >> x;
    for (auto &x: v2) cin >> x;

    if (inv(v1) == inv(v2)) cout << "Possible\n";
    else cout << "Impossible\n";
    return 0;
}