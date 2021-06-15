/*
***Placing Domino***
    Description:
        Given a "n * m" rectangle, some blocks are black and some are white.
        Calculate the possible ways to place "1 * 2" dominos to cover all 
        white blocks.

    O(n * m * 2^m)
*/
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 15+3;
const int MAX_M = 15+3;

int dp[2][1 << MAX_M];
bool color[MAX_N][MAX_M]; //1: black(cannot place)；0: white(can)
int n, m, Mod;

void solve() {
    for(int i=0; i<2; i++)
        memset(dp[i], 0, sizeof(dp[i]));

    int *cur = dp[0]; //cur[used]: possible results under the circumstance of "used" 當前列的可能數
    int *next = dp[1]; //to record things forwardly 紀錄下一列的可能數
    cur[0] = 1; //initialize

    for(int i=n-1; i>=0; i--) {
        for(int j=m-1; j>=0; j--) {
            //to enumerate 
            for(int used=0; used < 1 << m; used++) {
                //if current palce is used or unable to put a domino
                if((used >> j & 1) || color[i][j]) 
                    next[used] = cur[used & ~(1 << j)];
                else {
                    int res = 0;

                    //horizontal
                    if(j+1 < m && !(used >> (j+1) & 1) && !color[i][j+1])
                        res += cur[used | (1 << (j+1))];
                    //vertical
                    if(i+1 < n && !color[i+1][j])
                        res += cur[used | (1 << j)];
                    
                    next[used] = res % Mod;
                }
               
            }
            //the current "next" is later "cur" (reuse!)
            swap(cur, next);
        }
    }
    printf("%d\n", cur[0]);
}

int main() {
    
    return 0;
}