/*
***DP***
    Description:
        Given m sorters, and each has a range that can sort numbers. Find
        out the minimum sorters needed to make the MAX of the numbers to 
        appear at the end of the sequence.

    O(m * log n)
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_M = 500000;
const int MAX_N = 50000;
const int INF = 1e9;

int n, m;
int s[MAX_M], t[MAX_M]; //ranges
int node[1 << 18]; //seg tree

//dp[j]: the minimum sorters needed to make MAX appear at pos "j", otherwise INF
int dp[MAX_N + 1]; 
int N; //N = 2^p >= n

//1-indexed
void ST_init(int n) {

    N = 1;
    while(N < n)
        N *= 2;
    for(int i=1; i<=2*N-1; i++)
        node[i] = INF;
}

//1-indexed
void update(int v, int x) {

    v += N - 1; //to leaf
    node[v] = x;
    while(v > 1) {
        v /= 2;
        node[v] = min(node[2*v], node[2*v + 1]);
    }
}

//[l, r)
int query(int s, int t, int v, int l, int r) {

    if(t <= l || s >= r) 
        return INF;
    if(s <= l && r <= t)
        return node[v];
    else {
        int mid = (l+r) / 2;
        int lch = query(s, t, 2*v, l, mid);
        int rch = query(s, t, 2*v+1, mid, r);
        return min(lch, rch);
    }
}

void solve() {

    ST_init(n);
    fill(dp, dp+n+1, INF); //[l, r)
    dp[1] = 0; 
    update(1, 0);

    for(int i=0; i<m; i++) {
        //if val = query(...)+1, it means that current sorter is to be used
        int val = min(dp[t[i]], query(s[i], t[i]+1, 1, 1, N+1) + 1);
        dp[t[i]] = val;
        update(t[i], val);
    }
    printf("%d\n", dp[n]);
}

int main() {

    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++)
        scanf("%d%d", &s[i], &t[i]);
    
    solve();
    
    return 0;
}