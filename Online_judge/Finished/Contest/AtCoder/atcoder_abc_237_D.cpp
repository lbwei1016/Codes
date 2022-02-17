#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    list<int> A;
    A.push_back(0);
    auto it = A.begin();
    for(int i=1; i<=n; ++i) {
        if(s[i-1] == 'R') ++it;
        it = A.insert(it, i);
    }
    for(auto x: A) cout << x << ' ';
    
    return 0;
}