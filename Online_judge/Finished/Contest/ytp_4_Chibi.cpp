#include <bits/stdc++.h>
using namespace std;

struct P { int x, t; };
int n, m;

// P boat[105];
vector<P> B;
int tim[105];

void C() {
    for(auto v : B) {
        int x = v.x, t = v.t;
        for(int i=x; i>0; --i) {
            if(tim[i] <= t+(x-i)) break;
            tim[i] = t+(x-i);
        }
        for(int i=x+1; i<=m; ++i) {
            if(tim[i] <= t+(i-x)) break;
            tim[i] = t+(i-x);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    fill(tim, tim+101, 1e9);
    B.resize(n);
    for(int i=0; i<n; ++i) {
        int x, t;
        cin >> x >> t;
        // tim[x] = t;
        B[i] = P{x, t};
    }
    C();
    for(int i=1; i<=m; ++i) cout << tim[i] << " ";
    cout << '\n';
    return 0;
}