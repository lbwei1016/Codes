/*
***Sweeping Line***
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

struct P { int t, st; };
vector<P> v;
vector<int> res; 

inline bool cmp(const P &p1, const P &p2) {
    return p1.t==p2.t ? p1.st<p2.st : p1.t<p2.t;
}
int main() {
    int n, a, b;
    cin >> n;
    v.reserve(2*n);
    res.resize(n+1);
    for(int i=0; i<n; ++i) {
        cin >> a >> b;
        v.push_back(P{a, 1});
        v.push_back(P{a+b, -1});
    }
    sort(v.begin(), v.end(), cmp);
    int preV = 0, preT = 0, cnt = 0;
    for(int i=0; i<2*n; ++i) {
        P p = v[i];
        cnt += v[i].st;
        while(i+1<2*n && v[i+1].t==p.t) {
            cnt += v[++i].st;
        }
        res[preV] += p.t-preT;
        preV = cnt;
        preT = p.t; 
    }
    for(int i=1; i<=n; ++i) {
        cout << res[i] << ' ';
    }
    return 0;
}