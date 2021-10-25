/*
***Math*** -- Chinese Remainder Theorem
    Description:
        給定一元線性同餘方程組:
            { x ≡ a1 (mod m1)
            { x ≡ a2 (mod m2)
            {  ......
            { x ≡ an (mod mn)
        求出 x；事實上 x mod (m1*m2*....mn) 是最小的解。

        假定 m1, m2, ...兩兩互質，則任意的 ai 可以使方程組有解。
    Solution:
        令 M = m1*m2*...mn, Mi = M / mi。
        已知對於任意 i, j (i != j)，mi 與 mj 互質，因此 gcd(Mi, mi) = 1。
        又令 ti*Mi ≡ 1 (mod mi)，即 ti 為 Mi 模 mi 的乘法反元素。
        則方程組的通解為: 
            x = a1*t1*M1 + a2*t2*M2 + ... an*tn*Mn + k*M
              = ∑(ai*ti*Mi) + k*M
        因此 x mod M 可以得到最小解。
    Proof:
        見維基百科: 
            https://zh.wikipedia.org/wiki/%E4%B8%AD%E5%9B%BD%E5%89%A9%E4%BD%99%E5%AE%9A%E7%90%86
    O(n logn)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 用此找出模逆元 (modular multiplicative inverse)
ll extgcd(ll a, ll b, ll &x, ll &y) {
    int d = a;
    if(b != 0) {
        d = extgcd(b, a%b, y, x);
        y -= x*(a/b);
    }
    else {
        x = 1, y = 0;
    }
    return d;
}
ll chinese_remainder_theorem(int n, ll M, ll a[], ll m[]) {
    // 為了使求出的解最小而 mod M
    ll res = 0, x = 0, y = 0;
    for(int i=0; i<n; ++i) {
        ll Mi = M / m[i];
        extgcd(Mi, m[i], x, y); // 求模逆元
        res = (res + a[i]*Mi*x % M) % M;
    }
    return (res+M) % M; // 為了讓結果為正
}
int main() {
    int n; // 方程式數量
    ll a[100], m[100], M = 1;
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> a[i] >> m[i];
        M *= m[i];
    }
    cout << chinese_remainder_theorem(n, M, a, m) << '\n';
    return 0;
}
/* 
test case:
    3
    2 3
    3 5
    2 7
ans: 23 (韓信點兵)
*/