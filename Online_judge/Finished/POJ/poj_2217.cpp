/*
***String*** -- Longest Common Substring
    Solution:
        將要求 common substring 的字串全部串在一起，並求 suffix array。
        可以發現，兩字串要擁有最大的 common substring，只需考慮他與後綴陣
        列中他的前一位就夠了 (因為相隔越遠，字串從頭看起的差異越大)，因此再
        算出高度陣列並找出非屬同一字串的最大高度即是答案。
    O(∑Li * log∑Li)
*/
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10005;
int T, n, sa[2*N], ra[2*N], newra[2*N], hei[2*N];
int tmp[2*N], cnt[2*N];
string s, t;

void counting_sort() {
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; ++i) ++cnt[ra[sa[i]]];
    for(int i=1; i<n; ++i) cnt[i] += cnt[i-1];
    for(int i=n-1; i>=0; --i) tmp[--cnt[ra[sa[i]]]] = sa[i];
    for(int i=0; i<n; ++i) sa[i] = tmp[i];
}
void get_suffix() {
    vector<pair<int, int> > tmp(n);
    for(int i=0; i<n; ++i) tmp[i] = {s[i], i};
    sort(tmp.begin(), tmp.end());
    for(int i=0; i<n; ++i) sa[i] = tmp[i].second;
    ra[sa[0]] = 0;
    for(int i=1; i<n; ++i) {
        if(tmp[i-1].first == tmp[i].first)
            ra[sa[i]] = ra[sa[i-1]];
        else ra[sa[i]] = ra[sa[i-1]] + 1;
    }

    for(int k=0; 1<<k<=n; ++k) {
        for(int i=0; i<n; ++i) 
            sa[i] = (sa[i] - (1<<k) + n) % n;
        counting_sort();
        newra[sa[0]] = 0;
        for(int i=1; i<n; ++i) {
            if(ra[sa[i]] == ra[sa[i-1]] && ra[(sa[i]+(1<<k))%n] == ra[(sa[i-1]+(1<<k))%n]) 
                newra[sa[i]] = newra[sa[i-1]];
            else newra[sa[i]] = newra[sa[i-1]] + 1;
        }
        for(int i=0; i<n; ++i) ra[i] = newra[i];
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
int main() {
    scanf("%d", &T);
    getchar(); // eat '\n'
    while(T--) {
        getline(cin, s);
        getline(cin, t);
        int sl = s.size(), res = 0;
        s += '\0' + t; // 用未曾出現過的字元來串接兩字串
        n = s.size();
        get_suffix();
        LCP();
        for(int i=1; i<n; ++i) {
            // 當該高度並非同一字串才考慮更新最大值
            if((sa[i-1] < sl) != (sa[i] < sl))
                res = max(res, hei[i]);
        }
        printf("Nejdelsi spolecny retezec ma delku %d.\n", res);
    }
    return 0;
}