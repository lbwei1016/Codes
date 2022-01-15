/*
***DSU***
    Description:
        For i and j, if abs(i-j) >= k, then s[i] and s[j] can be swapped.
        Determine whether string s can be swapped into decreasing order.
    Solution:
        If (i, j) and (j, k) can be swapped respectively, they should 
        belong to the same subset, i.e. (i, k) can be swapped as well, 
        since i<->j then j<->k.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 105;
string s;
int k;
int p[N];

int find(int x) {
    if(p[x]  < 0) return x;
    return p[x] = find(p[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(p[x] < p[y]) {
        p[x] += p[y];
        p[y] = x;
    }
    else {
        p[y] += p[x];
        p[x] = y;
    }
}

int main() {
    memset(p, -1, sizeof p);
    cin >> s >> k;
    int len = s.size();
    for(int i=0; i<len; ++i) {
        for(int j=i+k; j<len; ++j) {
            join(i, j);
        }
    }    
    vector<vector<char> > subset(len);
    for(int i=0; i<len; ++i) {
        subset[find(i)].push_back(s[i]);
    }
    for(auto &x : subset) {
        sort(x.begin(), x.end(), greater<char>());
    }

    string res;
    for(int i=0; i<len; ++i) {
        int rt = find(i);
        // At position i, find the minimum char can be swapped to here.
        res.push_back(subset[rt].back());
        subset[rt].pop_back();
    }
    sort(s.begin(), s.end());
    if(s == res) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}