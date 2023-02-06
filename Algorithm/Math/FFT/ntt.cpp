/*
***Math*** -- Number Theoretic Transformation (NTT)
    Note:
        這裡的應用是大數乘法。在整數體下的 FFT；見 ./fft.cpp
        注意 P 的值要夠大!!!
    Time Complexity:
        transformation: O(nlogn)
        multiplication: O(n) (point-wise)
    Reference:
        https://blog.csdn.net/acdreamers/article/details/39005227
        http://sunmoon-template.blogspot.com/2016/04/number-theoretic-transform-ntt.html
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int POW = 23; // N = 1 << POW (多項式長度)
const int P = (15 << 27) + 1;
const int G = 31; // generator (primitive root)

vector<ll> omgn(POW + 1);
string s1, s2;

ll fpow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= x;
            res %= P;
        }
        x *= x;
        x %= P;
        n >>= 1;
    }
    return res;
}

void getOmgn() {
    for (int i=0; i<=POW; ++i) {
        int t = 1 << i;
        omgn[i] = fpow(G, (P-1) / t);
    }
}

void rader(vector<ll> &F) {
    int len = F.size();
    int j = len >> 1;
    for (int i=1; i<len-1; ++i) {
        if (i < j) swap(F[i], F[j]);
        int k = len >> 1;
        while (j >= k) {
            j -= k;
            k >>= 1;
        }
        if (j < k) j += k;
    }
}

void NTT(vector<ll> &F, int inv) {
    rader(F);
    int len = F.size(), at = 1;
    for (int seg=2; seg<=len; seg<<=1, ++at) {
        for (int i=0; i<len; i+=seg) {
            ll omg = 1;
            for (int j=i; j<i+seg/2; ++j) {
                ll u = F[j] % P;
                ll t = omg * F[j + seg/2] % P;
                F[j] = (u + t) % P;
                F[j + seg/2] = (u - t + P) % P;
                omg = omg * omgn[at] % P;
            }
        }
    }
    if (inv == -1) {
        for (int i=1; i<len/2; ++i) 
            swap(F[i], F[len - i]);
        ll inv = fpow(len, P - 2);
        for (int i=0; i<len; ++i) 
            F[i] = F[i] * inv % P;
    }
}

void convolution(vector<ll> &a, vector<ll> &b) {
    NTT(a, 1); NTT(b, 1);
    for (int i=0; i<a.size(); ++i)
        a[i] = a[i] * b[i] % P;
    NTT(a, -1);
}

void solve() {
    cin >> s1 >> s2;
    int len = 1, mx = max(s1.size(), s2.size());
    while (len < (mx << 1)) len <<= 1;
    // cout << len << '\n';
    vector<ll> p1(len), p2(len);

    for (int i=0; i<s1.size(); ++i) {
        p1[i] = s1[s1.size() - i - 1] - '0';
    }
    for (int i=0; i<s2.size(); ++i) {
        p2[i] = s2[s2.size() - i - 1] - '0';
    }

    convolution(p1, p2);
    vector<ll> res(p1);

    for (int i=0; i<len; ++i) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
    auto it = res.rbegin();
    while (*it == 0) ++it;
    for (; it!=res.rend(); ++it) cout << *it;
    cout << '\n';
}

int main() {
    io;
    getOmgn();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}