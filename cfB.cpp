#include <bits/stdc++.h>
using namespace std;

string s;

int cmp(string s1, string s2, int l1, int l2) {
    if(l1 != l2) return l1>l2?1:-1;
    for(int i=0, j=0; i<l1&&j<l2; ++i, ++j) {
        if(s1[i] == '$') {
            --j;
            ++l1;
            continue;
        }
        if(s2[j] == '$') {
            --i;
            ++l2;
            continue;
        }
        if(s1[i] != s2[j]) {
            // cout << (s1[i]>s2[i]?1:-1) << '\n';
            return s1[i]>s2[j]?1:-1;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        // string s;
        string mx = "0";
        cin >> s;
        int len = s.size(), lmx = 1;
        for(int i=1; i<len; ++i) {
            int ds = 0;
            char tmp1 = s[i-1], tmp2 = s[i];
            int sum = s[i]+s[i-1]-'0'-'0';
            if(sum < 10) {
                ++ds;
                s[i-1] = '$';
            }
            else s[i-1] = sum / 10 + '0';
            s[i] = sum % 10 + '0';
            if(cmp(mx, s, lmx, len-ds) < 0) {
                mx = s;
                lmx = len-ds;
            }
            s[i-1] = tmp1; s[i] = tmp2;
        }   
        int st;   
        for(st=0; st<lmx; ++st) {
            if(mx[st] != '0') break;
        }  
        for(; st<lmx; ++st) {
            if(mx[st] != '$') cout << mx[st];
            else ++lmx;
        }
        cout << '\n';
    }
    return 0;
}