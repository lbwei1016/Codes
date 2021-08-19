#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n) {
        s.resize(n);
        int mx = 0;
        for(int i=0; i<n; ++i) {
            cin >> s[i];
            mx = max(mx, (int)s[i].size());
        }
        sort(s.begin(), s.end());
        for(int i=0; i<60; ++i) cout << '-';
        cout << '\n';
        
        int C = 60/(mx+2) + (60%(mx+2) >= mx);
        int row = n/C+(n%C > 0), col;
        while(row*C-n >= C) --C;
        for(int i=0; i<row; ++i) {
            cout << s[i];
            col = 1;
            while(col*row+i<n && col<C) {
                int len = s[col*row+i-row].size();
                while(len-2 < mx) {
                    cout << ' '; ++len;
                }
                cout << s[col*row+i];
                ++col;
            }
            cout << '\n';
        }
    }
    return 0;
}