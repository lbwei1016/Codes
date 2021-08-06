/*
***Sort***
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {5, 4, 8, 1, 2};
    int len = 5;
    for(int i=0; i<len; i++) {
        for(int j=i+1; j<len; j++) {
            if(a[j] < a[i]) swap(a[i], a[j]);
        }
    }
    for(auto i : a) cout << i << ' ';
    return 0;
}