/*
***LPS*** --Longest Palindromic Subsequence

    O(size(str) ^ 2)
*/
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 1000+5;
int dp[MAX_N]; //str[1] ~ str[i] 的最大迴文子字串長度
char str[MAX_N];
int n;
//檢查是否迴文(palindrome)
int pal(int L, int R) {
    int l = L, r = R;
    while(l < r) {
        if(str[l++] != str[r--]) return 0;
    }
    return (R-L+1);
}

int main() {
    scanf("%d", &n);
    while(n--) {
        int i, mx = 0;
        char res[MAX_N]; 
        memset(dp, 0, sizeof(dp));
        scanf("%s", str+1); //從一開始
        //從左到右
        for(i=1; str[i]; i++) { 
            for(int j=1; j<=i; j++) {
                //檢查 str[j] ~ str[i] 是否迴文
                int len = pal(j, i);
                if(dp[i] < len) {
                    dp[i] = len;
                    if(dp[i] > mx) {
                        memset(res, 0, sizeof(res));
                        memcpy(res, str+j, len);
                        mx = dp[i];
                    }
                }
            }
        }
        printf("%s\n", res);
    }
    
    return 0;
}