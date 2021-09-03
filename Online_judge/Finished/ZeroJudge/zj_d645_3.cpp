/* 
***DP*** -- Bounded Knapsack (單調隊列優化) 
(https://www.cnblogs.com/GXZC/archive/2013/01/08/2851153.html) (/competitive_programming/背包問題.pdf)
    Solution:
        利用 W / w[i] 相同餘數時重複轉移的特性，進行優化，詳見上述資源。
    Note:
        與「二進制拆分」--O(N*W logT)-- 相比，若物品重 (w[i]) 偏大 (W/w[i] < 100)，以至於重複選到同一物品
        的機會很小；此時即使 T 很大，但 logT 的實際值很小 (因為邊界優化)，因此複雜度接近 O(N*W)，與
        本優化相同。但是「二進制拆分」還有一個優點是常數較小，所以在這種情況下通常會比「單調隊列優化」
        還要快上不少 (超過 7 倍)。
        但是當物品重極小 (W/w[i] > 1e4)，重複選到同一物品的機會極大，則「單調隊列優化」就比「二進制拆分」快 
        2.1 倍 (自製 deque) / 1.3 倍 (std::deque)；若 「W/w[i] > 1e5」，則是 3.5 倍 (自製) / 3.4 倍 (std::deque)

        經過少次觀察，若「W / w[i]」越大，「單調隊列優化」越有利，反之則「二進制拆分」有利。
    O(N * W)
    N: 物品種類；W: 可容納重
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_W = 1000;
struct Pack { int sum, val; };
int n, W, v, w, t, dp[MAX_W+5];
// deque<Pack> dq; 
Pack dq[2*MAX_W];

int main() {
    scanf("%d%d", &n, &W);
    for(int i=0; i<n; ++i) {
        scanf("%d%d%d", &v, &w, &t);
        if(t == -1) t = W/w;
        else t = min(t, W/w);
        for(int j=0; j<w; ++j) {
            // dq.clear(); 
            int head = 0, tail = 0;
            for(int k=0; k<=(W-j)/w; ++k) {
                int val = dp[w*k + j] - v*k;
                // while(dq.size() && dq.back().val<val) dq.pop_back();
                // dq.push_back({k, val});
                // // 超過可以拿取的數量
                // if(k > dq.front().sum+t) dq.pop_front();
                // dp[w*k + j] = dq.front().val + v*k;
                while(head<tail && dq[tail-1].val<val) --tail;
                dq[tail++] = {k, val};
                if(k > dq[head].sum+t) ++head;
                dp[w*k + j] = dq[head].val + v*k;
            }
        }
    }
    printf("%d\n", dp[W]);
    return 0;
}