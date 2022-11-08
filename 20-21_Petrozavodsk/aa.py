N = 1000000
a0 = 960002411612632915
g = 42
MOD = 10**18 + 31
# res = [0] * (N + 1)
# res[N] = 300
# res[0] = a0

n = int(input())

def fpow(x, n):
    res = 1
    while n > 0:
        if n & 1:
            res *= x
            res %= MOD
        x *= x
        x %= MOD
        n >>= 1
    return res

pre = 300
pt = 1
ff = open('file.txt', 'w')
arr = [300]
for i in range(N-1, n-1, -1):
    pre = fpow(g, pre)
    # pre = g ** pre
    pre %= MOD
    if pt == 10000:
        arr.append(pre)
        pt = 0
    pt += 1
    # print(i)
    # res[i] = fpow(g, res[i+1])

# # print(res[n])
print(pre)

ff.write(str(arr))