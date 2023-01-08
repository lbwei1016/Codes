/*
    O(sqrt(n))
*/
#include <iostream>
#include <cmath>

using namespace std;

#define N 2500

int num_prime[N+1];
bool prime(int x)
{
    int sq = sqrt(x);
    for(int i=2; i<=sq; i++)
    {
        if(x % i == 0)
            return false;
    }
    return x != 1;
}
int main()
{
    int p = 0;
    for(int i=2; i<=N; i++)
    {
        if(prime(i))
            num_prime[p++] = i;
    }
    
    cout << "primes no greater than 1000" << '\n';
    int i;
    for(i=0; i<p; i++)
        cout << num_prime[i] << '\n';
    cout << i << '\n';
    return 0;
}