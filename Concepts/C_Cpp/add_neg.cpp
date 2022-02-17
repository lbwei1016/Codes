#include <bits/stdc++.h>
using namespace std;

// 加法 (without operator +)
int add(int a, int b) {
    if(!(a & b)) return a | b;
    return add(a^b, (a&b)<<1);

    /* 
        XOR 得到兩數非共通的 1-bit, 
        AND 得到兩數共通的的 1-bit -> 進位 (<<1)

        遞迴向下，至最終沒有共通的的 1-bit 時直接以 OR 實現加法
    */
}

int neg(int n) {
    int lowbit = n & -n, pos = 0;
    for(int i=lowbit; i>0; i>>=1) ++pos;
    return (((~n)>>pos)<<pos) | lowbit;

    /*
        lowbit 以下不變，以上則反轉 (2's complement)
    */
}

int main() {
    int n; cin >> n;
    int lowbit = n & -n, pos = 0;
    for(int i=lowbit; i>0; i>>=1) ++pos;
    int neg_n = neg(n);
    if(neg_n == -n) cout << "Yes! " << neg_n << '\n';
    else cout << neg_n;

    int a, b;
    cin >> a >> b;
    cout << add(a, b) << '\n';
    return 0;
}