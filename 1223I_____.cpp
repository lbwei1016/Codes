#include <bits/stdc++.h>
using namespace std;

string s, s_s;
int k;
bool find(int at, int l1, int r1, int l2, int r2) {
    int l = s.size();
    int pl[2] = {l1, l2}, pr[2] = {r1, r2};
    if(l1 != r1) {
        l1 = max(0, min(l1, r1-k)); 
        r1 = min(l, max(r1, l1+k));
    }
        
    if(l2 != r2) {
        l2 = max(0, min(l2, r2-k)); 
        r2 = min(l, max(r2, l2+k));
    }
    // if(l2 < r1) swap(l2, r1);
    if((l1<=at && at<=r1) || (l2<=at && at<=r2)) return true;
    if(pl[0]==l1 && pl[1]==l2 && pr[0]==r1 && pr[1]==r2) return false;
    return find(at, l1, r1, l2, r2);
} 
bool solve() {
    for(int i=0, l=s.size(); i<l; ++i) {
        for(int j=0; j<l; ++j) {
            if(s_s[i] != s[j]) continue;
            int r1 = max(0, i-k);
            int l2 = min(i+k, l-1);
            if(!find(j, 0, r1, l2, l-1)) return false; 
        }
    }
    return true;
}

int main() {
    cin >> s >> k;
    s_s = s;
    sort(s_s.begin(), s_s.end());
    if(solve()) puts("Yes");
    else puts("No");

    return 0;
}