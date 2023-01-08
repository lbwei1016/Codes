from collections import deque

MOD = 998244353

n = int(input())


def bfs(n):
    mx = n
    que = deque()
    # print(type(lis))
    que.append((n, [n,]))
    while len(que):
        tup = que.popleft()
        prod, eles = tup[0], tup[1]

        for i in range(len(eles)):
            x = eles[i]
            if x > 3: 
                prod = int(prod // x)
                if x % 2 == 0:
                    cei = flo = (x // 2)
                else:
                    cei = x // 2 + 1
                    flo = x // 2
                prod *= cei * flo
                eles[i] = cei
                eles.append(flo)
                que.append((prod, eles))

                mx = max(mx, prod)
    
    return mx

print(bfs(n) % MOD)