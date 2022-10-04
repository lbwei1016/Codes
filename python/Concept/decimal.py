from random import randint as rand
from unittest import skip
import math
# 浮點數運算
from decimal import Decimal, getcontext

N = 1001
dp = [[0 for x in range(N)] for y in range(N)]
# print(dp)

def bino():
    for i in range(N):
         dp[i][0] = dp[0][i] = 1
    for i in range(N):
        if i == 0:
            continue
        for j in range(N):
            if j == 0:
                continue
            dp[i][j] += dp[i-1][j] + dp[i][j-1]

bino()
# print(dp)
sum1 = 0

for i in range(51):
    sum1 += dp[1000-i][i] * (0.01)**i * (0.99)**(1000-i)
print(1-sum1)

# 改精確度
getcontext().prec = 100

sum2 = 0
euler = '2.718281828459045'
em10 = Decimal(math.e)**(Decimal(-10))
# print(em10)

k = 1
for i in range(51):
    p = em10 * Decimal(10**i) / k
    sum2 += p
    k *= (i+1)
    print("cool", p)

print(sum2)