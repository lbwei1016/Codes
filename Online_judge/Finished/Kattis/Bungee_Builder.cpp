#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int mn = 1e9, mx = 0, res = 0;
    cin >> n;

    for(int i=0; i<n; ++i) {
        int h;
        cin >> h;
        if(h > mn) {
            if(h < mx) {
                res = max(res, h-mn);
            }
            else {
                res = max(res, mx-mn);
                mx = h;
                mn = 1e9;
            }
        }
        else {
            mx = max(mx, h);
            mn = h;
        }
    }
    cout << res << '\n';

    return 0;
}