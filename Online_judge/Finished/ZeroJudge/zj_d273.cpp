/*
***DP*** -- UVa11584
    Description:
        最長迴文子字串

    O(size(str) ^ 2)
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000+5;
int dp[MAX_N]; //str[1] ~ str[i] 的最小的迴文子字串數量
char str[MAX_N];
int n;
//檢查是否迴文
bool pal(int L, int R) {
    while(L < R) {
        if(str[L++] != str[R--]) return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    while(n--) {
        int i;
        fill(dp, dp+MAX_N, 0x7fffffff);
        dp[0] = 0;
        scanf("%s", str+1); //從一開始
        //從左到右
        for(i=1; str[i]; i++) { 
            for(int j=1; j<=i; j++) {
                //檢查 str[j] ~ str[i] 是否迴文
                if(pal(j, i)) {
                    /*
                        dp[j-1] + 1: 
                            已知 str[i] ~ str[j] 為迴文，則此式代表採納 str[i] ~ str[j] 
                            這段作為迴文子字串
                    */
                    dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        }
        printf("%d\n", dp[i-1]);
    }
    
    return 0;
}