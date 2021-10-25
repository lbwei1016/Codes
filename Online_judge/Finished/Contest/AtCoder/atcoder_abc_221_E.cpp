/*
***BIT / Modular multiplicative inverse / hashing*** (*)
    Description:
        Given a sequence A = (A1, A2, ... Ak). Find the number of subsequences that 
        follow the constraint below:
            for subsequence A' = (A1', ... Ak')，A1' <= Ak' 
            (only care about the elements at two ends) 
    Solution:
        For 1<=i<j<=N，there are 2^(j-i-1) subsequences s.t. A1'= Ai and Ak' = Aj.
        2^(j-i-1) = 2^(j-1) / 2^i, which means the answer can be expressed as below:
            ans = sum(from j=1 to j=N): Bj * 2^(j-1), where Bj is the sum of 1 / 2^i
            prior to current j. (前綴和的概念，因為前綴的 i (Ai<=Aj) 都可以為答案做出貢獻)
            (前綴和利用 BIT 實現)
        Since it is difficult to manage "1 / 2^i" with decimal numbers, try to manage
        them with the "inverse" on MOD = 998244353.
    Note: (MOD inverse)
        a * b^(-1) * 1 ≡ c mod(p) 
    =>  a * b^(-1) * b^(p-1) ≡ c mod(p) (since gcd(b, p) = 1；Fermat's Little Theorem) 
    =>  a * b^(p-2) ≡ c mod(p)

    => 1 / 2^i = (2^i)^(-1), where b = 2^i
    O(N logN)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e5+5, MOD = 998244353;
int n;
ll bit[N];
vector<ll> A, H; // H is for hashing

void hashing() {
    sort(H.begin(), H.end());
    unique(H.begin(), H.end());
    for(int i=0; i<n; ++i) {
        A[i] = lower_bound(H.begin(), H.end(), A[i])-H.begin()+1;
    }
}
void add(int i, ll x) {
    while(i < N) {
        bit[i] = (bit[i]+x) % MOD;
        i += i&-i;
    }
}
ll query(int i) {
    ll res = 0;
    while(i > 0) {
        res = (res+bit[i]) % MOD;
        i -= i&-i;
    }
    return res;
}
ll pow(ll x, int m) {
    ll res = 1;
    while(m > 0) {
        if(m & 1) res = res * x % MOD;
        x = x * x % MOD;
        m >>= 1;
    }
    return res;
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    A.resize(n); H.resize(n);
    for(int i=0; i<n; ++i) {
        cin >> A[i];
        H[i] = A[i];
    }
    hashing();
    ll res = 0, inv = pow(2LL, MOD-2);
    for(int i=0; i<n; ++i) {
        // pow(2LL, "i") since 2^(j-1). (there is a "-1")
        res = (res + query(A[i])*pow(2LL, i)) % MOD;
        add(A[i], pow(inv, i+1)); // i+1 since 1<=i<j<=N
    }
    cout << res << '\n';
    return 0;
}