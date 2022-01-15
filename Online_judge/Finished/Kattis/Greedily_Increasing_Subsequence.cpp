#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, pre = 0;
    vector<int> v, res;
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; ++i) {
        cin >> v[i];
        if(v[i] > pre) {
            res.push_back(v[i]);
            pre = v[i];
        }
    }    
    cout << res.size() << '\n';
    for(auto x : res) cout << x << ' ';
    cout << '\n';
    return 0;
}