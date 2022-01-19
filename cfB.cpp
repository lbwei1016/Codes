#include <bits/stdc++.h>
using namespace std;

bool calc(string &s) {
    int len = s.size();
    for(int i=1; i<len; ++i) {
        int sum = s[i-1]+s[i]-'0'-'0';
        if(sum >= 10) {
            s[i-1] = sum - 10 + '0';
            s[i] = 1 + '0';
            return true;
        }
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s.size() == 1) {
            cout << s << '\n';
            continue;
        }
        reverse(s.begin(), s.end());
        if(calc(s)) reverse(s.begin(), s.end());
        else {
            int len = s.size();
            s[len-2] = s[len-1]+s[len-2]-'0';
            s.pop_back();
            reverse(s.begin(), s.end());
        }
        cout << s << '\n';
    }
    return 0;
}