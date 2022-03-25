#include <bits/stdc++.h>
using namespace std;

bool is_palin(string &s) {
    int len = s.length();
    for (int i=0; i<len/2; ++i) {
        if (s[i] != s[len-i-1]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << is_palin(s);
    return 0;
}