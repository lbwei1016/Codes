/*
***LPS*** --Longest Palindromic String

    O(size(str) ^ 2 * LPS) (實際更佳)
*/
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 1e6+5;
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
    int mx = 0;
    char res[MAX_N]; 
    scanf("%s", str+1); //從一開始
    //從左到右
    for(int i=1; str[i]; i++) { 
        for(int j=1; j<=i; j++) {
            //檢查 str[j] ~ str[i] 是否迴文
            int len = pal(j, i);
            if(len > mx) {
                memset(res, 0, sizeof(res));
                memcpy(res, str+j, len);
                mx = len;
            }
        }
    }
    printf("%s\n", res);
    return 0;
}