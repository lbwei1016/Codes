/*
***Experiment*** -- # of divisors
    Define:
        d(n): number of divisors of n
    Description:
        For n <= 1e6, d(n) <= 13lg(n);
        for n <= 1e7, d(n) <= 20lg(n).
        The ratio of "sum(d(n)) / N" is approx. "14" for N = 1e6, 
        "16" for N = 1e7.
    Time:
        < 500ms
*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long;

const int N = 1e6+1;
vector<int> primes;
vector<bool> isp; // is_prime

ll CNT;

void sieve() {
    isp.assign(N, 1);
    isp[0] = isp[1] = 0;
    for (int i=2; i<N; ++i) {
        if (isp[i]) {
            primes.push_back(i);
            for (int j=2*i; j<N; j+=i) 
                isp[j] = false;
        }
    }
}

// prime factorization
ll divisors(int n) {
    ll div = 1, sqn = sqrt(n);
    for (int i=0; n>1; ++i) {
        ++CNT;
        if (primes[i] > sqn) break;
        ll cnt = 1;
        while (n % primes[i] == 0) {
            ++CNT;
            n /= primes[i];
            ++cnt;
        }
        div *= cnt;
    }    
    return div * (isp[n]+1); // remaining divisor is n
}

int main() {
    sieve();
    ll cnt = 0;
    for (int i=2; i<N; ++i) {
        ll k = divisors(i);
        cnt += k;
        if (k > 13*(ll)log2(i)) // d(n) <= 13lg(n), for n <= 1e6
            printf("who: %d; #: %lld\n", i, k);
    }
    cout << "N = " << N << '\n';
    cout << "sum of d(n): " << cnt << '\n';
    cout << "sum(d(n)) / N: " << double(cnt)/N << '\n'; // 13.97
    cout << "(rough) # of iterations: " << CNT << '\n'; // 1e8
    return 0;
}