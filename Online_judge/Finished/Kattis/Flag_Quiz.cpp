#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int main() {
    string s;
    int n, diff[N] = {0}, parts;
    getline(cin, s); 
    // getchar();
    cin >> n;
    vector<string> v[n];
    getchar();
    for(int i=0; i<n; ++i) {
        getline(cin, s);
        int pre = 0;
        for(int j=0, l=s.size(); j<l; ++j) {
            if(s[j] == ',') {
                v[i].push_back(s.substr(pre, j-pre));
                pre = j + 2;
                ++j;
            }
        }
        v[i].push_back(s.substr(pre, s.size()-pre));
    }
    parts = v[0].size();
    for(int i=0; i<n; ++i) {
        for(int j=i; j<n; ++j) {
            int d = 0;
            for(int c=0; c<parts; ++c) {
                if(v[i][c] != v[j][c]) {
                    ++d;
                }
            }
            diff[i] = max(diff[i], d);
            diff[j] = max(diff[j], d);
        }
    }

    int mn = 1e9;
    for(int i=0; i<n; ++i) {
        mn = min(mn, diff[i]);
    }
    for(int i=0; i<n; ++i) {
        if(diff[i] == mn) {
            for(int j=0; j<parts; ++j) {
                cout << v[i][j] << (j==parts-1 ? "\n" : ", ");
            }
        }
    }
    
    return 0;
}