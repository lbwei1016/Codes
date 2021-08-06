/*
***DP***
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
unsigned long long d[N], n;
int main() {
    cin >> n;
    d[1] = 3, d[2] = 7;
    for(int i=3; i<=n; ++i) {
        d[i] = 2LL*d[i-1] + d[i-2];
    }
    cout << d[n];
    return 0;
}