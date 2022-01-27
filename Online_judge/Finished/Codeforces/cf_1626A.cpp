#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        int alp[30] = {0};
        cin >> s;
        string ss;
        for(auto &x: s) {
            if(++alp[x-'a'] == 2) {
                ss.push_back(x);
            }
        }
        for(auto x: ss) {
            cout << x << x;
        }
        for(auto x: s) {
            if(alp[x-'a'] == 2) continue;
            cout << x;
        }
        cout << '\n';
    }
    return 0;
}