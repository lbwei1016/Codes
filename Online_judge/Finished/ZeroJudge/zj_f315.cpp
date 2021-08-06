/*
***BIT*** 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 100000+5;
int bit[2 * MAX_N]; //bit[i]: 若為 1，代表出現過；反之則非
int L[MAX_N], R[MAX_N]; //L[i], R[i]: 數字 i 第一次和第二次出現的位置
int n;
//1-indexed
void bit_add(int i, int x) {
    while(i <= 2*n) {
        bit[i] += x;
        i += i & -i;
    }
}
ll bit_sum(int i) {
    ll res = 0;
    while(i > 0) {
        res += bit[i];
        i -= i & -i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=2*n; i++) {
        int t;
        cin >> t;
        if(L[t] == 0) L[t] = i;
        else R[t] = i;
    }

    ll res = 0;
    //由小到大
    for(int i=1; i<=n; i++) {
        //前綴和，1 代表出現過
        res += bit_sum(R[i]) - bit_sum(L[i]);
        //代表數字 i 已出現過
        bit_add(L[i], 1);
        bit_add(R[i], 1);
    }
    cout << res << '\n';
    
    return 0;
}