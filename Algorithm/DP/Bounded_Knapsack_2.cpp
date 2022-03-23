/*
***DP*** -- Bounded knapsack (二進制拆分)
    Solution:
        將物品數量 > 1 的種類以 2 的次方拆成數個子物品 (1, 2, 4, 8....)，
        而這些子物品恰可以組合成任意小於等於原數量的拿取方式，再以 0/1 背包
        求解。物品種類增多至 N * log T。
    優化:
        for(int j=W....) 其實不必從 "W" 開始，只要 "j = min(W, ∑w[k]: k<i)" 
        就好了，因為更大的那些背包空間其實也只是照抄前面的值而已，根本用不到那麼多。
        (前提: ∑w[i] >= W，不過大概不會有不符合的情況)
    O(N * log T * W)
    N: 物品種類；T: 物品數量；W: 可容納重
*/
#include <iostream>
using namespace std;

const int MAX_W = 1005;
const int N = 8000;
int n, W;
int v[N], w[N], dp[MAX_W]; // value, weight, number of items
int main() {
    scanf("%d%d", &n, &W);
    int cnt = 0;
    for(int i=0; i<n; i++) {
        int a, b, t, j;
        scanf("%d%d%d", &a, &b, &t);
        if(t < 0) t = W / b; // 數量無限多時
        // 拆解
        for(j=1; j<t; j<<=1) {
            v[cnt] = a * j;
            w[cnt++] = b * j;
        }
        // 當 t 恰為二的整數次方
        if(t == j) {
            v[cnt] = a;
            w[cnt++] = b;
        }
    }
    // 0/1 knapsack
    for(int i=0; i<cnt; i++) {
        for(int j=W; j>=w[i]; j--)
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
    }
    printf("%d\n", dp[W]);
    return 0;
}