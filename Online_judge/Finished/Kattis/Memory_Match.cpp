#include <bits/stdc++.h>
using namespace std;

int n, k;
map<string, int> mp; // 只翻到一張的
set<string> got; // 兩張牌都已知的
set<int> known_pos; // 哪些位置翻過

int main() {
    int p[2];
    string s[2];
    cin >> n >> k;
    for(int i=0; i<k; ++i) {
        cin >> p[0] >> p[1] >> s[0] >> s[1];
        known_pos.insert(p[0]); known_pos.insert(p[1]);
        if(s[0] == s[1]) {
            // 知道後又被翻開的
            if(got.count(s[0])) {
                got.erase(s[0]);
            }
            else {
                mp.erase(s[0]);
            }
            continue;
        }
        for(int j=0; j<2; ++j) {
            auto it = mp.find(s[j]);
            // 曾經翻過，又翻到不同張
            if(it!=mp.end() && it->second!=p[j]) {
                got.insert(s[j]);
                mp.erase(it);
            }
            else if(!got.count(s[j])) {
                mp[s[j]] = p[j];
            }
        }
    }    
    int add = 0;
    if(mp.size() == n-known_pos.size()) add = mp.size();
    // 只剩兩張就直接翻了!!!
    else if(n-known_pos.size() == 2) add = 1;
    cout << got.size()+add << '\n';

    return 0;
}