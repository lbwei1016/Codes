/*
預處理 d: 字串間的距離關係 (要多多少才能把 i 變成 j)
d[i][j][0]: string 'i' 接在 string 'j' 前面
d[i][j][1]:                            後面
先判斷是否具包含關係，再檢查前、後綴
d 未必對稱

dp[S][v][0] = min(dp[S][v][], dp[S \union u][u][0] + d[u][v][0]) 
dp[S][v][1] 同理

dp[S][u][0]: u 在整個 string 的頭

把完全被包含的清除
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
// #pragma GCC optimize("O3,unroll-loops")
using namespace std;
using ll = long long;

const int N = 7, INF = 1e9+7;
int n;
int d[N][N][2]; // distance
int dp[1 << N][N][2]; // 7e6, good
string S[N];
// string str[1 << N][N];
// deque<int> dq[1 << 7][7][2];
int nei[1 << N][N][2];

void init() {
    for (int i=0; i<n; ++i) 
        for (int j=0; j<n; ++j) 
            d[i][j][0] = d[i][j][1] = INF;
    for (int i=0; i<(1<<n); ++i) 
        for (int j=0; j<n; ++j) 
            dp[i][j][0] = dp[i][j][1] = INF;
}

void precalc() {
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
        d[i][j][0] = d[i][j][1] = INF;
        // if (i == j) {
            // d[i][j][0] = d[i][j][1] = S[i].size();
        // }
    }

    vector<int> redund;
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            if (S[i].find(S[j]) != string::npos) {
                d[i][j][0] = d[i][j][1] = 0;
                d[j][i][0] = d[j][i][1] = S[i].size() - S[j].size();
                redund.push_back(j);
            }
            else if (S[j].find(S[i]) != string::npos) {
                d[j][i][0] = d[j][i][1] = 0;
                d[i][j][0] = d[i][j][1] = S[j].size() - S[i].size();
                redund.push_back(i);
            }
            else {
                int len = min(S[i].size(), S[j].size());
                int li = S[i].size(), lj = S[j].size();
                for (int k=len; k>=1; --k) {
                    // 'i' cat 'j'
                    string r = string(S[i].begin()+li-k, S[i].end()), rr = S[j].substr(0, k);
                    if (r == rr) {
                        d[i][j][0] = lj - k;
                        d[j][i][1] = li - k;
                        break;
                    }
                }
                for (int k=len; k>=1; --k) {
                    // 'j' cat 'i'
                    string r = string(S[j].begin()+lj-k, S[j].end()), rr = S[i].substr(0, k);
                    if (r == rr) {
                        d[j][i][0] = li - k;
                        d[i][j][1] = lj - k;
                        break;
                    }
                }

                if (d[i][j][0] == INF) {
                    d[i][j][0] = lj;
                    d[j][i][1] = li;
                }
                if (d[j][i][0] == INF) {
                    d[j][i][0] = li;
                    d[i][j][1] = lj;
                }
            }
        }
    }

    // erase redundant terms (fully contained by another string)
    sort(redund.begin(), redund.end());
    redund.resize(unique(redund.begin(), redund.end()) - redund.begin());
    for (int i=0; i<n; ++i) {
        if (find(redund.begin(), redund.end(), i) != redund.end()) continue;
        int off = lower_bound(redund.begin(), redund.end(), i) - redund.begin();
        for (int j=0; j<n; ++j) {
            if (find(redund.begin(), redund.end(), j) != redund.end()) continue;
            int off2 = lower_bound(redund.begin(), redund.end(), j) - redund.begin();
            d[i-off][j-off2][0] = d[i][j][0];
            d[i-off][j-off2][1] = d[i][j][1];
        }
        S[i-off] = S[i];
    }
    n -= redund.size();
}

int main() {
    io;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> S[i];
    }
    init();
    precalc();

    dp[(1 << n)-1][0][0] = dp[(1 << n)-1][0][1] = 0;
    // 誰該當起點 ? 不同起點會影響答案嗎 ?
    // TSP 的 statement 是計算 cycle，而 cycle 中任一點都可以做為起點而走經相同路徑。
    // 所以只要把 cycle 拔掉一條邊，就好

    for (int G=(1<<n)-2; G>=0; --G) {
        for (int u=0; u<n; ++u) {
            // if (!((G >> u) & 1)) continue; // good?
            for (int v=0; v<n; ++v) {
                // 'v' unvisited
                if (!((G >> v) & 1)) {
                    int H = G | (1 << v);
                    for (int i=0; i<2; ++i) {
                        if (dp[H][v][i] + d[u][v][i] < dp[G][u][i]) {
                            // cout << "cool" << u << ' ' << v << '\n';
                            dp[G][u][i] = dp[H][v][i] + d[u][v][i];
                            nei[G][u][i^1] = v;
                            // if (i & 1) {
                            //     // dq[G][u][i] = dq[H][v][i];
                            //     // dq[G][u][i].push_back(u);
                            // }
                            // else {
                            //     // dq[G][u][i] = dq[H][v][i];
                            //     // dq[G][u][i].push_front(u);
                            // }
                        }
                    }
                }
            }
        }
    }

    cout << dp[0][0][0] << ' ' << dp[0][0][1] << '\n';
    // for (auto c: dq[0][0][0]) cout << c << ' ';
    cout << '\n';

    int at = 0;
    int R = 0;
    cout << "0 ";
    while (R < (1<<n)-2) {
        cout << nei[R][at][1] << ' ';
        // int tmp = at;
        at = nei[R][at][1];
        R |= (1 << at);
        // ++R;
    }
    // for (auto c: dq[0][0][1]) cout << c << ' ';

    cout << '\n';

    for (int i=0; i<n; ++i) cout << S[i] + '\n';

    return 0;
}
// char *s = "detaomegaisus";
/*
3
aaabc
abc
bccfd

7
det
ta
omega
sus
is
deta
detaomega

3
sus
is
detaomega

5
abhdkdg
sgkj
hdk
dgitowdabhd
kjjdj


dgitowdabhdkdgsgkjjdj
*/