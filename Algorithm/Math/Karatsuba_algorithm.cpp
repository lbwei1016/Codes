/*
***Math / Divide and Conquer***
    Description:
        計算兩 n 次多項式相乘。
        假設 n = 2k-1 (共 2k 項)，可以將原式想成:
            f * g = (f1*x^k + f2) * (g1*x^k + g2) = f1*g1*x^2k + (f1*g2+f2*g1)*x^k + f2*g2
        所以只要算出 f1g1, f1g2, f2g1, f2g2，再合併就可以求出答案。
        但是如果要分成 4 個子狀態分治下去，時間複雜度是:
            T(n) = 4T(n/2) + O(n) = O(n^2)
        和 naive 算法其實一樣，於是需要修正計算: 
            其實只需要計算 (f1+f2)*(g1+g2), f1g1, f2g2，
            再將第一項的結果減去第二第三項，就可以求出 f1g2+f2g1
            => f * g = f1*g1*x^2k + [(f1+f2)*(g1+g2)-f1g1-f2g2]*x^k + f2*g2
        因此複雜度變成: T(n) = 3T(n/2) + O(n) = O(n^log(2)3)，算是快了不少。
    Implementation:
        以下實作將多項式的次數補至 2^m - 1，也就是說總共有 2^m 項。像這樣
        將 n 調整至 2 的冪次，減低實作難度以外，複雜度也不會受到影響。(不存在的項係數為 0)
    T(n) = 3T(n/2)+ O(n) => O(n^log(2)3)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1<<22;
int N; // 輸入時代表最高次，隨後調整為項數，可以想成是 [0, N) 的次數區間
int F[MAX_N], G[MAX_N];
// 為了傳參數的方便，f, g 是一般陣列而非 vector
// 為了 return 的方便，return value 設為 vector
// dac(乘多項式, 被乘多項式, 次數+1(也就是項數))
vector<int> dac(int f[], int g[], int n) {
    // 當簡化至 2 個一次多項式 (項數=2) 相乘，直接乘
    if(n == 2) {
        vector<int> mul(N);
        mul[2] += f[1]*g[1];
        mul[1] += f[0]*g[1] + f[1]*g[0];
        mul[0] += f[0]*g[0];
        return mul;
    }
    int k = n / 2; // 一次分一半
    vector<int> res(2*N);
    int le[k] ={0}, ri[k] = {0};
    // f2 + f1
    for(int i=0; i<k; ++i) le[i] = f[i] + f[i+k];
    // g2 + g1
    for(int i=0; i<k; ++i) ri[i] = g[i] + g[i+k];
    vector<int> k_0 = dac(f, g, k), k_2 = dac(f+k, g+k, k);
    vector<int> kaa = dac(le, ri, k);
    // 記得乘上 x^k, x^2k (res[i+k], res[i+2*k])
    for(int i=0; i<n; ++i) {
        res[i] += k_0[i]; // f2g2
        res[i+k] += kaa[i] - k_0[i] - k_2[i]; // (f1+f2)*(g1+g2)-f1g1-f2g2
        res[i+n] += k_2[i]; // f1g1
    }
    return res;
}
int main() { 
    int to2 = 1;
    memset(F, 0, sizeof(F));
    memset(G, 0, sizeof(G));
    cout << "Enter leading coefficient:\n";
    cin >> N;
    cout << "Enter the coeffcients of two polynomials (decreasing):\n";
    for(int i=N; i>=0; --i) cin >> F[i];
    for(int i=N; i>=0; --i) cin >> G[i];
    // <= 是因為接下來的 N 代表的是 "項數"，而項數 = deg(f) + 1
    while(to2 <= N) to2 <<= 1;
    // 將 N 調整至 2 的冪次，減低實作難度以外，複雜度也不會受到影響
    N = to2; 
    vector<int> res = dac(F, G, N);
    for(int i=2*N-1; i>=0; --i) cout << res[i] << ' ';
    // 代入 x
    // long long val = 0;
    // for(int i=0, p=1; i<=2*N; ++i, p*=2) val += res[i]*p;
    // cout << val << '\n';
    
    return 0;
}