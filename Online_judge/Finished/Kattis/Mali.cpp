/*
    Description:
        動態求最小的最大序對和: max(ai + bj)
    Solution:
        重點在於，constraints 中 N 與 A, B 的大小懸殊 (A, B 極小)。
        因此針對 A, B 來計算
    O(n * A) => 1e7
*/
#include <bits/stdc++.h>
using namespace std;

const int NUM = 105;

// 1e2
void calc(vector<int> v1, vector<int> v2) {
    int n1 = 1, n2 = 100;
    bool done = false; // no more number to make pairs
    int mx = 0;
    while(true) {
        // minimal "ai" goes with maximal "bj"
        while(v1[n1] == 0) {
            if(++n1 > 100) {
                done = true;
                break;
            }
        }
        while(v2[n2] == 0) {
            if(--n2 < 0) {
                done = true;
                break;
            }
        }
        if(done) break;

        mx = max(mx, n1+n2);
        int used = min(v1[n1], v2[n2]);
        v1[n1] -= used; v2[n2] -= used;
    }
    cout << mx << '\n';
}

int main() {
    int n;
    // v1[k]: how many times number k appears in <a>
    vector<int> v1(NUM, 0), v2(NUM, 0);
    cin >> n;
    // 1e5
    for(int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        ++v1[a]; ++v2[b];
        calc(v1, v2); 
    }
    return 0;
}