/*
***String*** -- Suffix Array
    O(L * (log L)^2)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int sa[N], ra[N], tmp[N], n, k;
string s;

inline bool cmp_sa(int i, int j) {
    if(ra[i] != ra[j]) return ra[i] < ra[j];
    int r1 = i+k < n ? ra[i+k] : -1;
    int r2 = j+k < n ? ra[j+k] : -1;
    return r1 < r2;
}
void suffix() {
    for(int i=0; i<n; ++i) {
        sa[i] = i;
        ra[i] = s[i];
    }
    for(k=1; k<=n; k<<=1) {
        sort(sa, sa+n, cmp_sa);
        tmp[sa[0]] = 0;
        for(int i=1; i<n; ++i) {
            tmp[sa[i]] = tmp[sa[i-1]] + (cmp_sa(sa[i-1], sa[i]));
        }
        for(int i=0; i<n; ++i) ra[i] = tmp[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    getline(cin, s);
    n = s.size();
    suffix();
    for(int i=0; i<n; ++i) cout << sa[i] << '\n';
    return 0;
}