/*
***Monotone***
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    // mn: minimum mt.; mx: maximum mt.
    int mn = 1e9, mx = 0, res = 0;
    cin >> n;

    for(int i=0; i<n; ++i) {
        int h;
        cin >> h;
        if(h > mn) {
            // update answer
            if(h < mx) {
                res = max(res, h-mn);
            }
            else {
                /* 
                    If current mt. is higher than its prev. mt., then 
                    "mn" must be initialized, since it can never be used
                    as the lowest point (any future bridge would come across
                    this current mt. if "mn" remains to the minimum).
                */
                res = max(res, mx-mn);
                mx = h;
                mn = 1e9;
            }
        }
        else {
            // At some point, a mt. can simultaneously be "mx" and "mn".
            mx = max(mx, h);
            mn = h;
        }
    }
    cout << res << '\n';

    return 0;
}