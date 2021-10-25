/*
***Recursion***
    The worst case can reach 2^10000, but it actually don't go that bad.
    (for an easy pruning "if(divi) return;")
    If the problem is like "leetcode 1981" aiming to a find optimal solution,
    dp is certainly needed.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int n, k;
int arr[N];
bool divi = 0;

void rec(int val, int d) {
    if(divi) return;
    if(d == n) {
        if(val % k == 0) divi = 1;
        return;
    }
    int a = val+arr[d], b = val-arr[d];
    rec(a, d+1); rec(b, d+1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=0; i<n; ++i) cin >> arr[i];
    rec(arr[0], 1);
    if(divi) cout << "Divisible\n";
    else cout << "Not divisible\n";
    return 0;
}