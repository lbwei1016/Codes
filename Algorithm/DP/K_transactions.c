/*
***DP*** 
    Description:
        Do at most k transactions (buy and sell) to gain maximum profit.
    O(k * n)
*/
#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define N 1005

// Actually buy[] and sell[] are 2D, but they only use "i-1" at i；so memory can be reused. 
// buy[i][j]: the maximum value for: at day i, stock i is bought, and k transactions has been done
// sell[i][j]: the maximum value for: at day i, stock i is sold, and k transactions has been done

int buy[N]; 
int sell[N];

int main() {
    int n, k, price[N];
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; ++i) scanf("%d", price+i);
    
    /*
        Consider the situation when sell[j-1] = 0, which means no transactions so far.
        If you want to buy item "i", the equation: "buy[j] = max(buy[j], sell[j-1]-price[i])"
        would be "buy[j] = max(0, -price[i])", which means you can never buy item "i"!
        Hence, buy[] have to initialized with -INF to ensure every item can be the first item 
        bought.
    */
    for(int i=0; i<=k; ++i) buy[i] = -1e9;
    // count "buying" a transaction
    for(int i=0; i<n; ++i) {
        for(int j=1; j<=k; ++j) {
            buy[j] = max(buy[j], sell[j-1]-price[i]); // buy item i or not
            sell[j] = max(sell[j], buy[j]+price[i]); // sell item i or not
        }
    }
    printf("%d", sell[k]); // sell > buy
    return 0;
}