/*
***hash***
    Description:
        利用 mt19937 產生出的 pseudo-random 數來代表集合元素，而集合就是
        所有亂數 XOR 起來的數值。

    (from: atcoder_abc_250E)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, q;
    cin >> n;
    vector<unsigned ll> A(n+1), B(n+1);
    set<int> sA, sB;
    map<int, unsigned ll> hash;
    mt19937_64 mt(16);
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        A[i+1] = A[i];
        // if "x" is successfully inserted
        if (sA.insert(x).second) {
            auto &v = hash[x];
            while (!v) v = mt();
            A[i+1] ^= v;
        }
    }

    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        B[i+1] = B[i];
        // if "x" is successfully inserted
        if (sB.insert(x).second) {
            auto &v = hash[x];
            while (!v) v = mt();
            B[i+1] ^= v;
        }
    }

    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (A[x] == B[y]) puts("Yes");
        else puts("No");
    }    

    return 0;
}