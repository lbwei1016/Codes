/*
***Greedy***
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for(int i=1, len=s.size(); i<len; i++) {
        if(s[i] == s[i-1]) {
            char c = s[i-1];
            char subs = c == 'a' ? c+1 : c-1;
            for(int cnt=1; s[i] == c; cnt++, i++) {
                if(cnt & 1)
                    s[i] = subs;
            }
            if(s[i] == s[i-1]) 
                s[i-1] = (c-'a'+10) % 26 + 'a';
        }
    }
    cout << s+"\n";
    return 0;
}