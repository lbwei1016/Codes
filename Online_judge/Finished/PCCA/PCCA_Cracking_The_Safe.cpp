/*
***BFS / 狀態壓縮 / 隱式圖*** (*)
    Description:
        Push button to crack a safe.
    Solution:
        Initailly, I used recursion to try to solve it. However, in recursion, the 
        first time when a status is met doesn't guarantee that its "best" outcome (which
        means "safe" might not be the smallest for it now) will be produced. If I 
        am to use memoization, I have to "return" whenever there is a result for some
        status, despite the fact that it may not be the best one. Hecne, I would  
        produce an "answer" which is not the optimized situation.

        And BFS comes!!!
    O(m^(n^n)): m = 4, n = 3
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 150;
struct CODE { int r1, r2, r3, d; };
bool vis[N][N][N]; // 三個 row；狀態壓縮 (可以考慮用單一整數表示)

void _move(int R[3], int val, int i, int j) {
    int mask = 3; // 00011
    // col
    for(int c=0; c<3; ++c) {
        int k = R[i] & mask; // 取出
        R[i] ^= k; // 先清除
        k >>= (2*c); // 為了下一行的 mod
        k = (k + val + 4) % 4; // 原本是考慮 +1 和 -1，但實際上只需要 +1
        k <<= (2*c); // 回復 
        R[i] |= k; // 放回去
        mask <<= 2; // 往下一 col
    }
    // row
    mask = 3;
    for(int k=0; k<j; ++k) mask <<= 2;
    for(int r=0; r<3; ++r) {
        if(r == i) continue; // 不要重複加
        int k = R[r] & mask;
        R[r] ^= k;
        k >>= (2*j);
        k = (k + val + 4) % 4;
        k <<= (2*j);
        R[r] |= k;
    }
}

int bfs(int R[3]) {
    queue<CODE> que;
    que.push({R[0], R[1], R[2], 0});
    vis[R[0]][R[1]][R[2]] = true;

    while(!que.empty()) {
        CODE p = que.front(); que.pop();
        if(p.r1==0 && p.r2==0 && p.r3==0) return p.d;

        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                int tmp[3] = {p.r1, p.r2, p.r3};
                _move(tmp, 1, i, j);
                if(vis[tmp[0]][tmp[1]][tmp[2]]) continue;
                vis[tmp[0]][tmp[1]][tmp[2]] = true;
                que.push({tmp[0], tmp[1], tmp[2], p.d+1});
            }
        }
    }
    return -1;
}

int main() {
    int tmp, R[3] = {0};
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            cin >> tmp;
            R[i] <<= 2;
            R[i] |= tmp;
        }
    }
    cout << bfs(R) << '\n';
    return 0;
}

/* recursion
const int N = 150, INF = 1e9;
int safe[N][N][N]; // 三個 row；bit dp
int g_mn = INF;

// memoization
void _move(int R[3], int val, int i, int j) {
    int mask = 3; // 00011
    // col
    for(int c=0; c<3; ++c) {
        int k = R[i] & mask;
        R[i] ^= k;
        k >>= (2*c);
        k = (k + val + 4) % 4;
        k <<= (2*c);
        R[i] |= k;
        mask <<= 2;
    }
    // row
    mask = 3;
    for(int k=0; k<j; ++k) mask <<= 2;
    for(int r=0; r<3; ++r) {
        if(r == i) continue;
        int k = R[r] & mask;
        R[r] ^= k;
        k >>= (2*j);
        k = (k + val + 4) % 4;
        k <<= (2*j);
        R[r] |= k;
    }
}

int rec(int R[3], int d) {
    if(safe[R[0]][R[1]][R[2]] != INF && d >= safe[R[0]][R[1]][R[2]]) 
        return safe[R[0]][R[1]][R[2]];
    --safe[R[0]][R[1]][R[2]];
    if(R[0]==0 && R[1]==0 && R[2]==0) {
        g_mn = min(g_mn, d);
        return d;
    }
    int mn = INF;
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            _move(R, 1, i, j);
            safe[R[0]][R[1]][R[2]] = min(safe[R[0]][R[1]][R[2]], rec(R, d+1));
            mn = min(safe[R[0]][R[1]][R[2]], mn);
            _move(R, -1, i, j);
        }
    }
    return mn;
}
*/