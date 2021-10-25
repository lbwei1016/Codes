/*
***Recursion***
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[4] = {10000000, 100000, 1000, 100};
char s[4][20] = {"kuti", "lakh", "hajar", "shata"};

void rec(ll n) {
    if(n == 0) return;
    for(int i=0; i<4; ++i) {
        if(n / arr[i]) {
            rec(n / arr[i]);
            printf(" %s", s[i]);
            n %= arr[i];
        }
    }
    if(n) printf(" %lld", n);
}
int main() {
    ll n;
    for(int i=1; scanf("%lld", &n) != EOF; ++i) {
        int cnt = 0, tmp = i;
        // left alignment
        while(tmp > 0) ++cnt, tmp/=10;
        printf("%d.", i);
        for(int j=1-cnt; j>0; --j) putchar(' ');
        if(n) {
            rec(n);
            puts("");
        }
        else puts(" 0");
    }
    return 0;
}