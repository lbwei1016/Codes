/*
 -- bits, LCP
    Description:
        對數字 A 進行以下三個操作之一，計算花最少的操作次數使 A 變成 B
            1. 乘 2 加 1
            2. 乘 2
            3. 除以 2 (floor)
    Solution:
        上述的三個操作，轉成二進位來看，其實就是
            1. 在尾端加 1
            2. 在尾端加 0 
            3. 去除尾端位元
        因此，三個操作會影響的只有尾端的位元；若要最小化操作次數，必須找出
        兩數的位元的 LCP (Longest Common Prefix)。實作上就是把 A 不斷右移
        直到兩數的 LCP，再補上尾端的位元變成 B 就好。其實可以把「補上尾端的位元變成 B」
        的步驟反過來，變成從 B 開始逐一刪除尾端位元。這樣可以得到一個單純的
        演算法: 重複比較 A 和 B 誰比較大，比較大的向右移 1 位元 ，直到相同為止。
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll a, b, cnt = 0;
    scanf("%lld%lld", &a, &b);
    while(a != b) {
        if(a > b) a >>= 1;
        else b >>= 1;
        ++cnt;
    }
    printf("%lld\n", cnt);
    return 0;
}