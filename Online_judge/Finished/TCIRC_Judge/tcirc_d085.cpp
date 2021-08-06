/*
***DP***
    Description:
        令 p(i,j) = 在 [1,j] 區間內完成不超過 i 次買賣的最大獲利，則
        p(i,j) = max{ c[j]-c[t]+p(i-1,t-1): for all t<j }
    Solution:
        想法一：列舉所有情形，找出使任意 j 最大的 t，O(k*n^2)，不行。
        想法二：對 j 同時找出最小的 c[t] 以及最大的 p(i-1,t-1)，但無法同時維護兩者。
        想法三：
            重新檢視遞迴式: c[j] + {p(i-1,t-1) - c[t]}，選擇 t 之時即減去 c[t]。
        因此，只需要維護「最大可選的 p(i-1,t-1) - c[t]」即可，而選擇會因 j 遞
        增而改變（可以選擇更有優勢的）。
            使用 deque 來儲存「p(i-1,t-1) - c[t] 的遞增序列」，理由：隨著 j 遞增，
        可選擇的前置狀態增加，因此，若前面的狀態較後方新加入的狀態差，是可以捨棄的；
        結果就是，deque 不論是 val 還是 r 皆為遞增的。
            另外，因為計算方式為將買賣次數累積計算 (1~k)，dp 陣列本該是二維陣列，
        但我們只需要使用到前一次買賣 (前一列) 的資訊，並且前一列的資訊已經依遞增的順序
        存於 deque 之中，因此一維陣列就夠了。
    
    O(k * n)
*/
#include <bits/stdc++.h>
using namespace std;

struct P { int val, r; };
int n, k;
vector<int> p; //price
deque<P> pre_mx; //increasing sequence of: dp[i-1][t-1] - p[t]
int dp[100005]; //int dp[105][100005]

void put_max(P p) {
    if(!pre_mx.empty() && pre_mx.back().val > p.val) {
        return;
    }
    pre_mx.push_back(p);
}
int main() {
    scanf("%d%d", &n, &k);
    p.resize(n+5);
    for(int i=1; i<=n; i++) {
        scanf("%d", &p[i]);
        put_max(P{-p[i], i});
    }
    for(int i=1; i<=k; i++) {
        P prev = pre_mx.front(); 
        pre_mx.pop_front();
        for(int j=1; j<=n; j++) {
            //if a better condition is available
            if(!pre_mx.empty() && j > pre_mx.front().r) {
                prev = pre_mx.front();
                pre_mx.pop_front();
            }
            dp[j] = max(dp[j-1], p[j]+prev.val);
        }
        pre_mx.clear();
        for(int j=1; j<=n; j++) {
            put_max(P{dp[j-1]-p[j], j});
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}