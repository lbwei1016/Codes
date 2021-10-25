/*
***Divide and Conquer***
    O(n logn)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tmp[100005][2];
    inline static bool cmp1(vector<int> &v1, vector<int> &v2) {
        return v1[0]==v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
    }
    
    int dac(int l, int r, vector<vector<int>> &v) {
        if(l+1 == r) return 0;
        int mid = (l+r) >> 1;
        int res = dac(l, mid, v) + dac(mid, r, v);
        for(int i=l; i<mid; ++i) {
            if(v[r-1][1]>v[i][1] && v[r-1][0]>v[i][0]) {
                ++res; 
                v[i][0] = 1e9; // v[i][0] = 1e9: 為了不要重複計算
            }
        }
        int j=mid, k=0;
        for(int i=l; i<mid; ++i) {
            while(j<r && v[j][1]<v[i][1]) {
                tmp[k][0] = v[j][0];
                tmp[k++][1] = v[j++][1];
            }
            tmp[k][0] = v[i][0];
            tmp[k++][1] = v[i][1];
        }
        for(int i=l; i<j; ++i) v[i][0] = tmp[i-l][0], v[i][1] = tmp[i-l][1];
        return res;
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp1);
        int n = properties.size();
        return dac(0, n, properties);
    }
};
int main() {
    vector<vector<int> > vv(10, vector<int>(2, 0));
    Solution S;
    for(int i=0; i<10; ++i) for(int j=0; j<2; ++j) cin >> vv[i][j];
    cout << S.numberOfWeakCharacters(vv);
    return 0;
}