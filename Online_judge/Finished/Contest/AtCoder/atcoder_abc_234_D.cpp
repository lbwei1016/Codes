#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    multiset<int> S;
    for (int i=1; i<=k; ++i) {
        int x; cin >> x;
        S.insert(-x);
    }    
    auto it = --S.end();
    for (int i=k+1; i<=n; ++i) {
        cout << -(*it) << '\n';
        int x; cin >> x;
        S.insert(-x);
        if (x > -(*it)) --it;
    }
    cout << -(*it) << '\n';
    return 0;
}