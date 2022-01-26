#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a, N, res = 1e9;

unordered_set<int> S;

int pow(int x, int n) {
    int res = 1;
    while(n > 0) {
        if(n & 1) res *= x;
        n >>= 1;
        x *= x;
    }
    return res;
}
int op(int n) {
    int dig = 0, tmp = n;
    int highest;
    while(tmp > 0) {
        highest = tmp % 10;
        tmp /= 10;
        ++dig;
    }
    n = (n - highest*pow(10, dig-1))*10 + highest;
    return n;
}
void rec(int n, int d) {
    if(n == 1) {
        res = min(res, d);
        return;
    }
    if(n % a == 0) {
        int k = n / a;
        if(S.count(k)) return;
        S.insert(k);
        rec(k, d+1);
    }
    if(n % 10 != 0 && n > 10) {
        n = op(n);
        if(S.count(n)) return;
        S.insert(n);
        rec(n, d+1);
    }
}

int main() {
    cin >> a >> N;
    rec(N, 0);
    if(res == 1e9) puts("-1");
    else cout << res << '\n';
    return 0;
}