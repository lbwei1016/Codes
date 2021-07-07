/*
***Sliding Window***
*/
#include <bits/stdc++.h>
using namespace std;

int n, K;
int arr[200005];

int main() {
    scanf("%d%d", &n, &K);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    int s, t, sum = 0, ans = 0, cnt = 0;
    for(s=0, t=0; t<n; t++) {
        sum += arr[t];
        while(sum > K) {
            sum -= arr[s++];
        }
        if(sum > ans) {
            ans = sum;
            cnt = 1;
        } else if(sum == ans) {
            cnt++;
        }
    }
    printf("%d\n%d\n", ans, cnt);
    return 0;
}