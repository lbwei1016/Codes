#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> v;
    while(cin >> n) {
        v.resize(n);
        for(int i=0; i<n; ++i) cin >> v[i];
        sort(v.begin(), v.end());
        if(n == 1) {
            cout << v[0] << " 1 1\n";
        }
        else if(n == 2) {
            int k = abs(v[0]-v[1]);
            if(k == 0) cout << v[0] << " 2 1\n";
            else {
                cout << k << " 2 " << k+1 << '\n';
            }
        }
        else {
            int mid, cnt = 0;
            if(n & 1) {
                mid = v[n/2];
                for(int i=0; i<n; ++i) {
                    if(v[i] == mid) ++cnt;
                }
                cout << mid << ' ' << cnt << ' ' << "1\n";
            }
            else {
                int mid2 = v[n/2];
                mid = v[n/2-1];
                for(int i=0; i<n; ++i) {
                    if(mid<=v[i] && v[i]<=mid2) ++cnt;
                }
                cout << mid << ' ' << cnt << ' ' << mid2-mid+1 << '\n';
            }
        }
    }
    return 0;
}