#include <bits/stdc++.h>
using namespace std;

int pow_2[21];

int t, n;

void calc_pow() {
    for(int i=0, n=1; i<21; ++i, n*=2) 
        pow_2[i] = n;
}

bool calc(int k, vector<int> &psum) {
    
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> v(n);
        for(auto &x: v) cin >> x;
        sort(v.begin(), v.end());

        vector<int> psum;
        int cnt = 1;
        psum.reserve(n);
        for(int i=1, pre=v[0]; i<n; ++i) {
            if(v[i] != pre) psum.push_back(cnt);
            ++cnt;
            pre = v[i];
        }
        psum.push_back(cnt);

        int lb = -1, ub = n+1;
        while(ub - lb > 1) {
            int mid = (ub+lb) / 2;
            if(calc(mid, psum)) ub = mid;
            else lb = mid;
        }
    }
    return 0;
}