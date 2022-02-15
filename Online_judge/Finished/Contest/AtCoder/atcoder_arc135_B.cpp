#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    ll now, pre, ele0;
    cin >> n >> pre;
    ele0 = pre;
    vector<ll> diff(n+2), maxs(3);
    for(int i=3; i<n+2; ++i) {
        cin >> now;
        diff[i] = diff[i-3] + (now - pre);
        pre = now;
        maxs[i%3] = max(maxs[i%3], -diff[i]);
    }
    ll req = 0;
    for(auto x: maxs) req += x;
    if(req <= ele0) {
        puts("Yes");
        maxs[0] += ele0 - req;
        for(int i=0; i<n+2; ++i) {
            cout << maxs[i%3]+diff[i] << ' ';
        }
    }
    else puts("No");
    // cout << req;
    return 0;
}