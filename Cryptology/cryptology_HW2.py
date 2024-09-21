from math import gcd
from random import randint

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

def in_QR(a, N):
    for i in range(1, N):
        if gcd(i, N) != 1: continue
        if i**2 % N == a: 
            return True
    return False


def legendre_symbol(a, p):
    return fast_pow(a, (p - 1) // 2, p)


def sqrt_mod_prime(a, p):
    if legendre_symbol(a, p) != 1:
        print(f'{a} is not in QR({p})!')
        return -1

    if (p + 1) % 4 == 0:
        sqrt = fast_pow(a, (p + 1) // 4, p)
    else:
        k = (p - 1) // 2
        r = k
        L = 0
        while r % 2 == 0:
            r //= 2
            L += 1

        b = randint(2, p - 1)
        while fast_pow(b, k, p) == 1:
            b = randint(2, p - 1)

        s = 0
        while L > 0:
            s //= 2
            L -= 1
            z = (fast_pow(a, r * fast_pow(2, L), p) * fast_pow(b, s, p)) % p
            if z == p - 1:
                s += k
    
        sqrt = fast_pow(a, (r + 1) // 2, p) * fast_pow(b, s // 2, p) % p

    assert(fast_pow(sqrt, 2, p) == a)
    return sqrt


if __name__ == '__main__':
    print('Input a and p to compute the square root of a mod p:')
    s = input()
    a, p = s.split()
    a, p = int(a), int(p)
    sqrt = sqrt_mod_prime(a, p)
    if sqrt > 0:
        print(f'square root of {a} mod {p} = {sqrt}')

