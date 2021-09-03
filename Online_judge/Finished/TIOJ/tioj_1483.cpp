/*
***DP / BIT*** (*)
    Description:
        在 R*C 的矩陣中，找出所有使經過且選擇的 a[i][j] 為遞增的路徑。
        (a[i][j] 是題目給的矩陣)
    Solution:
        令 dp[i]][j] 為自左上角走到 (i, j) 且選擇 a[i][j] 的方法數:
            dp[x][y] = ∑dp[i][j]: 1<=i<=x, 1<=j<=y, a[i][j]<a[x][y]
        從遞迴式可以看出，要找出當前的 dp 值，必須求二維的前綴和，而且
        前綴的目標還必須是小於自己的。
            二維前綴和: 二維 BIT
            遞增: 從小到大，一次更新所有相同的值 (並非從左上到右下)
        BIT 的想法可以理解如下:
            當前 dp 加上二維前綴中任一個非零的元素，代表著從那個非
            零元素所在處，移動至當前位置，過程中沒有取新的元素。
            +1 代表的意義就是不取前綴中任何值，直接走到當前位置。
    O(RC logRlogC)
*/
#include <bits/stdc++.h>
using namespace std;

const int R = 1005, MOD = 1e9+7;
struct P { int x, y; };
int t, r, c;
int dp[R][R], bit[R][R];
// 為了使 BIT 的更新由小到大，索引用值而非座標
vector<P> v[R]; 

void init() {
    memset(bit, 0, sizeof(bit));
    for(int i=0; i<R; ++i) v[i].clear();
}
void update(int x, int y, int val) {
    for(int i=x; i<=r; i+=i&-i)
        for(int j=y; j<=c; j+=j&-j)
            bit[i][j] = (bit[i][j]+val)%MOD;
}
int query(int x, int y) {
    int res = 0;
    for(int i=x; i>0; i-=i&-i) 
        for(int j=y; j>0; j-=j&-j)
            res = (res+bit[i][j])%MOD;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        init();
        cin >> r >> c;
        for(int i=1; i<=r; ++i) {
            for(int j=1; j<=c; ++j) {
                int x; cin >> x;
                v[x].push_back(P{i, j});
            }
        }
        for(int x=0; x<R; ++x) if(!v[x].empty()) {
            for(auto p : v[x]) dp[p.x][p.y] = query(p.x, p.y)+1;
            for(auto p : v[x]) update(p.x, p.y, dp[p.x][p.y]);
        }
        int ans = 0;
        // dp[i][j] 在 (i, j) 之後就都不選了，這也是合法的
        for(int i=1; i<=r; ++i) 
            for(int j=1; j<=c; ++j) 
                ans = (ans+dp[i][j])%MOD;
        cout << ans << '\n';
    }
    return 0;
}