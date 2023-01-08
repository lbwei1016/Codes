/*
***DP***

    O(n * log n)
*/
#include <bits/stdc++.h>
using namespace std;

//segment start from "l" to "r" with weight "e"
struct SEG { int l, r, e; };
int n;
SEG seg[100005];
int dp[100005];

bool cmp(SEG s1, SEG s2) {
    return s1.r < s2.r;
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d%d%d", &seg[i].l, &seg[i].r, &seg[i].e);
    }
    seg[0] = SEG{-1, -1, 0};
    sort(seg, seg+n+1, cmp);
    for(int i=1; i<=n; i++) {
        //find a segment whose "end" is less than current segment's "start"
        int it = lower_bound(seg, seg+n+1, SEG{0, seg[i].l, 0}, cmp) - seg;
        it--;
        //pick current segment or not
        dp[i] = max(dp[i-1], dp[it]+seg[i].e);
    }
    printf("%d\n", dp[n]);
    return 0;
}