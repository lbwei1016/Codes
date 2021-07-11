/*
***Merge Sort / Divide and Conquer***

    O(n * log n)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
vector<int> v;

ll inv(int l, int r) {
    if(l+1 == r) return 0;
    int m = (l+r) / 2;
    ll num = inv(l, m) + inv(m, r), cross = 0;
    int temp[r-l], j = m;
    for(int i=l, k=0; i<m; i++) {
        while(j<r && v[j]<v[i]) {
            temp[k++] = v[j++];
        }
        temp[k++] = v[i];
        cross += j - m;
    }
    for(int i=l; i<j; i++) {
        v[i] = temp[i-l];
    }
    return num + cross;
}
int main() {
    scanf("%d", &n);
    v.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    printf("%lld\n", inv(0, n));
    return 0;
}