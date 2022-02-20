/*
***Prefix Sum*** 
    Decription:
        See https://atcoder.jp/contests/abc240/tasks/abc240_f
    Solution:
        因為 M 太大 (1e9)，所以無法直接計算前綴和，於是利用前綴和的性質:
            對於數列 <an> 的前 i 項和 Si，如果 a(i+1) > 0，S(i+1) 才會
            大於 Si。
        因此，只要找出 Bi < 0 之處，前 (i-1) 項和就是 B 的最大前綴和候選之一。

    Time Complexity:
        找出 Bi < 0: O(nlogn)
        計算前綴和: O(n)，共 k 次；k 為 Bi < 0 的數量 (上界未知)
        (n <= 2e5)
    Note:
        這題還有更好的解，但這是我自己想出來的。(2022/2/21)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point { int j, k; };

// 找出 Bi < 0 之處
int find_neg(ll x, ll y, ll B) {
    ll lb = 0, ub = y+1;
    while(ub - lb > 1) {
        ll mid = (lb + ub) >> 1;
        if(x*mid + B < 0) ub = mid;
        else lb = mid;
    }
    return lb; 
}

// 計算前綴和
ll total(vector<ll> &B, vector<ll> &x, vector<ll> &y, int j) {
    ll sum = 0;
    while(j > 0) {
        sum += y[j]*B[j] - x[j] * y[j]*(y[j]-1)/2;
        --j;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> x(n+3), y(n+3), B(n+3), y_psum(n+3);
        // 1-indexed 方便很多
        for(int i=1; i<=n; ++i) {
            cin >> x[i] >> y[i];
        }
        // 數量 y 的 prefix sum
        for(int i=1; i<=n; ++i) {
            y_psum[i] = y_psum[i-1] + y[i];
        }

        // 此 B 非題意的 B (連續前綴和)，而是離散化(?)的 B (B[1] = x[1] * y[1] ...)
        for(int i=1; i<=n; ++i) {
            B[i] = B[i-1] + x[i] * y[i];
        }

        // Bi < 0 之處
        vector<point> border;
        for(int i=1; i<n; ++i) {
            if(B[i] >= 0 && B[i+1] < 0) {
                // 找出確切的 "B(k+1) < 0" 的位置 k+1 (因為要大(等)於 0 的，所以實際上是 k)
                int k = find_neg(x[i+1], y[i+1], B[i]) + y_psum[i];
                border.push_back(point{i, k});
            }
        }
        // mx == x[1] 是只選第一項，也就是 A1 的情形
        ll mx = x[1];
        // 加到底
        if(B[n] > 0) mx = max(mx, total(B, x, y, n));

        for(int i=0, len=border.size(); i<len; ++i) {
            int k = border[i].k; // 實際位置
            int j = border[i].j; // 第幾組 (此處 "B" 的離散化單位，即與 x[], y[] 相關)
            int at = y_psum[j]; // 此組實際在的位置
            ll l = k - at; // 多出來的
            mx = max(mx, total(B, x, y, j) + l*B[j] + x[j+1] * l*(l+1)/2);
        }
        cout << mx << '\n';
    }
    return 0;
}
/*
1
6 13
2 3
-6 2 
7 2
-10 3
3 2
100 1
---ans: 28

1
3 7
-1 4
-3 2
-7 1
---ans: -1
*/