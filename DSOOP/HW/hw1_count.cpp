#include <bits/stdc++.h>
using namespace std;

int count(int a[], int len, int target) {
    int cnt = 0;
    for (int i=0; i<len; ++i) {
        if (a[i] == target) ++cnt;
    }
    return cnt;
}
int main() {
    int a[] = {2, 4, 0, -1, 392, 34, 2, 3, 4, 6, 10, 3, 2, 999};
    cout << count(a, sizeof(a)/sizeof(int), a[0]) << '\n';
    return 0;
}