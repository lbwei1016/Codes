#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+3;
int arr[N], s_arr[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        scanf("%d", arr+i);
        s_arr[i] = arr[i];
    }
    sort(s_arr, s_arr+n);

    bool inv = false;
    int st = 0, ed = 0;
    for(int i=0; i<n; ++i) {
        int ss, ee;
        if(s_arr[i] != arr[i]) {
            ss = i++;
            while(i<n && arr[i-1]>=arr[i]) {
                ++i;
            }
            ee = --i;
            if(inv) {
                puts("impossible");
                return 0;
            }
            inv = true;
            st = ss; ed = ee;
        }
    }
    printf("%d %d\n", st+1, ed+1);
    return 0;
}