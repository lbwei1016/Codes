/*
***LIS*** -- Longest Increasing Subsequence
    Description:
        store the exact sequence
    Note: The accuracy of this code is not verified. Use it with caution.
*/
#include <bits/stdc++.h>
using namespace std;

struct E {
    int w, s, id;
};
struct LIS {
    int val;
    vector<int> seq;
    LIS() : val(0){ seq.clear(); }
};

inline bool cmp1(const E &e1, const E &e2) {
    return e1.w==e2.w ? e1.s>e2.s : e1.w<e2.w;
}

LIS dp[100000];

int main() {
    int w, s;
    
    vector<E> v;
    for(int i=1; cin>>w>>s; ++i) {
        v.push_back(E{w, s, i});
    }
    sort(v.begin(), v.end(), cmp1);

    int si = v.size();
    LIS ans;
    for(int i=0; i<si; ++i) {
        dp[i].val = 1; 
        dp[i].seq.push_back(v[i].id);  
        for(int j=0; j<i; ++j) {
            if(v[i].w>v[j].w && v[i].s<v[j].s) {
                if(dp[i].val < dp[j].val + 1) {
                    dp[i].val = dp[j].val + 1;
                    dp[i].seq = dp[j].seq;
                    dp[i].seq.push_back(v[i].id);
                }
            }
            if(dp[i].val > ans.val) {
                ans = dp[i];
            }
        }
    }
    cout << ans.val << '\n';
    for(auto x : ans.seq) cout << x << '\n';
    return 0;
}