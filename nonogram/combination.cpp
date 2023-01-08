#include <bits/stdc++.h>
using namespace std;

int hint[3] = {1, 2, 3};
int a[3] = {0b1000000000, 0b0011000000, 0b0000011100};
bitset<10> B;

void rec(int d, const int n, int num, int at, int sum, int has_moved) {
    if(d == n) {
        B = num;
        // cout << num << '\n';
        for(int i=9; i>=0; --i) cout << B[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0; i<=at-(sum)-(n-(d+1));  ++i) {
        // a[d] >>= i;
        // num |= (a[d] >> (i+has_moved));
        // rec(d+1, n, sum-a[d], num);
        rec(d+1, n, (num|(a[d] >> (i+has_moved))), at-i-hint[d]-1, sum-hint[d], has_moved+i);
        // num ^= (a[d] >> (i+has_moved));
    }
}

int main() {
    int sum = 6;
    rec(0, 3, 0, 10, sum, 0);
    return 0;
}