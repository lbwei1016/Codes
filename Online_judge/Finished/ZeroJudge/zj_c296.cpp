/*
***Josephus problem***

    Description:
        約瑟夫問題的推廣，求第 K 位被殺死的人的安全的下一位，即「幸運之人」
    
    Solution:（0-indexed 較方便）
        若使用佇列模擬，複雜度高（程式碼在下方）。另一解法如下：
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

            而「第 K 位被殺的人」即為：N-(K-1) 人圍成一圈時，
            第一位被殺的人，其編號：(M-1) mod N-(K-1)，再由上述推導之遞迴式即可算出
            第 K 位被殺的人在 N 人圍成一圈時的編號。

            本題所求的幸運者，其實就是當圓圈大小為　N-(K-1) 人時，第一位被殺的人的下一位，
            其當下編號即為 (M-1 + 1) mod N-(K-1) = M mod N-K+1，再依上述方法回溯即可求解。
    
    O(K)
*/
#include <bits/stdc++.h>

using namespace std;

int N, M, K;

void josephus_k() {
    // int Nk = N - (K-1);
    // int luc = (M-1+1) % Nk;
    // for(int i=Nk+1; i<=N; i++) {
    //     luc = (luc + M) % i;
    // }
    int luc = 0;
    for(int i=N-K+1; i<=N; i++) {
        luc = (luc + M) % i;
    }
    cout << luc+1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    josephus_k();
    
    return 0;
}
/*
void simulation() {
    queue<int> que;
    for(int i=1; i<=N; i++) {
        que.push(i);
    }

    int k = 0, m = 0;
    while(true) {
        for(int i=0; i<que.size(); i++) {
            int t = que.front(); que.pop();
            m++;
            if(m != M) que.push(t);
            else {
                k++;
                m = 0;
                if(k == K) {
                    cout << que.front() << '\n';
                    return;
                }
            }
        }
    }
}
*/