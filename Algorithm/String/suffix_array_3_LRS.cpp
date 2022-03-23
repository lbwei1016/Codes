/*
***String*** -- Longest Repeated Substring (non-overlapping)
    Description:
        求 A 的一個最長子字串，使得這個子字串在 A 中出現超過一次，且至少
        兩次出現的位置不重疊。
    Solution:
        1. 將問題轉化為二分問題:
            判斷是否存在長度為 k 的字串在 A 至少重複出現兩次，且不重疊。
        2. 利用 hei[]，並將之依照 k 來分組:
            對於區間 [i, j]，若區間內的 hei[] 皆不小於 k，則將他們歸類在同一組。

            因為區間內的 hei[] 皆不小於 k，所以同一組內的任兩個後綴的 lcp 皆 >= k，
            只需其中恰兩後綴不重疊即滿足條件。因此，對於同一組的所有後綴，取距離最遠
            的兩者，判斷 min-max >= k 是否成立。

            為什麼只判斷相鄰的後綴 (hei[]) ? 而非窮舉 ?
            因為如同 LCSubstring，最長的可能只會出現在自己的前(後)一個後綴。
    O(L * log L)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, sa[N], ra[N], nra[N], out[N], cnt[N];
int hei[N];
int lrs; // LRS 的起始點
string s;

void counting_sort() {
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; ++i) ++cnt[ra[sa[i]]];
    for(int i=1; i<n; ++i) cnt[i] += cnt[i-1];
    for(int i=n-1; i>=0; --i) out[--cnt[ra[sa[i]]]] = sa[i];
    for(int i=0; i<n; ++i) sa[i] = out[i];
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
    int mn = sa[0], mx = sa[0];
    for(int i=1; i<n; ++i) {
        // 仍在同一組
        if(hei[i] >= len) {
            // 盡量拉開間距
            mn = min(mn, sa[i]);
            mx = max(mx, sa[i]);
        }
        else {
            // 離開前一組了，check
            if(mx-mn >= len) {
                lrs = mx;
                return true;
            }
            // 新的組邊界
            mx = mn = sa[i];
        }
    }
    if(mx-mn >= len) {
        lrs = mx; 
        return true;
    }
    return false; 
}
void LRS() {
    // 長度
    int lb = 0, ub = n;
    while(ub - lb > 1) {
        int mid = (lb+ub) >> 1;
        if(check(mid)) lb = mid;
        else ub = mid;
    }
    cout << "LRS: " << lb << ' '+s.substr(lrs, lb)+'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    getline(cin, s);
    s += '\0';
    n = s.size();
    suffix(); LCP();
    for(int i=0; i<n; ++i) cout << sa[i] << ' '+s.substr(sa[i])<<'\n';
    cout << "----------------------------\n";
    LRS();
    return 0;
}