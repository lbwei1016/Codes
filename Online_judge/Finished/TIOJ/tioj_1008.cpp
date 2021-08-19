/*
***BFS (隱式圖) / Hash***
    Solution:
        考慮到最大情況: 有五個量杯，容量五十，因此總狀態數 50^5；
        狀態數太多無法以一般陣列處理，所以必須 hash，有兩種方法:
            方法一:
                利用進位制的想法，建立一 51 進位的數 => a*51^4 + b*51^3 ...，
                其中係數 a, b, c, d, e 就代表各量杯的水量。
            方法二: 
                每 6 (2^6-1 = 63 > 51) bits 表示一個量杯的水量，共 30 bits，因此
                只需一個 int 即可。
            狀態壓縮完之後再將各個狀態丟入 std::unordered_set 中，判斷該狀態是否出現過。
        接著就是 BFS 了。
*/
#include <bits/stdc++.h>
using namespace std;

// a[]: 即將進行 (或已經做完) 某一動作的水量
// b[]: 當前水量
int n, cap[6], k, a[6], b[6], ans;
queue<int> que;
unordered_set<int> S; 

// hash
void encode() {
    int s = 0;
    for(int i=n-1; i>=0; --i) {
        s <<= 6;
        s |= a[i];
    }
    if(S.count(s)) return;
    S.insert(s);
    que.push(s);
}
// 轉換為水量
void decode() {
    int x = que.front(); que.pop();
    for(int i=0; i<n; ++i) {
        b[i] = x & 63; x >>= 6; // 63: 0b111111
    }
}
int main() {
    scanf("%d", &n);
    int mx = 0;
    for(int i=0; i<n; ++i) {
        scanf("%d", cap+i);
        mx = max(mx, cap[i]);
    }
    scanf("%d", &k);
    /*
        量杯倒來倒去，其實就是各自的容量在相加減，因此實際上可以把這一連串的動作
        表示為多元一次方程式。若所求的量 k 無法整除所有容量的 GCD (整係數方程式=分數)
        ，那麼方程式將沒有整數解，也就是並不存在這樣的操作方式。
    */
    int GCD = cap[0];
    for(int i=1; i<n; ++i) GCD = __gcd(GCD, cap[i]);

    if(k <= mx && k%GCD == 0) {
        encode();
        while(!que.empty()) {
            ++ans;
            int sz = que.size();
            while(sz--) {
                decode(); // 取出一狀態，更新 b[]
                for(int i=0; i<n; ++i) {
                    if(b[i] == k) {
                        printf("%d\n", ans - 1);
                        return 0;
                    }
                    a[i] = b[i];
                }
                for(int i=0; i<n; ++i) {
                    a[i] = cap[i]; encode(); // 注滿
                    a[i] = 0; encode(); // 倒空
                    a[i] = b[i]; // 回復
                }
                for(int i=0; i<n; ++i) {
                    for(int j=0; j<n; ++j) {
                        if(i == j) continue;
                        a[i] = max(b[i]+b[j]-cap[j], 0); // 倒到另一個量杯 (i -> j)
                        a[j] = min(cap[j], b[i]+b[j]);
                        encode();
                        a[i] = b[i], a[j] = b[j]; // 回復
                    }
                }
            }
        }
    }
    puts("-1");
    return 0;
}