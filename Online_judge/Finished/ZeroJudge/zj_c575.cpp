/*
***Binary Search***

    O(N * logR)
        R: range of coordinate
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 50000+5;

int N, K;
int Ns[MAX_N];

int solve(int mid) {
    int s = 0;
    int k = K;
    while(true) {
        if(k <= 0) return -1; //當基地台數已用盡
        int pos = upper_bound(Ns, Ns+N, Ns[s]+mid) - Ns; //找覆蓋不到的最近一點  
        if(pos >= N) return 1; //當全數覆蓋完畢
        k--; //用去一座基地台
        s = pos; //更新位置
    }
    return -1; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> Ns[i];
    }
    sort(Ns, Ns+N);

    int lb = 0, ub = 1e9+1;
    while(ub - lb > 1) {
        int mid = (lb+ub) / 2;
        int r = solve(mid);
        if(r > 0) ub = mid;
        else lb = mid;
    }
    cout << ub << '\n';
    
    return 0;
}