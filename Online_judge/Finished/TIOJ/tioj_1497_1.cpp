/*
***String*** -- Suffix Array
    O(L * log L)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int sa[N], ra[N], n, newra[N];
string s;

void counting_sort() {
    int tmp[n], count[n] = {0};
    for(int i=0; i<n; ++i) ++count[ra[sa[i]]];
    for(int i=1; i<n; ++i) count[i] += count[i-1];
    for(int i=n-1; i>=0; --i) tmp[--count[ra[sa[i]]]] = sa[i];
    for(int i=0; i<n; ++i) sa[i] = tmp[i];
}
void get_suffix() {
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
        newra[sa[0]] = 0;
        for(int i=1; i<n; ++i) {
            if(ra[sa[i]]==ra[sa[i-1]] && ra[(sa[i]+(1<<k))%n]==ra[(sa[i-1]+(1<<k))%n])
                newra[sa[i]] = newra[sa[i-1]];
            else newra[sa[i]] = newra[sa[i-1]] + 1;
        }
        for(int i=0; i<n; ++i) ra[i] = newra[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    getline(cin, s);
    s += '\0';
    n = s.size();
    get_suffix();
    for(int i=1; i<n; ++i) {
        cout << sa[i];
        if(i != n-1) cout << '\n';
    }
    return 0;
}