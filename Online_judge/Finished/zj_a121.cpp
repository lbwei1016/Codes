/*
***Prime***
    Description:
        Query of the number of primes in [a, b]
    
    O(sqrt(N) * q)
        q: number of queries
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int SQRT_MAX_N = 10000+1;
bool is_prime[SQRT_MAX_N];
bool is_prime_seg[1000+1];

void sieve() {
    for(int i=2; i<=SQRT_MAX_N; i++) 
        is_prime[i] = true;
    for(int i=2; i<=SQRT_MAX_N; i++) {
        if(is_prime[i]) {
            for(int j=2*i; j<=SQRT_MAX_N; j+=i)
                is_prime[j] = false;
        }
    }
}

void seg_sieve(ll a, ll b) {
    for(int i=0; i<=b-a; i++) is_prime_seg[i] = true;
    for(int i=2; i<=sqrt(b); i++) {
        if(is_prime[i]) {
            for(ll j=max(2LL, (a+i-1)/i) * i; j<=b; j+=i) 
                is_prime_seg[j-a] = false; 
        }
    }
    if(a == 1)
        is_prime_seg[0] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    ll a, b;
    while(cin >> a >> b) {
        seg_sieve(a, b);
        int cnt = 0;
        for(int i=0; i<=b-a; i++) {
            if(is_prime_seg[i])
                cnt++;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}