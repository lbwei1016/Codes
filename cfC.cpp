#include <bits/stdc++.h>
using namespace std;

vector<int> k(105), h(105);

int rec(int d, int n, int res, int now) {
    if(d == n) return res;
    if(k[d] - k[d-1] > 1) now = 1;
    else ++now;

    if(h[d] == 1) {
        return min(rec(d+1, n, res+1, 1), rec(d+1, n, res+now, now));
    }
    if(now < h[d]) {
        while(now <= h[d]) res += now++;
        now = h[d];
    }
    return rec(d+1, n, res, now);
}
int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) {
            cin >> k[i];
        }
        for(int i=1; i<=n; ++i) {
            cin >> h[i];
        }
        
        cout << rec(1, n+1, 0, 1) << '\n';
    }
    return 0;
}