/*
***Divide and Conquer***
    O(n logn)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+2;
int n, arr[N], tmp[N];

ll dac(int l, int r) {
    if(l+1 >= r) return 0;
    int m = (l+r) >> 1;
    ll cnt = dac(l, m) + dac(m, r);
    int i, j, k = 0;
    for(i=l, j=m; i<m; ++i) {
        while(j<r && arr[i]>arr[j]) {
            tmp[k++] = arr[j++];
        }
        tmp[k++] = arr[i];
        cnt += j - m;
    }
    for(int i=l; i<j; ++i) arr[i] = tmp[i-l];

    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 0;
    while(cin >> n && n) {
        for(int i=0; i<n; ++i) cin >> arr[i];
        cout << "Case #" << ++cnt << ": " << dac(0, n) << '\n';
    }   
    return 0;
}