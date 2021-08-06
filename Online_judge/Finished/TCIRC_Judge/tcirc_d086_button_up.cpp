/*
***DP*** -- top-down
    Solution:
        以矩陣為主體。
        在範圍 [i, j] 內，選擇 for all k such that i<=k<j，該 k 即是代表最後
        一次乘法發生的位置，將乘法鍊拆成兩半，也就是說，這個遞迴式是倒著做的：
        不斷試驗乘法鍊的可能最後一次乘法結果，再取最小值。
    O(n^3)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int main() {
    int n;
    int p[N];
    int sum[N][N] = {0};
    scanf("%d", &n);
    for(int i=0; i<n+1; i++) {
        scanf("%d", &p[i]);
    }
    for(int len=1; len<n; len++) {
        //sum(i, i+len)
        for(int i=0; i+len<n; i++) {
            int j = i + len, mn = 1e9;
            for(int k=i; k<j; k++) {
                //p[i]*p[k+1]*p[j+1]: row(i) * col(k) * col(j)
                mn = min(mn, sum[i][k]+sum[k+1][j]+p[i]*p[k+1]*p[j+1]);
            }
            sum[i][j] = mn;
        }
    }
    printf("%d\n", sum[0][n-1]);
    return 0;
}
/* 另一種寫法 (畫方格圖驗證)
//結束點逐漸往後推
for(int j=1; j<n; j++) {  
    //開始點往前推 (長度變長)
    for(int i=j-1; i>=0; i--) {
        int mn = 1e9;
        //列舉截斷點
        for(int k=i; k<j; k++) {
            mn = min(mn, sum[i][k]+sum[k+1][j]+p[i]*p[k+1]*p[j+1]);
        }
        sum[i][j] = mn;
    }
}
*/