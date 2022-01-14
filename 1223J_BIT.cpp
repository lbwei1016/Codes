/*
***BIT*** (逆序數對) (*)
    Description:
        有一個對序列的操作為: 將相鄰三元素由 abc -> cab。
        給定兩個序列，求第一個序列是否能透過上述操作變換為第二個序列。
    Solution:
        奇、偶置換 (odd & even permutation)
            首先假想一原序列: 1, 2, ..., n，並判斷給定的兩序列分別是此
            原序列經過奇或偶置換。再來觀察上述的操作，可以發現，該操作是
            "偶置換"(1<->3, 2<->3)，又置換的奇偶性不因再做一次偶置換而改變。
            因此可以得出結論: 
                若兩序列可藉由上述操作互相轉換，則兩序列的置換奇偶性必須相同。
        而置換奇偶性即為逆序數對的奇偶。
    O(n logn)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int bit[N];

void add(int id) {
    while(id < N) {
        ++bit[id];
        id += id&(-id);
    }
}
int query(int id) {
    int sum = 0;
    while(id > 0) {
        sum += bit[id];
        id -= id&(-id);
    }
    return sum;
}
int inv(vector<int> &v, int n) {
    int sum = 0;
    memset(bit, 0, sizeof(bit));
    for (int i=n-1; i>=0; --i) {
        sum += query(v[i]);
        add(v[i]);
    }
    return sum % 2;
}
int main() {
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (auto &x: v1) cin >> x;
    for (auto &x: v2) cin >> x;
    
    if(inv(v1, n) == inv(v2, n)) cout << "Possible\n";
    else cout << "Impossible\n";

    return 0;
}