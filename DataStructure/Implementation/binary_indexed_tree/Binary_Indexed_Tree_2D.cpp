/*
***BIT*** -- two-dimensional
    Description:
        每一列自成 BIT，而每一行也是 BIT。
        令原矩陣 A[][]，BIT 矩陣 B[][]:
            B[1][1] = A[1][1], B[1][2] = A[1][1]+A[1][2]...... -- a BIT
            B[2][1] = B[1][1]+A[2][1], B[2][2] = B[1][2]+B[2][1]+A[2][2]...... -- 鉛直方向也是 BIT
        簡單來說，B[i][j] 就是 "i 方向的 BIT + j 方向的 BIT" !
        可以推廣到更高維度。
    Complexity:
        複雜度就是一維的 D (維度) 次方。
        若要求取任意子矩陣 (非前綴)，需要排容原理: O(2^D (logn)^D)
*/
#include <bits/stdc++.h>
using namespace std;

const int M = 3, N = 5;
int arr[M+1][N+1];
int bit[M+1][N+1];

// 單點修改數值: O((logn)^2)
void update(int x, int y, int val) {
    for(int i=x; i<=M; i+=(i&-i)) {
        for(int j=y; j<=N; j+=(j&-j)) {
            bit[i][j] += val;
        }
    }
}
// 查詢 [1, 1] 到 [x, y] 矩形的和 (前綴和): O((logn)^2)
int query(int x, int y) {
    int res = 0;
    for(int i=x; i>0; i-=(i&-i)) {
        for(int j=y; j>0; j-=(j&-j)) {
            res += bit[i][j];
        }
    }
    return res;
}
// 初始化 BIT: O(MN)
void build() {
    memcpy(bit, arr, (M+1)*(N+1)*sizeof(int));
    for(int i=1; i<=M; ++i) {
        // 先行的 BIT，再列的 BIT，否則會重複算
        int x = i + (i&-i);
        if(x <= M) {
            for(int j=1; j<=N; ++j) {
                bit[x][j] += bit[i][j];
            }
        }
        for(int j=1; j<=N; ++j) {
            int y = j + (j&-j);
            if(y > N) break;
            bit[i][y] += bit[i][j];
        }
    }
}
// 求取任意子矩陣 (非前綴): O(2^2 (logn)^2)
// 左上右下
int arb_query(int x1, int y1, int x2, int y2) {
    // draw
    return query(x2, y2)-query(x1-1, y2)-query(x2, y1-1)+query(x1-1, y1-1);
}
int main() {
    int x, y, x1, y1, x2, y2;
    for(int i=1; i<=M; ++i) {
        for(int j=1; j<=N; ++j) {
            cin >> arr[i][j];
            // update(i, j, arr[i][j]);
        }
    }
    build();
    // while(cin >> x >> y) cout << query(x, y) << '\n';
    while(cin >> x1 >> y1 >> x2 >> y2) 
        cout << arb_query(x1, y1, x2, y2) << '\n';
    return 0;
}
/*
1 2 3 4 5
8 0 14 2 9
-7 13 7 2 1
*/