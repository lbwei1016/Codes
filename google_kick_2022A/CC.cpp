#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

unordered_set<int> S;

bool palin(string &s, int st, int len, unordered_set<int> &back) {
    bool stay = false;
    for (int i=0; i<(len/2); ++i) {
        if (s[i+st] != s[len-i-1+st]) {
            // if (s[i+st] == '?') {
            //     s[i+st] = int(s[len-i-1+st]-'0') ^ 1 + '0';
            //     S.erase(i+st);
            //     back.insert(i+st);
            // }
            // else if (s[len-i-1+st] == '?') {
            //     s[len-i-1+st] = int(s[i+st]-'0') ^ 1 + '0';
            //     S.erase(len-i-1+st);
            //     back.insert(len-i-1+st);
            // }
            return false;
        }
        else if (s[i+st] == '?') stay = true;
    }
    return !stay;
}

bool solve(string &s, int len, unordered_set<int> &back) {
    for (int l=5; l<=len; ++l) {
        for (int i=0; i+l<len; ++i) {
            // 不看 "?" 的情況就 palin
            if (palin(s, i, l, back)) {
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
    unordered_set<int> back;
    bool res = 0;
    int at = *S.begin();
    S.erase(at);

    for (int i=0; i<2; ++i) {
        s[at] = i + '0';
        if (solve(s, len, back)) {
            res |= rec(s, len);
            if (res) return res;
        }
        for (auto &x :back) {
            S.insert(x);
        }
        back.clear();
    }

    s[at] = '?';
    S.insert(at);
    return false;
}

void print(bool res, int i) {
    printf("Case #%d: ", i);
    if (res) {
        printf("POSSIBLE\n");
    }
    else puts("IMPOSSIBLE");
}

int main() {
    // io;
    int t;
    cin >> t;
    for (int i=1; i<=t; ++i) {
        int len; cin >> len;
        string s;
        cin >> s;
        unordered_set<int> tmp;

        S.clear();

        for (int j=0; j<len; ++j) {
            if (s[j] == '?')
                S.insert(j);
        }

        bool res = solve(s, len, tmp);
        if ()

        res = rec(s, len);
        
    }
    return 0;
}