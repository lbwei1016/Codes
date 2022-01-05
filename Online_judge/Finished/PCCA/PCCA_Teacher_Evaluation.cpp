#include <bits/stdc++.h>
using namespace std;

const int N = 35;
int n, p, sum;
int gra[N];

int main() {
    cin >> n >> p;
    for(int i=0; i<n; ++i) {
        cin >> gra[i];    
        sum += gra[i];
    }
    int ans = ceil(double(p*n-sum)/(100.0-p));
    if(ans <= 0) cout << "impossible\n";
    else cout << ans << '\n';
    return 0;
}