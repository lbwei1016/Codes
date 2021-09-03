/*
***BIT***
    Solution: 
        Two-dimensional BIT
*/
#include <bits/stdc++.h>
using namespace std;
#define lb(i) ((i)&(-i))

const int N = 1024+1;
typedef long long ll;
int n;
ll bit[N][N];

void update(int x, int y, int v) {
    for(int i=x; i<=n; i+=lb(i)) {
        for(int j=y; j<=n; j+=lb(j))
            bit[i][j] += v;
    }
}
ll query(int x, int y) {
    ll res = 0;
    for(int i=x; i>0; i-=lb(i)) {
        for(int j=y; j>0; j-=lb(j)) {
            res += bit[i][j];
        }
    }
    return res;
}
ll Q(int x1, int y1, int x2, int y2) {
    return query(x2, y2)-query(x1-1, y2)-query(x2, y1-1)+query(x1-1, y1-1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int com;
    while(cin >> com) {
        if(com & 1) {
            int x, y, z;
            cin >> x >> y >> z;
            update(x+1, y+1, z);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << Q(x1+1, y1+1, x2+1, y2+1) << '\n';
        }
    }
    return 0;
}