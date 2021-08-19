/*
***DP*** -- bits
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[1<<21];
int t, n, R[22][22];

void init() {
    fill(dp, dp+(1<<21), 1e9);
    memset(R, 0, sizeof(R));
}
int main() {
    scanf("%d", &t);
    while(t--) {
        init();
        scanf("%d", &n);
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                scanf("%d", &R[i][j]);
            }
        }
        dp[0] = 0;
        int S = 1<<n;
        // 只有 1 的位元數為三的倍數的才需要更新
        for(int s=0; s<S; ++s) if(dp[s] < INF) {
            /*
            ___builtin_ctz(): 返回右起第一個 1 右邊的 0 的個數。
                這裡先取 not，因此 i 的意義就變成「右起第一個 0 右邊的 1 的個數」。
                不需要多跑一個 i 的迴圈，因為即使是迴圈也只會從第一個非 1 的位元開始，
                而第二以後的非 1 位元可以藉由外層的 s 來列舉，因此更新到的狀態數不變。
            */
            int i = __builtin_ctz(~s);
            for(int j=i+1; j<n; ++j) if(!(s & (1<<j))) {
                for(int k=j+1; k<n; ++k) if(!(s & (1<<k))) {
                    dp[s|(1<<i)|(1<<j)|(1<<k)] = min(dp[s|(1<<i)|(1<<j)|(1<<k)], \
                                    dp[s]+R[i][j]+R[j][k]+R[k][i]);
                }
            }
        }
        printf("%d\n", dp[S-1]);
    }    
    return 0;
}