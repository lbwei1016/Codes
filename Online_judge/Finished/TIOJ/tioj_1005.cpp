/*
***Math*** -- Prime
*/
#include <bits/stdc++.h>
using namespace std;

const int M = 32768+1;
bool is_prime[M];
vector<int> prime, pfac[M];

void sieve() {
    fill(is_prime, is_prime+M, 1);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<M; ++i) {
        if(!is_prime[i]) continue;
        prime.push_back(i);
        for(int j=i*2; j<M; j+=i) is_prime[j] = false;
    }
}
void calc(int x) {
    int tmp = x;
    for(auto i : prime) {
        if(tmp % i == 0) {
            pfac[x].push_back(i);
            tmp /= i;
        }
        if(is_prime[tmp]) {
            if(tmp <= i) break;
            pfac[x].push_back(tmp);
            break;
        }
    }
}
int main() {
    sieve();
    int n, arr[51];
    while(scanf("%d", &n)) {
        if(n == 0) break;
        int cnt = 0;
        for(int i=0; i<n; ++i) scanf("%d", arr+i);
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                if(arr[i] == arr[j]) continue;
                if(pfac[arr[i]].empty()) calc(arr[i]);
                if(pfac[arr[j]].empty()) calc(arr[j]);
                bool rp = true;
                for(auto x : pfac[arr[i]]) {
                    for(auto y : pfac[arr[j]]) {
                        if(x == y) {
                            rp = false; break;
                        }
                    }
                    if(!rp) break;
                }
                if(rp) {
                    ++cnt;
                    //printf("%d %d\n", arr[i], arr[j]);
                }
            }
        }
        if(cnt) printf("%.6lf\n", sqrt(double(6*n*(n-1))/double((2*cnt))));
        else puts("No estimate for this data set.");
    }
    return 0;
}