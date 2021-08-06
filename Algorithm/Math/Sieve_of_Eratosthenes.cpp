/*
***Sieve of Eratosthenes***
    A more efficient way to find out multiple primes

    O(n * log(log n)) ~= O(n)
*/
#include <iostream>
#include <cmath>

using namespace std;

#define SQRT_N 45

typedef long long ll;
const int N = SQRT_N * SQRT_N;
bool is_prime[N+1]; //if is_prime[i-a] = true, then i is prime -> save memory
bool is_prime_small[SQRT_N]; //[2, sqrt(b))
ll prime[N+1];

int sieve(); //return the number of primes
void segmented_sieve(ll, ll); //sieve prime in range of [a, b)

int sieve() 
{
    for(int i=0; i<=N; i++)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;

    int p = 0;
    for(int i=2; i<=N; i++)
    {
        if(is_prime[i])
        {
            prime[p++] = i;
            for(int j=2*i; j<=N; j+=i)
            {
                is_prime[j] = false;
            }
        }
    }
    return p;
}

void segmented_sieve(ll a, ll b)
{
    //find primes in [2, sqrt(b)) first, and then use it to sieve [a, b)

    //initialization
    int sq = sqrt(b);
    for(int i=2; i<sq; i++)
        is_prime_small[i] = true;
    for(int i=0; i<b-a; i++)
        is_prime[i] = true;

    for(int i=2; i<sq; i++)
    {
        if(is_prime_small[i])
        {
            //[2, sqrt(b)) first
            for(int j=2*i; j<sq; j+=i)
                is_prime_small[j] = false;

            //2LL: represents a value 2 in long long type
            /*
                explanation:
                1. Why "(a+i-1)/i * i" ?
                    -> To find out the first number that is a multiple of i.
                2. Why a + "i" ?
                    -> To ensure the calculation outcome is no less than a.
                3. Why a + i "-1" ?
                    -> Take an example: set a = 33, i = 3；if there isn't "-1",
                       then (a+i)/i * i = (33+3)/3 * 3 = 36. As we can see, "33"
                       is skipped! That's why we need "-1" to involve "a" when 
                       i | a ("a" is a multiple of i).
                4. Why "max(2LL, ...)" ?
                    -> If (a+i-1)/i) < 2, it means that a <= i, and that the multiplication: 
                       "(a+i-1)/i) * i" will be useless, since the result will either
                       be "0" or "i", which makes prime "i" itself "false". Hence, directly 
                       assign j = 2 * j to function properly.
                To unfold it:
                    ll low = a/i * i;
                    if(low < a) 
                        low += i;
                    if(low == i)
                        low += i;
                    for(ll j=low; j<b; j+=i)
                        is_prime[j-a] = false;
            */
            for(ll j=max(2LL, (a+i-1)/i) * i; j<b; j+=i) 
                is_prime[j-a] = false;
        }
    }
    if(a == 1)
        is_prime[0] = 0; //1 - 1 = 0, but 1 is not a prime!
}
int main()
{
    cout << "primes no greater than " << N << '\n';
    int p = sieve();
    cout << p << '\n';
    //for(int i=0; i<p; i++)
        //cout << prime[i] << '\n';
    cout << "\n\n";

    ll a, b;
    cin >> a >> b; //[a, b)
    segmented_sieve(a, b);
    p = 0;
    for(int i=0; i<b-a; i++)
    {
        if(is_prime[i])
        {
            p++;
            //cout << i+a << '\n';
        }
            
    }
    cout << p << '\n';
    return 0;
}