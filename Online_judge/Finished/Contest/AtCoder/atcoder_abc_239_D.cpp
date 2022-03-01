#include <bits/stdc++.h>
using namespace std;

const int N = 300;
bool is_prime[N];
int a, b, c, d;

void sieve() {
    for(int i=2; i<N; ++i) 
        is_prime[i] = 1;
    for(int i=2; i<N; ++i) {
        if(is_prime[i])
            for(int j=2*i; j<N; j+=i)
                is_prime[j] = 0;
    }
}

bool play(int x) {
    for(int i=c; i<=d; ++i) {
        if(is_prime[i+x]) return 0;
    }
    return 1;
}
// the first win: return 0
bool solve() {
    for(int i=a; i<=b; ++i) {
        if(play(i)) return 1;
    }
    return 0;
}

int main() {
    sieve();
    cin >> a >> b >> c >> d;
    if(solve()) puts("Takahashi");
    else puts("Aoki");
    return 0;
}