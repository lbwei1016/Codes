#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, cnt = 0;
    string s, tar = "abc";
    cin >> n >> q;
    cin >> s;
    for(int i=0; i<n-2; ++i) {
        if(s.substr(i, 3) == tar) ++cnt;
    }
    
    for(int i=0; i<q; ++i) {
        int id;
        char c;
        cin >> id >> c;
        --id;
        for(int i=max(0, id-2); i+2<n && i<id+1; ++i) {
            if(s.substr(i, 3) == tar) --cnt;
        }
        s[id] = c;
        for(int i=max(0, id-2); i+2<n && i<id+1; ++i) {
            if(s.substr(i, 3) == tar) ++cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}