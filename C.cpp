#include <bits/stdc++.h>
using namespace std;

map<int, vector<int> > mp;
int main() {
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; ++i) {
        int tmp;
        cin >> tmp;
        mp[tmp].push_back(i+1);
    }

    while(q--) {
        int x, k;
        cin >> x >> k;
        if(mp[x].size() < k) cout << "-1\n";
        else cout << mp[x][k-1] << '\n';
    }
    return 0;
}