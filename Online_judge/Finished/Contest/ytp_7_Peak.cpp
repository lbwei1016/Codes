/*
***BIT*** (*)
    Description:
        Given an array of identical elements, count (i, j, k): for all 
        i<j<k such that a[i] < a[j] > a[k], and a[i] + a[j] + a[k] is 
        an even number.
    Solution:
        Like solving the "inversion" problem, use a BIT to calculate
        the number of how many elements are smaller than the current one.

        Unlike the above problem, we have to evaluate both from the left 
        and from the right, and we also need to record separately "odd" 
        elements and "even" elements to comply with the "even number" 
        constraint. 

        Finally, the scope of elements are rather big (<= 1e9), and thus 
        hashing is mandatory. Don't forget to record the parity (odd or even)
        of every element, since the parity before and after hashing may differ.
    O(n logn)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200005;
int oddbit[N], evenbit[N]; // 奇偶 BIT
int n, arr[N], tmp[N];
ll oddleft[N], evenleft[N];
bool iseven[N]; // arr[i] 的奇偶性
ll ans;

// 因為 arr[i] <= 1e9 太大
void _hash() {
    sort(tmp, tmp+n);
    for(int i=0; i<n; ++i) {
        arr[i] = lower_bound(tmp, tmp+n, arr[i])-tmp + 1;
    }
}
void update(int i, int bit[]) {
    while(i <= n) {
        ++bit[i];
        i += i&-i;
    }
}
int query(int i, int bit[]) {
    int res = 0;
    while(i > 0) {
        res += bit[i];
        i -= i&-i;
    }
    return res;
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        scanf("%d", arr+i);
        tmp[i] = arr[i];
        if(arr[i] & 1) iseven[i] = 0;
        else iseven[i] = 1;
    }

    _hash();
    // 找出左邊比自己小的數量
    for(int i=0; i<n; ++i) {
        oddleft[i] = query(arr[i]-1, oddbit);
        evenleft[i] = query(arr[i]-1, evenbit);
        if(iseven[i]) update(arr[i], evenbit);
        else update(arr[i], oddbit);
    }
    memset(oddbit, 0, sizeof(oddbit));
    memset(evenbit, 0, sizeof(evenbit));
    // 找出右邊比自己小的數量
    for(int i=n-1; i>=0; --i) {
        ll oddright = query(arr[i]-1, oddbit);
        ll evenright = query(arr[i]-1, evenbit);
        if(iseven[i]) {
            ans += oddleft[i]*oddright;
            ans += evenleft[i]*evenright;
            update(arr[i], evenbit);
        }
        else {
            ans += oddleft[i]*evenright;
            ans += evenleft[i]*oddright;
            update(arr[i], oddbit);
        }
    }
    printf("%lld\n", ans);
    return 0;
}