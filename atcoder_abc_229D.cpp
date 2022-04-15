#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    // io;
    string s;
    int k, K;
    cin >> s >> k;
    K = k;
    vector<int> sym;
    for (int i=0;;) {
        int xcnt = 0, dcnt = 0;
        // bool flag = false;
        while (i<s.size() && s[i] == 'X') {
            ++xcnt;
            ++i;
            // flag = true;
        }
        if (xcnt > 0)
            sym.push_back(xcnt);
        // if (flag) {
        //     --i; continue;
        // }
        while (i<s.size() && s[i] == '.') {
            ++dcnt;
            ++i;
            // flag = true;
        }
        if (dcnt > 0)
            sym.push_back(-dcnt);
        if (i == s.size()) break;
        // --i;
    }

    int lb = 0, rb = 0;
    int n = sym.size();
    int sum = 0, mx = 0;
    while (rb-lb >= 0) {
        bool jump = false;
        while (rb<n) {
            if (sym[rb] > 0) {
                sum += sym[rb];
            }
            else if (k >= -sym[rb]) {
                k -= -sym[rb];
                sum += -sym[rb];
            }
            else {
                if (-sym[rb] > K) {
                    jump = true;
                    ++rb; 
                }
                break;
            }
            ++rb;
        }
        // ++rb;
        mx = max(mx, min((int)s.size(), sum+k));
        if (jump) {
            lb = rb;
            sum = 0;
            k = K;
            continue;
        }

        if (sym[lb] > 0) {
            sum -= sym[lb];
            // ++lb;
        }
        else if (-sym[lb] <= K) {
            k += -sym[lb];
            sum -= -sym[lb];
            // ++lb;
        }
        ++lb;
    }
    cout << mx << '\n';
    return 0;
}