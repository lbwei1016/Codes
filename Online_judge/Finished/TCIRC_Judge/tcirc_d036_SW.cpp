/*
***Sliding Window***

    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

int arr[200005];
unordered_map<int, int> cnt;

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    int res = 0;
    for(int i=0; i<m-1; i++) {
        cnt[arr[i]]++;
    }
    for(int s=0, t=m-1; t<n; s++, t++) {
        cnt[arr[t]]++;
        if(cnt.size() == m) res++;
        if(--cnt[arr[s]] == 0) cnt.erase(arr[s]);
    }
    printf("%d\n", res);
    return 0;
}