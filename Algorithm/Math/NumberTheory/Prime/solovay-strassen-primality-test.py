from random import randint
from math import gcd, sqrt

def legendre_symbol(a, p):
    return fast_pow(a, (p - 1) // 2, p)

def jacobi_symbol(a, n):
    factor = 1
    while a >= 3 and n >= 3:
        if gcd(a, n) != 1: 
            return 0
        
        while a % 2 == 0:
            factor *= fast_pow(-1, (n**2 - 1) // 8)
            a //= 2

        factor *= fast_pow(-1, (a - 1) * (n - 1) // 4)
        _a = n % a
        a, n = _a, a

    # now a = 0, 1 or 2
    if a < 2:
        return factor
    return fast_pow(-1, (n**2 - 1) // 8) * factor


# x^n % M
def fast_pow(x, n, M=-1):
    res = 1
    while n > 0:
        if n & 1:
            res *= x
        x *= x
        n >>= 1

        if M > 0:
            res %= M
            x %= M
    return res


def get_Bn(n) -> list:
    Bn = []
    for a in range(1, n):
        if gcd(a, n) != 1: continue
        if (jacobi_symbol(a, n) + n) % n == fast_pow(a, (n - 1) // 2, n):
            Bn.append(a)
    return Bn


def prime_test(n) -> bool:
    if n % 2 == 0: return False
    Bn = get_Bn(n)

    r = 10
    samples = set()
    while len(samples) < r:
        a = randint(2, n - 1)
        if a in samples: continue
        if gcd(a, n) != 1: continue
        samples.add(a)
    
    for a in samples:
        if a not in Bn: return False

    return True
        

if __name__ == '__main__':
    N = [8, 35, 17, 21, 23]
    for n in N:
        print(prime_test(n))