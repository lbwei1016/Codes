/*
***BFS***
    Solution:
        把每個狀態看成頂點，找 shortest path。
    Note:  
        若使用 DFS，不要用 std::unorderde_set 來紀錄是否拜訪，
        因為先遞迴的路徑未必最短!!! 要用和 BFS 一樣的表格 d[] 
        來記錄路徑長，但須初始化為 INF。底下有以 DFS 實作的版本。
    O(NlogN)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 1e7+1;
int a, N, d[MAX_N];

int pow(int x, int n) {
    int res = 1;
    while(n > 0) {
        if(n & 1) res *= x;
        n >>= 1;
        x *= x;
    }
    return res;
}

int op(int n) {
    int tmp = n, dig = 0;
    int lowdig = n % 10; n /= 10;
    while(tmp > 0) ++dig, tmp /= 10;
    return lowdig*pow(10, dig-1) + n;
}

void bfs() {
    queue<ll> que;
    d[1] = 0; que.push(1);
    while(!que.empty()) {
        ll at = que.front(); que.pop();
        
        ll op1 = at * a;
        if(op1 < 10LL*N && d[op1] == -1) {
            d[op1] = d[at] + 1;
            que.push(op1);
        }
        if(at % 10 != 0 && at > 10) {
            ll op2 = op(at);
            if(op2 < 10LL*N && d[op2] == -1) {
                d[op2] = d[at] + 1;
                que.push(op2);
            }
        }
    }
}

int main() {
    cin >> a >> N;
    memset(d, -1, sizeof(d));
    bfs();
    cout << d[N] << '\n';
    return 0;
}
/*
***Correct DFS version
using namespace std;

typedef long long ll;
const int MAX_N = 1e7+1;
int a, N;
int d[MAX_N];

ll pow(int x, int n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res *= x;
        n >>= 1;
        x *= x;
    }
    return res;
}

ll op(ll n) {
    ll tmp = n, dig = 0;
    int lowdig = n % 10; n /= 10;
    while(tmp > 0) ++dig, tmp /= 10;
    return lowdig*pow(10, dig-1) + n;
}

void rec(ll n) {
    ll x = n*a;
    if(x < 10LL*N && d[x]>d[n]+1) {
        d[x] = d[n] + 1;
        rec(x);
    }
    if(n % 10 != 0 && n > 10) {
        ll y = op(n);
        if(y < 10LL*N && d[y]>d[n]+1) {
            d[y] = d[n] + 1;
            rec(y);
        }
    }
}

int main() {
    cin >> a >> N;
    fill(d, d+MAX_N, MAX_N);
    d[1] = 0;
    rec(1);
    if(d[N] == MAX_N) cout << "-1\n";
    else cout << d[N] << '\n';
    return 0;
}
*/