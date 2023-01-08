/*
***String***
    Description:
        利用 "倍增法 + 內建排序" 來優化時間複雜度。
        (Doubling Algorithm + sort)
        雖然有更快的演算法，但似乎使用這個就夠快了，而且比較方便。
    O(L * (log L)^2)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int n, k; // 2^r
int sa[N], ra[N]; // rank

// 以 rank 排序 sa
bool cmp_sa(int i, int j) {
    if(ra[i] != ra[j]) return ra[i] < ra[j];
    // 倍增後 (往後跳)
    int r1 = i+k < n ? ra[i+k] : -1; 
    int r2 = j+k < n ? ra[j+k] : -1;
    return r1 < r2;
}
void get_suffix(string &s) {
    n = s.size(), k = 0;
    // 2^0
    // i=n 是為了表示空字串，因為它也是 suffix 的一部分
    for(int i=0; i<=n; ++i) {
        sa[i] = i;
        ra[i] = i < n ? s[i] : -1;
    }
    int tmp[N]; // 暫存新的 rank
    for(k=1; k<=n; k<<=1) {
        sort(sa, sa+n+1, cmp_sa);
        tmp[sa[0]] = 0;
        for(int i=1; i<=n; ++i) {
            // 當 ra[sa[i-1]] < ra[sa[i]] 時，cmp_sa 為 1，否則維持原 rank 
            tmp[sa[i]] = tmp[sa[i-1]] + (cmp_sa(sa[i-1], sa[i]));
        }
        // update
        for(int i=0; i<=n; ++i) ra[i] = tmp[i];
    }
}
int main() {
    string s = "aabbaa";
    get_suffix(s);
    for(int i=0; i<=n; ++i) {
        cout << setw(2) << sa[i] << ": " << s.substr(sa[i]) << '\n'; 
    }
    return 0;
}