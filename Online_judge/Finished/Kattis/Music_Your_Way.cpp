#include <bits/stdc++.h>
using namespace std;

int pos;

bool cmp(const vector<string> &lhs, const vector<string> &rhs) {
    return lhs[pos] < rhs[pos];
}

void print(vector<string> &attr, vector<vector<string> > &song) {
    for(auto x: attr) cout << x << ' ';
    cout << '\n';
    for(auto s: song) {
        for(auto a: s) cout << a << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    vector<string> attr;
    string s;
    int n, que;
    getline(cin, s);
    s += ' ';
    for(int i=0, prev=0, l=s.size(); i<l; ++i) {
        if(s[i] == ' ') {
            attr.push_back(s.substr(prev, i-prev));
            prev = i+1;
        }
    }

    cin >> n;
    vector<vector<string> > song(n, vector<string>(attr.size()));
    for(auto &s: song) {
        for(auto &at: s) cin >> at;
    }
    cin >> que;
    while(que--) {
        string q;
        cin >> q;
        // determine which attribute is used for sorting
        pos = find(attr.begin(), attr.end(), q) - attr.begin();
        stable_sort(song.begin(), song.end(), cmp);
        print(attr, song);
    }

    return 0;
}