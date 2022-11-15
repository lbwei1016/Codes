import random as rand

ff = open('in.txt', 'w')

R, C = rand.randint(20000, 1000000), rand.randint(20000, 1000000)
K = rand.randint(10000, 50000)
x, y = list(), list()
for i in range(2):
    x.append(rand.randint(1, R))
for i in range(2):
    y.append(rand.randint(1, C))
ff.write(
    "{0} {1} {2}\n{3} {4} {5} {6}\n".format(
        R, C, K, x[0], y[0], x[1], y[1]
    )
)




