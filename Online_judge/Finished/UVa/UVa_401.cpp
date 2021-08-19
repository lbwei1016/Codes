#include <bits/stdc++.h>
using namespace std;

unordered_map<char, char> rev;
bool is_pali(string s) {
    for(int i=0, l=s.size(), h=l/2; i<h; ++i) {
        if(s[i] != s[l-1-i]) return false;
    }
    return true;
}
bool is_mirr(string s) {
    for(int i=0, l=s.size(), h=l/2; i<=h; ++i) {
        if(!rev.count(s[i])) return false;
        if(rev[s[i]] != s[l-1-i]) return false;
    }
    return true;
}
void init() {
    rev['A'] = 'A', rev['E'] = '3', rev['H'] = 'H', 
    rev['I'] = 'I', rev['J'] = 'L', rev['L'] = 'J',
    rev['M'] = 'M', rev['O'] = 'O', rev['S'] = '2',
    rev['T'] = 'T', rev['U'] = 'U', rev['V'] = 'V', 
    rev['W'] = 'W', rev['X'] = 'X', rev['Y'] = 'Y', 
    rev['Z'] = '5', rev['1'] = '1', rev['2'] = 'S',
    rev['3'] = 'E', rev['5'] = 'Z', rev['8'] = '8';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    string s;
    while(cin >> s) {
        cout << s;
        bool pali = is_pali(s), mirr = is_mirr(s);
        if(pali && mirr) cout << " -- is a mirrored palindrome.\n\n";
        else if(pali) cout << " -- is a regular palindrome.\n\n";
        else if(mirr) cout << " -- is a mirrored string.\n\n";
        else cout << " -- is not a palindrome.\n\n";
    }
    return 0;
}