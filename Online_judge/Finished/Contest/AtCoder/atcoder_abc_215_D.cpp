/*
***Math*** -- co-prime
    Description:
        Given a sequence An = {A1, A2, ...}, find every positive 
        integer k no greater than M such that "gcd(Ai, k) = 1 | 1<=i<=n".
    Solution:
        Use a table to store every possible factor of Ai | 1<=i<=n, and 
        then check every positive integer.
    Note:
        Sieving primes first only speeds up a little bit.
*/
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+5;
int n, m, cnt;
int arr[N], ans[N];
unordered_set<int> S;
bool is_prime[N];
 
void sieve() {
    fill(is_prime+2, is_prime+N, 1);
    for(int i=2; i<N; ++i) {
        if(is_prime[i]) {
            for(int j=2*i; j<N; j+=i) {
                is_prime[j] = 0;
            }
        }
    }
}
 
int main() {
    scanf("%d%d", &n, &m);
    // sieve();
    for(int i=0; i<n; ++i) scanf("%d", arr+i);
    for(int i=0; i<n; ++i) {
        // if(is_prime[arr[i]]) {
        //     S.insert(arr[i]);
        //     continue;
        // }
        for(int j=1, k=sqrt(arr[i]); j<=k; ++j) {
            if(arr[i] % j == 0) {
                S.insert(j); S.insert(arr[i]/j);
            }
        }
    }
    S.erase(1);
    int t; cnt = 1;
    ans[0] = 1;
    bool flag = 1;
    for(int i=2; i<=m ;++i) {        
        flag = 1;
        // if(is_prime[i]) {
        //     if(S.count(i)) {
        //         flag = 0;
        //     }
        // }
        // else {
            for(int j=1, k=sqrt(i); j<=k; ++j) {
                if(i % j == 0) {
                    t = i/j;
                    if(S.count(t) || S.count(j)) {
                        flag = 0; break;
                    } 
                }
            }
        // }
        if(flag) ans[cnt++] = i;
    }
    printf("%d\n", cnt);
    for(int i=0; i<cnt; ++i) printf("%d\n", ans[i]);
    return 0;
}