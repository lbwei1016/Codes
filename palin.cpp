#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool palin(string::iterator fr, string::iterator to) {
    while (to - fr >= 1) {
        if (*fr != *to) return false;
        ++fr, --to;
    }
    return true;
}

int LPS(string &s) {
    for (int len=s.size(); len>0; --len)
        for (int i=0; i+len<=s.size(); ++i) 
            if (palin(s.begin()+i, s.begin()+len+i-1)) 
                return len;
    return 0;
}

bool rec(int n, int d, vector<int> &mark, string &s) {
    if (d == n) {
        int len = LPS(s);
        return len < 5;
    }
    bool res = false;
    s[mark[d]] = '0';
    res |= rec(n, d+1, mark, s);
    s[mark[d]] = '1';
    res |= rec(n, d+1, mark, s);
    // s[mark[d]] = '?';
    return res;
}

int main() {
    // io;
    int t; cin >> t;
    for (int i=1; i<=t; ++i) {
        int n; cin >> n;
        string s;
        vector<int> mark;
        cin >> s;
        // cout << s+"\n-------------\n";
        for (int j=0; j<s.size(); ++j) {
            if (s[j] == '?')
                mark.push_back(j);
        }
        if (rec(mark.size(), 0, mark, s)) {
            printf("Case #%d: POSSIBLE\n", i);
        }
        else 
            printf("Case #%d: IMPOSSIBLE\n", i);
    }
    return 0;
}