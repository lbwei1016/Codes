/*
***Sort*** (stable)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {5, 4, 8, 1, 2, -1, 3, 9};
    int len = sizeof(a) / sizeof(int);
    for(int i=0; i<len; i++) {
        for(int j=i+1; j<len; j++) {
            if(a[j] < a[i]) swap(a[i], a[j]);
        }
        for (int i=0; i<len; ++i) printf("%d,%c", a[i], (i==len-1 ? '\n' : ' '));
    }
    for(auto i : a) cout << i << ' ';
    return 0;
}