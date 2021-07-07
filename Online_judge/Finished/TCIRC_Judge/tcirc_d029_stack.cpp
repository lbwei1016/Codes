/*
***Monotone Sequence*** -- Stack(implemented by vector for binary search)
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 2e5+5;
int n;
int h[MAX_N], p[MAX_N];
vector<P> S; //h, pos

//search from back
int bin_s(int val) {
    int pos = S.size()-1;
    if(S[pos].first > val) return pos;
    for(int jump=pos/2; jump>0; jump/=2) {
        while(pos-jump>=0 && S[pos-jump].first<=val) {
            pos -= jump;
        }
    }
    return pos-1; //first one > val
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &h[i]);
    }
    for(int i=1; i<=n; i++) {
        scanf("%d", &p[i]);
    }
    h[0] = 1e9;
    S.push_back(P{h[0], 0});
    ll res = 0;
    for(int i=1; i<=n; i++) {
        while(S.back().first <= h[i]) {
            S.pop_back();
        }
        int t = bin_s(h[i]+p[i]);
        res += i - S[t].second - 1;
        S.push_back(P{h[i], i});
    }
    printf("%lld\n", res);
    return 0;
}