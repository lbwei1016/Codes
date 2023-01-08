/*
排序左界，從後面更新；概念和用 BIT 求區間和相同
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100+5;

int bit[N], n;

void update(int i, int val) {
    while (i <= n) {
        bit[i] = __gcd(bit[i], val);
        i += (i & -i);
    }
}

int query(int i) {
    int res = 0;
    while (i > 0) {
        res = __gcd(res, bit[i]);
        i -= (i & -i);
    }
    return res;
}

int main() {
    n = 6;
    vector<int> arr = {0, 72, 16, 48, 20, 7, 12};
    // for (int i=1; i<=n; ++i) {
    //     update(i, arr[i]);
    // }
    // for (int i=1; i<=n; ++i) {
    //     printf("gcd for prefix %d: %d\n", i, query(i));
    // }
    
    reverse(arr.begin(), arr.end());
    // off-line query for "range gcd"
    // 排序左界，從後面更新；概念和用 BIT 求區間和相同
    for (int i=n; i>=1; --i) {
        update(i, arr[i]);
        printf("%d\n", query(n));
    }
    return 0;
}