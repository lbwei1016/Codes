/*
***Math*** -- prime
    Note:
        首先，這是一個隨機化演算法，並無法保證結果為真；但經過測試，
        若要判斷的數 n 在 32-bit 的範圍內，可以經由三次分別以 2, 7, 61 
        為底 (a) 的測試來確保結果正確，即當三次測試都通過時，該數就是質數。
    Description:
        利用質數性質:
            1.  當 p 為質數，且 gcd(a, p) = 1，則 a^(p-1) ≡ 1(mod p) (費馬小定理，逆定理未必成立)
            2.  當 p 為質數，x^2 ≡ 1(mod p) 的解為: x ≡ 1(mod p) 或 x ≡ p-1(mod p) (逆定理未必成立)
        利用以上兩點性質，對於要驗證的數 n，先將其轉化成 n-1 = u*2^t 的形式；"n-1"
        是為了對應性質1.的 "(p-1)"，"u*2^t" 是為了對應性質2.的 "x^2"。

        首先求出 a^u，判斷其是否符合性質2.，若符合，則因為 a^(n-1) = a^(u*2^t)，即
        a^(n-1) 是 a^u 自乘數次後的某個平方，依照性質2.不斷回推，即可能滿足性質1.，
        因此直接判斷其為質數。若不符合，逐次乘上自己，並進行前述的判斷，惟此處若 
        a^(u*2^r) ≡ 1(mod n)，反而要判斷其為非；因為如果 "a^(u*2^r) ≡ 1(mod n)"，
        但是 a^(u*2^("r-1")) ≡ 1(mod n) 和 a^(u*2^("r-1")) ≡ n-1(mod n) 都不成立
        的話，那性質2.根本不成立，哪裡還需要再做逆定理回推呢 ?
        (u 是奇數)

        Miller-Rabin test 的機率性來自於 base 'a' 的選擇。
    O(log n)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; // 要 long long 才不會 overflow!!!

ll pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
// n: a number to be tested；a: a random base
bool miller_rabin(ll n, ll a) {
    if (n < 3 || !(n & 1)) return n == 2; // 先去掉偶數
    if (n == a) return true; // 幫忙測試的底數 a 選的都是質數，要先判斷

    int u = n - 1, t = 0;
    for (; !(u & 1); u >>= 1, ++t);
    a = pow(a, u, n);
    if (a == 1 || a == n-1) return true;
    for (int i=0; i<t; ++i) {
        a = a * a % n;
        if (a == 1) return false; // 注意!!!
        else if (a == n-1) return true;
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    if (miller_rabin(n, 2) && miller_rabin(n, 7) && miller_rabin(n, 61))
        cout << "n: " << n << " is a prime\n";
    else cout << "n: " << n << " is \"not\" a prime\n";
    // for(int i=0; i<1e5; ++i) {
    //     if(miller_rabin(i, 2) && miller_rabin(i, 7) && miller_rabin(i, 61))
    //         printf("%d\n", i);
    // }
    return 0;
}