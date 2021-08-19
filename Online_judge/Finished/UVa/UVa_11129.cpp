/*
***Divide and Conquer***
    Description:
        將序列 { 0, 1, ..., n-1 } 排列成一新序列，使得沒有任何
        子序列可以形成等差數列
    Solution:
        利用等差數列的特性:
            屬於同一等差數列的數必定為同奇、同偶或奇偶相間，證明:
                已知 k-d, k, k+d 為一等差數列，k-d, k+d 必同奇偶性，
                而 k, d 可為奇或偶，因此奇偶性必定三相同或只有中間相異。
        因此我們可以將原序列分為 {偶}{奇} 兩部分，從上述特性我們可以確知，
        必定不存在跨越兩部分的等差數列。如此一來，只要繼續向下切割就好了。

        切割偶數序列: 可以視為所有數同除以 2，就變成奇偶相間的序列了
        切割奇數序列: 視為所有數同 -1 再除以 2 即可
    O(n * logn)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 10000+1;
int n, a[N], tmp[N];
// [)
void dac(int l, int r) {
    if(r-l <= 1) return;
    for(int i=l; i<r; ++i) tmp[i] = a[i];
    int j = l, m;
    for(int i=l; i<r; i+=2) a[j++] = tmp[i];
    m = j; // 奇偶分界
    for(int i=l+1; i<r; i+=2) a[j++] = tmp[i];
    dac(l, m); dac(m, r);
}
int main() {
    while(scanf("%d", &n) == 1) {
        if(n == 0) break;
        for(int i=0; i<n; ++i) a[i] = i;
        dac(0, n);
        printf("%d: ", n);
        for(int i=0; i<n; ++i) 
            printf("%d%c", a[i], i==n-1 ? '\n' : ' ');
    }
    return 0;
}