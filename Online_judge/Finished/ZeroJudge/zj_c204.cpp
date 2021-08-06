/*
***Prime*** --UVa13194
    Description:
        找出因數和(不包含自己)等於自己的數(perfect)
    Solution:
        1. 建質數表
        2. sqrt(N) 質因數分解
        3. 等比級數 (避免 owerflow)

    O(sqrt(N))
*/
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAX_N = 1e6+1;
struct factor { ll p, cnt; };

ll N;
bool is_prime[MAX_N];
vector<int> primes;
vector<factor> v; //N's factors except N itself

//sieve of Eratosthenes
void sieve() {
    for(int i=2; i<MAX_N; i++)
        is_prime[i] = true;

    int cnt = 0;
    for(int i=2; i<MAX_N; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=2*i; j<MAX_N; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    ll n = N;
    //將 N 質因數分解，只需到 sqrt(N)
    for(int i=0; n>1 && primes[i]<sqrt(N); i++) {
        if(n % primes[i] == 0) {
            int cnt = 0;
            for(; n%primes[i] == 0; cnt++) 
                n /= (ll)primes[i];
            v.push_back((factor){primes[i], cnt});
        }
    }
    //若 N 還沒被完全分解，那剩下的因數一定是質數，並且要排除 N 為質數的情形
    if(n != 1 && v.size() != 0)
        v.push_back((factor){n, 1});

    ll res = 1;
    for(int i=0; i<v.size(); i++) {
        if(v[i].cnt == 1) //避免 owerflow
            res *= (v[i].p + 1);
        else 
            res *= (pow(v[i].p, v[i].cnt+1) - 1) / (v[i].p - 1); //等比級數
    }
    res -= N;
    if(res == N) {
        printf("perfect\n");
    } 
    else if(res < N) {
        printf("deficient\n");
    }
    else {
        printf("abundant\n");
    }
}

int main() { 
    sieve();
    int t;
    scanf("%d", &t);
    while(t--) {
        v.clear();
        scanf("%lld", &N);
        solve();
    }
    
    return 0;
}