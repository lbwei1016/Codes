/*
***DP (memoization)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    //unordered_set<int> S[71];
    int dp[10000][75];
    int dfs(vector<vector<int>>& mat, int sum, int d, int target) {
        if(d == m) return abs(sum - target);
        if(dp[sum][d] >= 0) return dp[sum][d];
        
        int res = 1e9;
        for(int i=0; i<n; ++i) {
            res = min(res, dfs(mat, sum+mat[d][i], d+1, target));
        }
        return dp[sum][d] = res;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m = mat.size(); n = mat[0].size();
        memset(dp, -1, sizeof(dp));
        
        return dfs(mat, 0, 0, target);
    }
};