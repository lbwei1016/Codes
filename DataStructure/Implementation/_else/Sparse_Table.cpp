/*
***Sparse Table*** 
    Description:
        類似「倍增法」；遞迴式:
            f(i, j): minimum in [i, i+2^j]
            { f(i, 0) = xi
            { f(i, j+1) = min(f(i, j), f(i+2^j, j)
        進行 RMQ 時，對於範圍 [l, r]，先找出 k = log2(r-l+1)，而答案就是:
            min(f(l, k), f(r-2^k+1, k))
        即使有重疊部分，但不影響答案。
    Complexity:
        建構: O(n logn)
        查詢: O(1)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 100, lgN = 8;
// ST[i][j]: [i, i+2^j] 的最小值
int ST[N][lgN];

void construct(vector<int> &arr) {
    int n = arr.size();
    // j = 0, 自己就是最小值
    for(int i=0; i<n; ++i) ST[i][0] = arr[i];
    for(int j=0; (1<<j)<n; ++j) {
        for(int i=0; i+(1<<j)<n; ++i) {
            ST[i][j+1] = min(ST[i][j], ST[i+(1<<j)][j]);
            /*
                ST[i][j]: ST[i][j+1] 的左半邊
                ST[i+(1<<j)][j]: 右半邊
            */
        }
    }
}
int RMQ(int l, int r) {
    int k = __lg(r-l+1); // __lg() =  floor(log2())
    return min(ST[l][k], ST[r-(1<<k)+1][k]);
}
int main() {
    vector<int> arr = {5, 1, 7, 8, 2, 4, 9, 0};
    construct(arr);
    int l, r;
    while(cin >> l >> r) cout << RMQ(l, r) << '\n';
    return 0;
}