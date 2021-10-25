/*
***Math*** -- prime, 數論分塊(Fubini's theorem) (*)
    O(N + Q*sqrt(N))
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e7+1;
int cnt[MAX_N]; // 質因數個數
int pow16[8]; // 預先計算 16 的次方
vector<int> prime;

// 每一數字恰出現一次，O(N)
void sieve() {
    // prime.reserve(100000); 
    for(int i=2; i<MAX_N; ++i) {
        if(!cnt[i]) {
            prime.push_back(i);
            cnt[i] = 1;
        }
        for(int pr : prime) {
            if(1LL*pr*i >= 1LL*MAX_N) break;
            /*
                pr*i 會唯一出現，因為 k = pr*i 的質因數的冪次是隨著 i 遞增累積上去的。
                順序:
                    2, 4, 3, 6, 9, 18, 12, 5, 10, 15, 25, 12, 18, 30......
            */
            cnt[pr*i] = cnt[i]; 
            if(i % pr == 0) break; 
            ++cnt[pr*i]; // 如果 i 沒有 pr 這個因數，pr*i 就多了 pr 這個質因數
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    sieve();
    pow16[0] = 1;
    for(int i=1; i<8; ++i) 
        pow16[i] = pow16[i-1] * 16;
    int N, Q;
    cin >> N >> Q;
    while(Q--) {
        int n;
        cin >> n;
        int ans = 0;
        // 數論分塊，以 O(sqrt(n)) 的時間來計算 [n/i](向下取整) 的所有可能
        for(int i=1, x; i<=n; i=x+1) {
            int s = n / i; // 切成幾部分
            /*
                x 為裁剪係數 (每部份的大小)。

                這裡若直接拿 i 當作裁剪係數，時間將會達 O(N)；實際上，對於區間 [l, r]
                符合 [n/l] = [n/r]，我們只需要計算 [n/r] 的值就夠了，[l, r-1] 是可以
                忽略的區間。於是時間可達 O(sqrt(n))

                證明可見: 数论分块（整除分块）学习笔记 (CSDN)
            */
            x = n / s; 
            // 印出來觀察 x 更好理解
            // cout << "x: " << x << '\n'; 
            ans = max(ans, pow16[cnt[s]] + x);
        }
        cout << ans << '\n';
    }
    return 0;
}