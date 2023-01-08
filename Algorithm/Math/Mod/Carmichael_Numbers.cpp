/*
***Math*** -- Carmichael Numbers
    Description:
        Fermat's Little Theorem claims that:
            a^p ≡ a (mod p), for p is a prime.
        However, some "composite numbers (合數)" also comply with the
        above theorem, and those composite numbers are called "Carmichael numbers".
    O(log n)
*/
#include <iostream>

using namespace std;

#define N 65001

typedef long long ll;

bool is_prime[N];

ll mod_power(ll, ll, ll);
ll mod_power_recu(ll, ll, ll);
ll gcd(ll, ll);
void sieve();

int main()
{
    sieve(); //find primes
    ll n;
    bool car_yes = false;
    cin >> n;

    for(ll i=2; i<n; i++)
    {
        if(gcd(i, n) == 1)
        {
            ll xn = mod_power(i, n, n);
            if(xn == i % n)
                car_yes = true;
            break;
        }
    }
    if(car_yes && !is_prime[n])
        cout << "Yes\n";
    else
        cout << "No\n"; 
    return 0;
}

ll gcd(ll x, ll n)
{
    if(n == 0)
        return x;
    return gcd(n, x%n);
}

void sieve()
{
    for(int i=2; i<N; i++)
        is_prime[i] = true;
    for(int i=2; i<N; i++)
    {
        if(is_prime[i])
        {
            for(int j=2*i; j<N; j+=i)
                is_prime[j] = false;
        }
    }
}

//"+"、"-"、"*" can be applied to the calculation of "mod"(%) 
ll mod_power(ll x, ll n, ll mod)
{
    ll res = 1;
    while(n > 0)
    {
        /*
            e.g. 
            n = 41(101001) = 2^5 + 2^3 + 2^0
            x^n = x^(2^5) * x^(2^3) * x^(2^0)
        */
        if(n & 1)
            res = res * x % mod; // x^n % mod = res
        x = x * x % mod; //x -> x^(2^k)
        n >>= 1;
    }
    return res;
}

//another method for solving x^n
ll mod_power_recu(ll x, ll n, ll mod)
{
    if(n == 0)
        return 1;
    ll res = mod_power_recu(x*x % mod, n/2, mod);
    if(n & 1)
        res = res * x % mod;
    return res;
}

