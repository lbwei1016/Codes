import heapq

MOD = 998244353

n = int(input())


def bfs(n):
    mx = 100000000000000000
    pq = []
    # this heap stores tuples
    heapq.heappush(pq, (-1, n))
    while len(pq):
        tup = heapq.heappop(pq)
        prod, x = int(tup[0]), int(tup[1])
        print('\nprod, x: ', prod, x)

        mx = min(mx, x*prod)
        print('mx: ', mx)
        
        if x <= 3:
            continue
        if x % 2 == 0:
            cei, flo = x // 2, x // 2
            prod *= cei
            print('cei, flo: ', cei, flo)
            heapq.heappush(pq, (prod, cei))
        else:
            cei = x // 2 + 1
            flo = x // 2
            print('cei, flo: ', cei, flo)
            heapq.heappush(pq, (prod*flo, cei))
            heapq.heappush(pq, (prod*cei, flo))
    return mx
print(bfs(n))

