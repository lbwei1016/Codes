/*
***Divide and Conquer / Sliding Window*** (*)
    Description:
        找出第 k 大的區間和
    Solution:
        利用二分搜尋法，找出 q 使得比 q 大的區間和數量有 k-1 個，那麼 q 將是
        第 k 大的區間和。

        如何找出比 q 大的區間和數量 ?

        由於序列值可能為負，因此前綴和並不單調；此時利用 merge sort 的概念，
        排序 [l, m) 和 [m, r) 的前綴和，查找橫跨兩區間的區間和中，比 q 大
        的數量，並加上遞迴的回傳值。
        (為什麼可以將左右區間排序後再求解 ? 因為在排序前序列已經被依照原先順
        序切半，所以前綴和所在的左右相對位置並無更動，求解過程只是進行順序不
        定的前綴和相減而已，依然可以找出比 q 大的區間和數量。)

        經過上述的處理，[l, m) 和 [m, r) 中的前綴和已呈現單調性，因此若前綴和
        S[j] - S[i] > q，則 S[k]: k>j 與 S[i] 的差必定大於 q；我們於是可以利
        用爬行法來求解。
    Note:
        前綴和 S: S[j] - S[i] 為 [j, i) 的區間和；將 S[0] 設為 0，
        使得求解過程 (S[j] - S[i]) 可以直接求出 a[0] (第一項序列值)。
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 20005;
int n, k, a[N], tmp[N];
int psum[N]; // original prefix sum
int s[N]; // prefix sum array for merge sort

int dac(int l, int r, int q) {
    if(l+1 >= r) return 0;
    int m = (l+r) >> 1;
    int cnt = dac(l, m, q) + dac(m, r, q);

    // 爬行法
    for(int i=l, j=m; i<m; ++i) {
        while(j<r && s[j]-s[i]<=q) ++j;
        cnt += r - j;
    }

    // merge sort
    int j = m, k = 0;
    for(int i=l; i<m; ++i) {
        while(j<r && s[j]<s[i]) tmp[k++] = s[j++];
        tmp[k++] = s[i];
    }
    for(int i=l; i<j; ++i) s[i] = tmp[i-l];

    return cnt;
}
bool check(int q) {
    memcpy(s, psum, sizeof(psum));
    // 共 n+1 項
    return (dac(0, n+1, q) <= k-1);
}
int main() {
    while(scanf("%d%d", &n, &k) == 2) {
        if(!n) break;
        for(int i=0; i<n; ++i) scanf("%d", a+i);
        // 為了讓 s[j]-s[i] = a[0] 可以被計算出來，前綴和首項置 0，因此共 n+1 項
        psum[0] = 0; 
        for(int i=0; i<n; ++i) psum[i+1] = psum[i] + a[i];

        // 二分搜找解
        int lb = n * (-10000) - 1, ub = n * 10000;
        while(ub - lb > 1) {
            int mid = (lb+ub) >> 1;
            if(check(mid)) ub = mid;
            else lb = mid;
        }
        printf("%d\n", ub);
    }
    return 0;
}