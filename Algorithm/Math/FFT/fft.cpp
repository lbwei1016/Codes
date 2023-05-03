/*
***Math*** -- Fast Fourier Transformation (FFT)
    Note:
        這裡的應用是大數乘法 (多項式乘法)。

        使用 FFT 時，我們需要反元素，因此係數必須定義在某 field 上 (像是 \Bbb C)。
    Time Complexity:
        transformation: O(nlogn)
        multiplication: O(n) (point-wise; Hadamard product)
    Reference:
        https://ccjou.wordpress.com/2012/05/25/%E5%BF%AB%E9%80%9F%E5%82%85%E7%AB%8B%E8%91%89%E8%BD%89%E6%8F%9B/
        https://blog.csdn.net/acdreamers/article/details/39005227
        http://sunmoon-template.blogspot.com/2016/04/number-theoretic-transform-ntt.html
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ld PI = acos(-1.0);

string s1, s2; // two large numbers

struct Complex {
    ld rel, img;
    Complex(ld __r = 0.0, ld __i = 0.0): rel(__r), img(__i) {}
    Complex operator+(const Complex &c) {
        return Complex(rel + c.rel, img + c.img);
    }
    Complex operator-(const Complex &c) {
        return Complex(rel - c.rel, img - c.img);
    }
    Complex operator*(const Complex &c) {
        return Complex(rel*c.rel - img*c.img, rel*c.img + img*c.rel);
    }
};

// change some order, making FFT easier to implement
void rader(vector<Complex> &v) {
    int len = v.size();
    int j = len >> 1;
    for (int i=1; i<len-1; ++i) {
        if (i < j) swap(v[i], v[j]);
        int k = len >> 1;
        while (j >= k) {
            j -= k;
            k >>= 1;
        }
        if (j < k) j += k;
    }
}

// If inv = -1: inverse FFT
void FFT (vector<Complex> &F, int inv) {
    int len = F.size();
    rader(F);
    for (int seg=2; seg<=len; seg<<=1) {
        Complex omgn(cos(-inv * 2 * PI / seg), sin(-inv * 2 * PI / seg));
        for (int j=0; j<len; j+=seg) {
            Complex omg(1.0, 0.0);
            for (int k=j; k < j+seg/2; ++k) {
                Complex x = F[k];
                Complex y = omg * F[k + seg / 2];
                F[k] = x + y;
                F[k + seg / 2] = x - y;
                omg = omg * omgn;
            }
        }
    }
    if (inv == -1) {
        for (int i=0; i<len; ++i) 
            F[i].rel /= len;
    }
}

void convolution(vector<Complex> &a, vector<Complex> &b) {
    FFT(a, 1); FFT(b, 1);
    for (int i=0; i<a.size(); ++i) 
        a[i] = a[i] * b[i];
    FFT(a, -1); // "a" stores the product
}

void solve() {
    cin >> s1 >> s2;
    int len = 1, mx = max(s1.size(), s2.size());
    // "len" is a power of 2!
    while (len < (mx << 1)) len <<= 1;
    vector<Complex> p1(len), p2(len);

    for (int i=0; i<s1.size(); ++i) {
        p1[i] = Complex(s1[s1.size() - i - 1] - '0', 0.0);
    }
    for (int i=0; i<s2.size(); ++i) {
        p2[i] = Complex(s2[s2.size() - i - 1] - '0', 0.0);
    }

    convolution(p1, p2);
    vector<int> res(len + 1);
    for (int i=0; i<len; ++i) 
        res[i] = p1[i].rel + 0.5;

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}