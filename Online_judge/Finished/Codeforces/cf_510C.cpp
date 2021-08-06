/*
***Graph*** -- topological sort
    Solution:
        字母的出現順序要滿足 DAG
*/
#include <bits/stdc++.h>
using namespace std;

const int A = 30;
int n, deg[A], tp[A];
vector<int> par[A];
string s[105];

bool todag() {
    for(int i=1, j=0; i<n; ++i, j=0) {
        bool iden = false;
        while(s[i-1][j] == s[i][j]) {
            ++j;
            if(j == s[i-1].size() || j == s[i].size()) {
                iden = true;
                break;
            }
        }
        if(!iden) {
            par[s[i-1][j]-'a'].push_back(s[i][j]-'a');
            ++deg[s[i][j]-'a'];
        } 
        else if(s[i-1].size() > s[i].size()) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> s[i];
    }
    if(!todag()) {
        cout << "Impossible\n";
        return 0;
    }
    int head = 0, tail = 0;
    for(int i=0; i<26; ++i) {
        if(deg[i] == 0) tp[tail++] = i;
    }
    while(head < tail) {
        int v = tp[head++];
        for(auto u : par[v]) {
            if(--deg[u] == 0) tp[tail++] = u;
        }
    }
    if(tail < 26) cout << "Impossible\n"; // 非 DAG
    else {
        for(int i=0; i<26; ++i) 
            cout << (char)(tp[i]+'a');
    }
    return 0;
}