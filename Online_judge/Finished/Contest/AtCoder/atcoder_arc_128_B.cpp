/*
***Math***
    Solution:
        把球的數量加減的情況列出來。
    O(1 * T)。
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int t, r, g, b;

int calc(int to, int a, int b) {
    if(a > b) swap(a, b);
    if((b-a) % 3 != 0) return INF;
    int s = (b-a)/3;
    double dr = ceil(double(s-to)/2.0);
    int r = (int)dr;
    if(r > min(b-s, a+2*s)) return INF;
    return b;
}
int main() {
    cin >> t;
    while(t--) {
        int mn = INF;
        cin >> r >> g >> b;
        mn = min(calc(r, g, b), mn);
        mn = min(calc(g, r, b), mn);
        mn = min(calc(b, r, g), mn);
        if(mn == INF) cout << "-1\n";
        else cout << mn << '\n';
    }    
    return 0;
}