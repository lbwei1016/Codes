/*
***DP***
    Description:
        給定數列: 0, 1, 8, 11, 69, 88, 96, 101, 111, 181，求該數列的第 N 項
    Solution:
        數列中每個數字翻轉 180 度後，仍是同樣的數字

    O(N)
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000000;

string dp[MAX_N+5] = { "0", "1", "8", "11", "69", "88", "96" };
string one[3] = { "0", "1", "8" };
string two[5] = { "00", "11", "69", "88", "96" };

void calc() {
    int left = 3, right = 7; //two-digit numbers
    int temp, pos = 7;

    for(int len=3; pos<MAX_N; len++) {
        if(len & 1) {
            for(int i=left; i<right && pos<MAX_N; i++) {
                int to = dp[i].size() >> 1;
                for(int j=0; j<3; j++) {
                    dp[pos++] = dp[i].substr(0, to) + one[j] + dp[i].substr(to, to);
                }
            }
        }
        else {
            temp = pos;
            for(int i=left; i<right && pos<MAX_N; i++) {
                int to = dp[i].size() >> 1;
                for(int j=0; j<5; j++) {
                    dp[pos++] = dp[i].substr(0, to) + two[j] + dp[i].substr(to, to);
                }
            }
            left = temp, right = pos;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    calc();
    int n;
    while(cin >> n) {
        if(!n) break;
        cout << dp[n-1] << '\n';
    }
    
    return 0;
}