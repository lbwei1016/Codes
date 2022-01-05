#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int N = 2e5+5;
int t, n, e, a[N];

inline bool prime_check(ll pro) {
    if(pro < 2) return false; 
    for(int i=2, sq=sqrt(pro); i<=sq; ++i) {
        if(!(pro % i)) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--) {
        int cnt = 0;
        bitset<N> isprime;
        isprime.reset();
        cin >> n >> e;
        for(int i=1; i<=n; ++i) {
            cin >> a[i];
            isprime[i] = prime_check(a[i]);
        }
        for(int i=1; i+e<=n; ++i) {
            if(!isprime[i] && a[i]!=1) continue;
            bool prime = isprime[i];
            int pick1 = (a[i]==1);
            for(int k=1; i+e*k<=n; ++k) {
                if(a[i+e*k] == 1) {
                    if(++pick1 == k+1) continue;
                    if(prime) ++cnt;
                }
                else if(prime) break;

                if(isprime[i+e*k]){
                    prime = true;
                    ++cnt;
                }
            }
        }
        cout << cnt << '\n';
    }    
    return 0;
}