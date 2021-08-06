/*
***DP***
    Description:
        求取圖形中由 1 構成的最大矩形面積
    Solution:
        自左上角開始，記錄每行連續的 1 的數目(len[])，並不斷往左更新接壤的面積(k = j-1, k--)

    O(M * N^2)
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N_M = 200+5;

int M, N;
int G[MAX_N_M][MAX_N_M]; //0 or 1
int len[MAX_N_M]; //記錄至該列為止，共有多少連續的 1

void solve() {
    int res = 0;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            len[j] = G[i][j] ? len[j]+1 : 0;
            int p = len[j]; //當面積為 1*len[j] (垂直向的矩形)
            res = max(res, p);
            for(int k=j-1; k>=0 && G[i][k]; k--) {
                p = min(p, len[k]); //取較小值才會是完整的矩形
                res = max(res, p * (j-k+1)); //(j-k+1) 是矩形的寬
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> M >> N) {
        memset(G, 0, sizeof(G));
        memset(len, 0, sizeof(len));
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                cin >> G[i][j];
            }
        }
        solve();
    }
    
    return 0;
}