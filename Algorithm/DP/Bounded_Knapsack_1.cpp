/*
***DP*** -- Bounded knapsack
    O(N * W * T)
    N: 物品種類；T: 物品數量；可容納重
*/
#include <iostream>
using namespace std;

const int N = 1005;
int n, W;
int v[N], w[N], t[N], dp[N]; // value, weight, number of items
int main() {
    scanf("%d%d", &n, &W);
    for(int i=1; i<=n; i++) {
        scanf("%d%d%d", &v[i], &w[i], &t[i]);
        if(t[i] == -1) t[i] = W / w[i] + 1; // infinite items
    }
    // 0/1 knapsack
    for(int i=1; i<=n; i++) {
        // multiple items
        for(int k=1; k<=t[i]; k++) {
            for(int j=W; j>=w[i]; j--)
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    printf("%d\n", dp[W]);
    return 0;
}