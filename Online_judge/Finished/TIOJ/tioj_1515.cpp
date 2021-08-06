/*
***String*** -- LCP
    O(L * log L)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, sa[N], ra[N], nra[N], out[N], cnt[N];
int mx;
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
    for(int i=0; i<n; ++i) {
        int j = sa[ra[i]-1];
        if(h > 0) --h;
        for(; i+h<n && j+h<n; ++h) {
            if(s[i+h] != s[j+h]) break;
        }
        mx = max(mx, h);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    suffix(); LCP();
    cout << mx << '\n';
    return 0;
}