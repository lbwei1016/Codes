from math import gcd, sqrt, ceil
from random import randint

def encrypt(e, n, m):
    return m**e % n

def decrypt(d, n, c):
    return c**d % n

def calc_secret_key(e, p, q):
    phi_n = (p - 1) * (q - 1)
    return pow(e, -1, phi_n)

# This can be replaced by ordinary pow()
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


def PPT_factoring(n, e, d, w) -> tuple[int, int]:
    # w = randint(2, n - 1)
    # k = gcd(w, n)
    # if k != 1: return (k, n //k)

    s = 0
    ed = e * d
    r = ed - 1
    print(f'ed - 1 = {r}')
    while r % 2 == 0:
        s += 1
        r //= 2
    print(f'(s, r) = {s, r}')
    assert(fast_pow(2, s) * r == ed - 1)

    for i in range(s):
        # v = (w ** (r * 2**i)) % n
        v = fast_pow(w, r * fast_pow(2, i), n)
        v1 = (v ** 2) % n
        print(f'v = {v}, v1 = {v1}')
        if v1 == 1 and v != 1 and v != n - 1:
            p = gcd(v - 1, n)
            q = n // p
            assert(p * q == n)
            return (p, q)
    return (-1, -1)


from functools import reduce
def factors(n):    
    return set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))


def weak_parameter_attack(n) -> tuple[int, int]:
    z = ceil(sqrt(n))
    print(f'z = {z}')
    for i in range(n):
        y = z + i
        print(f'y**2 - n = {y**2 - n}')
        x = int(sqrt(y ** 2 - n))
        if x ** 2 == y ** 2 - n:
            return (y - x, y + x)
    return (-1, -1)


def ElGamel_enc(p, g, y, m, k):
    return (pow(g, k, p), m * pow(y, k, p) % p)


def ElGamel_dec(p, a, b, x):
    return b * pow(a, -x, p) % p


# Find discrete log
def Shanks_algo(p, g, y):
    m = ceil(sqrt(p - 1))
    print(f'm = {m}')
    # L1 = [(j, pow(g, m * j, p)) for j in range(m)]
    # L2 = [(i, y * pow(g, -i, p) % p) for i in range(m)]

    # L1.sort(key=lambda z: z[1])
    # L2.sort(key=lambda z: z[1])
    # print(L1)
    # print(L2)

    L1 = [pow(g, m * j, p) for j in range(m)]
    L2 = [y * pow(g, -i, p) % p for i in range(m)]

    print(f'L1: {L1}\nL2: {L2}')

    for j, z in enumerate(L1):
        c = L2.count(z)
        if c > 0:
            i = L2.index(z)
            print(i)
            res = (m * j + i) % (p - 1)
            assert(pow(g, res, p) == y)
            return res
    
    return -1


def prob1():
    p, q = 317, 547
    e = 17
    n = p * q
    d = calc_secret_key(e, p, q)
    print(f'd = {d}')
    # print((p - 1) * (q - 1))

    m0 = 3175
    c0 = encrypt(e, n, m0)
    assert(decrypt(d, n, c0) == m0)
    print(f'c0 = {c0}')

    c1 = 2313
    m1 = decrypt(d, n, c1)
    assert(encrypt(e, n, m1) == c1)
    print(f'm1 = {m1}')


def prob2():
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]
    p, q = (-1, -1)
    n, e, d = (421301, 65537, 153473)
    # n, e, d = (89855713, 34986517, 82330933)

    # for w in primes:
    # # for w in range(2, n):    
    #     p, q = PPT_factoring(n, e, d, w)
    #     print(f'n: (p, q) = ({p}, {q}); w = {w}')
    w = 2
    p, q = PPT_factoring(n, e, d, w)
    print(f'n: (p, q) = ({p}, {q}); w = {w}')


def prob3():
    n = 5083607
    print(factors(n))
    print(weak_parameter_attack(n))


def prob4():
    n = 18721
    c1, c2 = 12677, 14702
    m = pow(c1, 2692, n) * pow(c2, -15, n) % n
    print(m)

    e1, e2 = 43, 7717
    assert(m**e1 % n == c1 and m**e2 % n == c2)


def prob5():
    p, g, x = 113, 17, 25
    y = pow(g, x, 113)
    print(f'y = {y}')

    m, k = 23, 22
    a, b = ElGamel_enc(p, g, y, m, k)
    print(f'(a, b) = {a, b}')
    m_dec = ElGamel_dec(p, a, b, x)
    print(f'm_dec = {m_dec}')
    assert(m_dec == m)

    m = ElGamel_dec(p, 7, 35, x)
    print(f'm = {m}')


def prob6():
    p, g, y = 449, 13, 61
    res = Shanks_algo(p, g, y)
    print(res)

if __name__ == '__main__':
    prob6()