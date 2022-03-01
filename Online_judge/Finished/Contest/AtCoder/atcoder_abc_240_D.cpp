#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> R(n+5), remain;
    vector<vector<int> > cnt(200005);
    for(int i=0; i<n; ++i) cin >> R[i];

    int pre = 0;
    for(int i=0; i<n; ++i) {
        int x = R[i];
        remain.push_back(x);
        if(pre == x) {
            if(cnt[x].size() && ++cnt[x].back() == x) {
                cnt[x].pop_back();
                for(int j=0; j<x; ++j) remain.pop_back();
                if(!remain.empty()) pre = remain.back();
                else pre = 0;
                // cnt[x].push_back(0);
            }
        }
        else {
            // cnt[pre].push_back(0);
            cnt[x].push_back(1);
            pre = x;
        }
        
        cout << remain.size() << '\n';
    }
    return 0;
}
// 2 3 2 3 3 3 2 3 3 2
// 5 3 4 4 4 3 2 2 3 3 4