#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
// #pragma GCC optimize("O3,unroll-loops")
using namespace std;
using ll = long long;

const int N = 18, INF = 1e9+7;
int n;
int d[N][N][2]; // distance
int dp[1 << N][N][2]; // 7e6, good
string S[N];
// int pre[1 << N][N][2];

struct MNS {
    int at, dir;
};

struct PREV {
    int G, v;
} pre[1 << N][N];

void init() {
    for (int i=0; i<n; ++i) 
        for (int j=0; j<n; ++j) 
            d[i][j][0] = d[i][j][1] = INF;
    for (int i=0; i<(1<<n); ++i) 
        for (int j=0; j<n; ++j) 
            dp[i][j][0] = dp[i][j][1] = INF;
    memset(pre, -1, sizeof(pre));
}

void precalc() {
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
        d[i][j][0] = d[i][j][1] = INF;
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

// string toString(deque<int> &v, const int &dir) {
//     string s = S[v[0]];
//     for (int i=1; i<n; ++i) {
//         int i0 = v[i-1], i1 = v[i];
//         if (dir) {
//             string r = S[v[i]].substr(S[v[i]].size() - d[i0][i1][0]);
//             s += r;
//         }
//         else {
//             string r = S[v[i]].substr(0, d[i0][i1][1]);
//             s += r;
//         }
//     }
//     return s;
// }

int main() {
    io;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> S[i];
    }
    init();
    precalc();

    dp[(1 << n)-1][0][0] = dp[(1 << n)-1][0][1] = 0;

    for (int G=(1<<n)-2; G>=0; --G) {
        for (int u=0; u<n; ++u) {
            for (int v=0; v<n; ++v) {
                // 'v' unvisited
                if (!((G >> v) & 1)) {
                    int H = G | (1 << v);
                    for (int i=0; i<2; ++i) {
                        if (dp[H][v][i] + d[u][v][i] < dp[G][u][i]) {
                            dp[G][u][i] = dp[H][v][i] + d[u][v][i];
                            if (i == 0)
                                pre[G][u] = {H, v};
                        }
                        // else if (dp[H][v][i] + d[u][v][i] == dp[G][u][i]) {
                        //     if (d[u][v][i] == INF) continue;
                        //     auto p = pre[G][u];
                        //     // string s1 = S[p.v].substr(S[p.v].size() - d[u][p.v][i]);
                        //     // string s2 = S[v].substr(S[v].size() - d[u][v][i]);

                        //     // if (s2 < s1) pre[G][u] = {H, v};
                        //     int val1 = 0, val2 = 0;
                        //     for (int j=0; j<n; ++j) {
                        //         if (j == u) continue;
                        //         val1 = max(val1, int(S[j].size() - d[p.v][j][0]));
                        //         val2 = max(val2, int(S[j].size() - d[v][j][0]));
                        //     }

                        //     if (val1 > val2) pre[G][u] = {H, v}; // p.v 接在其他人前面效益較高
                        // }
                    }
                }
            }
        }
    }

    /*
        10/16 結論:
            用 backtracking 找點是可行的，但那對於 lexi. 沒有幫助，
            因為每次紀錄都是局部最佳，會掩蓋掉 lexi. min。可以一試的
            解法是: 特判完全無交集的字串，並將他們排序，在任意插入到
            固定的 chain 中。
    */

    // cout << "length: " << dp[0][0][0] << '\n';
    int x = 0, y = 0;
    vector<int> cyc;
    while (true) {
        // cout << x << ' ' << y << '\n';
        int t1 = x;
        x = pre[x][y].G;
        y = pre[t1][y].v;
        if (y == -1) break;
        cyc.push_back(y);
    }   
    // reverse(cyc.begin(), cyc.end());
    // for (auto x: cyc) cout << x << '\n';

    vector<string> comb;
    string cur = S[cyc[0]];
    for (int i=0; i<cyc.size()-1; ++i) {
        if (d[cyc[i]][cyc[i+1]][0] < S[cyc[i+1]].size()) {
            cur += S[cyc[i+1]].substr(S[cyc[i+1]].size() - d[cyc[i]][cyc[i+1]][0]);
        }
        else {
            comb.push_back(cur);
            cur = S[cyc[i+1]];
        }
    }

    if (d[cyc.back()][cyc[0]][0] < S[cyc[0]].size()) {
        comb[0] = cur + comb[0].substr(S[cyc[0]].size() - d[cyc.back()][cyc[0]][0]); 
    }
    else comb.push_back(cur);

    sort(comb.begin(), comb.end());
    for (auto x: comb) cout << x;

    // for (int i=0; i<n; ++i) {
    //     for (int j=0; j<n; ++j) {
    //         assert(d[i][j][0] >= 0);
    //     }
    // }

    return 0;
}