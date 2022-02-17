#include <bits/stdc++.h>
using namespace std;

const int S = 360;
struct L {
    int l, r;
};

int main() {
    vector<L> ls;
    int rota = 0, n;
    cin >> n;

    ls.push_back(L{0, 360});
    for(int i=0; i<n; ++i) {
        int deg; cin >> deg;
        // rota += deg;
        for(int j=0, sz=ls.size(); j<sz; ++j) {
            // auto &x = ls[j];
            ls[j].l = (ls[j].l + deg) % S;
            ls[j].r = (ls[j].r + deg) % S;
            if(ls[j].r - ls[j].l <= 0) {
                ls.push_back(L{0, ls[j].r});
                // ls[j].l = ls[j].r; 
                ls[j].r = 0;
                // break;
            }
        }
    }
    int mx = 0;
    for(auto x: ls) {
        mx = max(mx, (x.r-x.l + 360) % 360);
    }
    cout << mx << '\n';
    return 0;
}