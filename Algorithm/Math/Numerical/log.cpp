/*
    Algorithm from TAOCP Vol.1 p.24
*/
#include <bits/stdc++.h>
using namespace std;
typedef numeric_limits<double> dbl;
const long double EPS = 1e-6;

namespace my {
    long double log10(long double x) {
        int n = 0;
        long double xi = x, pre_xi;
        while (!((1<xi || abs(1-x)<EPS) && xi<10)) {
            if (x > 10) {
                ++n; 
                xi /= 10;
            }
            else {
                --n;
                xi *= 10;
            }
        }

        pre_xi = xi;
        int prec = 100; // 100 times is enough
        vector<bool> b(prec+1);
        long double result = n, cnt = 2;
        for (int i=1; i<=prec; ++i) {
            long double sqr_px = pre_xi * pre_xi;
            b[i] = sqr_px / 10;
            if (sqr_px < 10) {
                b[i] = 0;
                pre_xi = sqr_px;
            }
            else {
                b[i] = 1;
                pre_xi = sqr_px / 10;
            }
            result += b[i] / cnt;
            cnt *= 2;
        }
        return result;
    }    
}


int main() {
    long double x = 9;
    // cin >> x;
    /*
    dbl::max_digits10:
        the number of base-10 digits that are necessary to uniquely 
        represent all distinct values of "double"
    */
    // cout.precision(dbl::max_digits10);
    cout.precision(100); // exceeds
    cout << dbl::max_digits10 << '\n'; // 17
    cout << my::log10(x) << '\n';
    cout << log10(x) << '\n'; // built-in
    return 0;
}