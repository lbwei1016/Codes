/*
***Binary Search / Prefix Sum***
    Solution:
        ps[r] - ps[l-1] <= K
        => ps[l-1] >= ps[r] - K
        => use lower_bound() to find MAX ps[l-1]

    O(n * log n)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K;
    scanf("%d%d", &n, &K);
    int psum = 0;
    int res = 0;
    set<int> S({0});
    for(int i=0; i<n; i++) {
        int t;
        scanf("%d", &t);
        psum += t;
        auto it = S.lower_bound(psum - K);
        if(it != S.end()) res = max(res, psum-*it);
        S.insert(psum);
    }
    printf("%d\n", res);
    return 0;
}
/* 爬行法 (Crawling Method) NO!!!!!!
Reason: elements in arr[] may be negative!!! 
        so the sum of the sequence is not increasing.
int s = 0, t = 0;
    int sum = 0, res = 0;
    while(s <= t) {
        while(t<n && sum+arr[t]<=K) {
            sum += arr[t];
            t++;
        }
        res = max(res, sum);
        sum -= arr[s++];
    }
*/