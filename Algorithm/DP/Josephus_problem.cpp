/*
***Josephus problem***

    Description:
        求最後的存活者。

        進階：求第 k 位被殺的人

    Solution: (0-indexed)
        當 N 人圍成一圈，每 M 人一數，每次被殺的人編號為：(M-1) mod N。
        假設最後存活者的編號為 f(N)。當編號 M-1 的人被殺後，讓剩餘的 N-1 人重新編號如下：
            M -> 0
            M+1 -> 1
            ...
            0 -> N-M
            ...
            M-3 -> N-3
            M-2 -> N-2
        則原先 N-環的存活者 f(N) = (f(N-1) + M) mod N，以此類推，而 f(1) = 0。
        （試著畫圖看看）（遞迴式由上述箭頭右方往左方逆運算即可得出）

    進階：
        當 N 人圍成一圈，每 M 人一數，第 k 位被殺的人即為：N-(k-1) 人圍成一圈時，
        第一位被殺的人，其編號：(M-1) mod N-(k-1)，再由上述推導之遞迴式即可算出
        第 k 位被殺的人在 N 人圍成一圈時的編號。

    O(N) / O(K)
*/
#include <iostream>

using namespace std;

const int MAX_N = 100;

int N, M, K;
int dp[MAX_N];

//0-indexed
//O(N)
void josephus() {
    dp[0] = dp[1] = 0;
    for(int i=2; i<=N; i++) {
        dp[i] = (dp[i-1] + M) % i;
    }
    //1-indexed
    for(int i=1; i<=N; i++) {
        printf("Kill %d: %d\n", i-1, dp[i]+1);
    }
}
//O(K)
void josephus_k_th() {
    int Nk = N - (K-1);
    int k_th = (M-1) % Nk;
    for(int i=Nk+1; i<=N; i++) {
        k_th = (k_th + M) % i;
    }
    /* 
        For more concise:
            int k_th = -1;
            for(int i=N-K+1; i<=N; i++) {
                k_th = (k_th + M) % i;
            }
    */
    cout << k_th+1 << '\n';
}

int main() {
    cout << "Input how many people in a circle, and the count to kill:\n";
    cin >> N >> M;
    
    cout << "The survivors are:\n";
    josephus();

    cout << "Input the K-th person to die:\n";
    cin >> K;
    josephus_k_th();
    
    return 0;
}