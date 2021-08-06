/*
***String*** -- Longest Repeated Substring (non-overlapping)
    Solution:
        題意要求的就是 LRS，但多了一個限制「轉調」；可以發現，
        轉調過後同一 theme 的「音差」不變，因此先將原序列轉化為
        s[i]-s[i-1] 的差值序列，再求解。
    O(L * log L)
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

const int N = 20005, INF = 1e9;
int n, s[N], mxx, mnn;
int sa[N], ra[N], nra[N];
int hei[N];

void counting_sort() {
    int tmp[n], cnt[n];
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; ++i) ++cnt[ra[sa[i]]];
    for(int i=1; i<n; ++i) cnt[i] += cnt[i-1];
    for(int i=n-1; i>=0; --i) tmp[--cnt[ra[sa[i]]]] = sa[i];
    for(int i=0; i<n; ++i) sa[i] = tmp[i];
}
void suffix() {
    vector<pair<int, int> > tmp(n);
    for(int i=0; i<n; ++i) tmp[i] = {s[i], i};
    sort(tmp.begin(), tmp.end());
    for(int i=0; i<n; ++i) sa[i] = tmp[i].second;
    ra[sa[0]] = 0;
    for(int i=1; i<n; ++i) {
        if(tmp[i].first == tmp[i-1].first)
            ra[sa[i]] = ra[sa[i-1]];
        else ra[sa[i]] = ra[sa[i-1]] + 1;
    }

    for(int k=0; 1<<k<=n; ++k) {
        for(int i=0; i<n; ++i) 
            sa[i] = (sa[i] - (1<<k) + n) % n;
        counting_sort();
        nra[sa[0]] = 0;
        for(int i=1; i<n; ++i) {
            if(ra[sa[i]]==ra[sa[i-1]] && ra[(sa[i]+(1<<k))%n]==ra[(sa[i-1]+(1<<k))%n])
                nra[sa[i]] = nra[sa[i-1]];
            else nra[sa[i]] = nra[sa[i-1]] + 1;
        }
        for(int i=0; i<n; ++i) ra[i] = nra[i];
    }
}
void LCP() {
    int h = 0;
    hei[0] = 0;
    for(int i=0; i<n; ++i) {
        int j = sa[ra[i]-1];
        if(h > 0) --h;
        for(; i+h<n && j+h<n; ++h) {
            if(s[i+h] != s[j+h]) break;
        }
        hei[ra[i]] = h;
    }
}
bool check(int len) {
    bool found = false;
    int mn = sa[0], mx = sa[0];
    for(int i=1; i<n; ++i) {
        if(hei[i] >= len) {
            mn = min(mn, sa[i]);
            mx = max(mx, sa[i]);
        }
        else {
            if(mx - mn >= len) {
                // 找距離最遠的 LRS，避免最後 +1 後重疊
                if(mx-mn > mxx-mnn) 
                    mxx = mx, mnn = mn;
                found = true;
            }
            mn = mx = sa[i];
        }
    }
    if(mx-mn >= len) {
        if(mx-mn > mxx-mnn) 
            mxx = mx, mnn = mn;
        return true;
    }
    return found;
}
int LRS() {
    int lb = 0, ub = n/2 + 2;
    while(ub - lb > 1) {
        int mid = (lb+ub) >> 1;
        if(check(mid)) lb = mid;
        else ub = mid;
    }
    return lb;
}
int main() {
    while(scanf("%d", &n) == 1) {
        if(n == 0) break;
        mxx = mnn = 0;
        int pre, now;
        scanf("%d", &pre);
        for(int i=0; i<n-1; ++i) {
            scanf("%d", &now);
            s[i] = now - pre;
            pre = now;
        }
        s[n-1] = -INF;
        suffix(); LCP();
        int res = LRS();
        // 還原
        if(mxx-mnn > res) ++res;
        if(res < 5) puts("0");
        else printf("%d\n", res);
    }
    return 0;
}