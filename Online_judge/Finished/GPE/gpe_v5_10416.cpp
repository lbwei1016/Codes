/*
***Math***
    Solution:
        找個位數的規律。
*/
#include <bits/stdc++.h>
using namespace std;

int mod[2][10] = {{0, 1, 4, 7, 6, 5, 6, 3, 6, 9}, {0, 1, 6, 3, 6, 5, 6, 7, 4, 9}};

int main() {
    string s;
    while(cin >> s) {
        if(s == "0") break;
        int res = 0, m = 0;
        if(s.size() >= 2) {
            int j = s[s.size()-2]-'0';
            res += j*7;
            res %= 10;
            m = j % 2;
        }
        int k = s[s.size()-1]-'0';
        for(int i=1; i<=k; ++i) {
            res += mod[m][i];
            res %= 10;
        }
        cout << res << '\n';
    }

    return 0;
}