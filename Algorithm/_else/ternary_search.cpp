/*
***Search***
    Description:
        Search for extreme values among concave upward or downward data.
    O(log N)
*/
#include <bits/stdc++.h>
using namespace std;

int t_search(int arr[], int l, int r) {
    // When r - l == 2, the boundries (l, ml, mr, r) cannot move anymore, so stop.
    // (because: 2/3 == 0)
    while(r - l > 2) {
        int ml = l + (r-l) / 3;
        int mr = r - (r-l) / 3;
        if(arr[ml] < arr[mr]) l = ml;
        else r = mr;
    }
    return max(arr[l], arr[l+1]);
}
int main() {
    // concave downward
    // int arr[] = {-4, -2, -1, 0, 3, 6, 7, 4, 3, -9, -18};
    // int arr[] = {0, 2, 0, -2, -4, -9};
    // printf("The largest value on the covex is: %d\n", t_search(arr, 0, sizeof(arr)/sizeof(int)));
    int n;
    cin >> n;
    while(n--) {
        int len; cin >> len;
        int arr[len];
        for(int i=0; i<len; ++i) cin >> arr[i];
        cout << t_search(arr, 0, len) << '\n';
    }
    return 0;
}