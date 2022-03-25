#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

unordered_set<int> S;

bool palin(string &s, int st, int len) {
    bool stay = false;
    for (int i=0; i<(len/2); ++i) {
        if (s[i+st] != s[len-i-1+st]) {
            return false;
        }
        else if (s[i+st] == '?') stay = true;
    }
    return stay ? 0 : 1;
}

bool check(string &s, int len) {
    for (int l=5; l<=len; ++l) {
        for (int i=0; i+l<len; ++i) {
            // 不看 "?" 的情況就 palin
            if (palin(s, i, l)) {
                return false;
            }
        }
    }
    return true;
}

bool rec(string &s, int len) {
    if (S.empty()) {
        return true;
    }
    bool res = 0;
    int at = *S.begin();
    S.erase(at);

    for (int i=0; i<2; ++i) {
        s[at] = i + '0';
        if (check(s, len)) {
            res |= rec(s, len);
            if (res) return res;
        }
    }

    s[at] = '?';
    S.insert(at);
    return false;
}

int main() {
    // io;
    int t;
    cin >> t;
    for (int i=1; i<=t; ++i) {
        int len; cin >> len;
        string s;
        cin >> s;

        S.clear();

        for (int j=0; j<len; ++j) {
            if (s[j] == '?')
                S.insert(j);
        }

        bool res = rec(s, len);
        printf("Case #%d: ", i);
        if (res) {
            printf("POSSIBLE\n");
            // cout << "GOOD: "+s+'\n';
        }
        else puts("IMPOSSIBLE");
    }
    return 0;
}