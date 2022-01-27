/*
***Sweep Line***
    Solution:
        If we regard time as segments, the time segment 
        for a monster (at "k", with health "h") is: (k-h, k].
        Hence, our goal is to find all the segments that do not 
        overlap with each other, and then calculate the sum of 
        them.
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9+5;
struct P { int le, ri; };

ll calc(ll len) {
    return (1+len)*len / 2LL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> k(n), h(n);
        vector<P> seg;
        for(int i=0; i<n; ++i) cin >> k[i];
        for(int i=0; i<n; ++i) cin >> h[i];

        seg.push_back(P{0, 0}); // boundry
        for(int i=0; i<n; ++i) {
            int le = k[i] - h[i];
            while(seg.back().le > le) seg.pop_back();
            // append
            if(seg.back().ri > le) seg.back().ri = k[i];
            else seg.push_back(P{le, k[i]}); // add a new segment
        }
        ll res = 0;
        for(auto x: seg) {
            res += calc(x.ri-x.le);
        }
        cout << res << '\n';
    }
    return 0;
}