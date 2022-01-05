#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
struct P { int u, v; };
int n, d, p[N];
vector<P> con;

int find_root(int x) {
    return p[x]<0 ? x : p[x]=find_root(p[x]);
}
void unite(int x, int y) {
    int rx = find_root(x);
    int ry = find_root(y);
    if(rx == ry) return;
    if(p[rx] > p[ry]) {
        p[ry] += p[rx];
        p[rx] = ry;
    }
    else {
        p[rx] += p[ry];
        p[ry] = rx;
    }
}
int main() {
    cin >> n >> d;
    con.reserve(n);
    for(int i=0; i<d; ++i) {
        int x, y;
        cin >> x >> y;
        con.push_back(P{x, y});
        memset(p, -1, sizeof(p));
        for(auto x : con) {
            
        }
    }    
    return 0;
}