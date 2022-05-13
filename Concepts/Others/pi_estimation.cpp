/*
Monte Carlo
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ull = unsigned long long;

double dist(long double x, long double y) {
    return x*x + y*y;
}

int main() {
    io;
    mt19937_64 mt(time(nullptr));
    // mt19937_64::max
    ull n = ULLONG_MAX;
    ull all = 0, inside = 0;
    while (n--) {
        long double x = mt() / (long double)mt.max();
        long double y = mt() / (long double)mt.max();
        // cout << x << ' ' << y << '\n';
        if (dist(x, y) < 1) ++inside;
        ++all;
        // cout << inside << ' ' << all << '\n';
        cout << "pi: " << 4.0*(long double)inside/all << '\n';
    }
    return 0;
}