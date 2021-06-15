/*
***Prime***
(ICPC)
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX_PRIME 1299709

bool is_prime[MAX_PRIME+1];
vector<int> primes;

void sieve()
{
    for(int i=2; i<=MAX_PRIME; i++)
        is_prime[i] = true;
    int sq = sqrt(MAX_PRIME);
    for(int i=2; i<=sq; i++)
    {
        if(is_prime[i])
        {
            for(int j=2*i; j<=MAX_PRIME; j+=i)
                is_prime[j] = false;
        }
    }

    for(int i=2; i<=MAX_PRIME; i++)
    {
        if(is_prime[i])
            primes.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    sieve();
    while(cin >> n)
    {
        if(!n)
            break;
        if(is_prime[n])
        {
            cout << "0\n";
            continue;
        }
        auto pos2 = lower_bound(primes.begin(), primes.end(), n);
        auto pos1 = pos2 - 1;
        int ans = (*pos2) - (*pos1);
        cout << ans << '\n';
    }
    
    return 0;
}