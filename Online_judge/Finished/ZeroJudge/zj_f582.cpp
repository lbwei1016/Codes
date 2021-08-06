/*
***DP*** 
    Reference: https://yuihuang.com/zj-f582/
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int n, m, root;
int dp[1005][85][5]; //dp[n][m][sym]: 第 n 個序列、第 m 個字的符號是 sym 
int ans, inf = 1e9;
string s[1005]; //s[i]: i 序列
vector <int> v[1005]; //v[i]: i 的子節點
map <char, int> mp = {{'@', 0}, {'A', 1}, {'U', 2}, {'C', 3}, {'G', 4}};
 
void f(int now, int pos){
    //當沒有子節點時
    if (v[now].empty()){
        //若為萬用字元，不須考慮，因為他必可以依照最佳情形進行調整
        if (s[now][pos] == '@') return;

        for (int i = 0; i <= 4; i++){
            //以將 i 極大值初始化，代表不是 i 符號
            dp[now][pos][i] = inf;
        }
        //因為沒有子節點，所以距離為零   
        dp[now][pos][0] = dp[now][pos][mp[s[now][pos]]] = 0;
        return;
    }
    //當有子節點時，逐一子節點遞迴 (仍是同一位置的字元)
    for (auto i:v[now]){
        f(i, pos);
    }
    int c = mp[s[now][pos]];
    //當 s[now][pos] 不是萬用字元 '@'
    if (c != 0){
        for (int i = 0; i <= 4; i++){
            //以將 i 極大值初始化，代表不是 i 符號
            dp[now][pos][i] = inf;
        }
        dp[now][pos][c] = 0;
        for (auto i:v[now]){
            //向子節點尋找
            //min(dp[i][pos][0]+1... : 當該子節點為 '@' 且設其符號不同與當前
            dp[now][pos][c] += min(dp[i][pos][0]+1, dp[i][pos][c]);
        }
        //為方便計算，將假設當 s[now][pos] 為 '@' 時的值設為該在字元時的最小值
        dp[now][pos][0] = dp[now][pos][c];
        return;
    }
    for (c = 1; c <= 4; c++){
        for (auto i:v[now]){
            dp[now][pos][c] += min(dp[i][pos][0]+1, dp[i][pos][c]);
        }
    }
    //將萬用字元選定為一具有最小值的字元
    dp[now][pos][0] = min(min(dp[now][pos][1], dp[now][pos][2]), min(dp[now][pos][3], dp[now][pos][4]));
}
 
int main() {
    cin >> n >> m;
    for (int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        cin >> s[a];
        if (a == b) root = a;
        else v[b].push_back(a);
    }
    for (int i = 0; i < m; i++){
        //一次只遞迴一個字元
        f(root, i);
        ans += dp[root][i][0];
    }
    cout << ans << "\n";
}
/* 
    最初我自己的想法，未考慮兄弟節點的影響；20分
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000+5;
const int MAX_M = 80+3;

int N, M, root;
struct node { int from, now; string s; vector<int> chl; };
struct F { int cnt[4] = {0}; };
node G[MAX_N];
char table[4] = {'A', 'U', 'C', 'G'};

void bfs() {
    int res = 0;
    queue<node> que;
    que.push(G[root]);
    while(!que.empty()) {
        node cur = que.front(); que.pop();
        if(cur.chl.empty()) continue;

        vector<int> chl = cur.chl;
        vector<F> freq(M);
        for(int i=0; i<chl.size(); i++) {
            for(int j=0; j<M; j++) {
                if(cur.s[j] == '@') {
                    if(G[chl[i]].s[j] == 'A') freq[j].cnt[0]++;
                    else if(G[chl[i]].s[j] == 'U') freq[j].cnt[1]++;
                    else if(G[chl[i]].s[j] == 'C') freq[j].cnt[2]++;
                    else if(G[chl[i]].s[j] == 'G') freq[j].cnt[3]++;
                }
                else if(cur.s[j] != G[chl[i]].s[j] && G[chl[i]].s[j] != '@')
                    res++;
            }
            que.push(G[chl[i]]);
        }

        for(int i=0; i<M; i++) {
            int MX = 0;
            int mx = 0;
            for(int j=0; j<4; j++) {
                res += freq[i].cnt[j];
                if(freq[i].cnt[j] > MX) {
                    MX = freq[i].cnt[j];
                    mx = j;
                }
            } 

            if(MX == 0) continue;

            res -= MX;
            G[cur.now].s[i] = table[mx];
            if(table[mx] != G[cur.from].s[i] && G[cur.from].s[i] != '@')
                res++;
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int p, q;
        string s;
        cin >> p >> q >> s;
        if(p == q) root = p;
        else G[q].chl.push_back(p);
        G[p].s = s;
        G[p].from = q;
        G[p].now = p;
    }
    bfs();
    return 0;
}
*/