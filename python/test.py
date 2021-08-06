import random as rand

file = "in.in"
ff = open(file, "w")
N = 10
L = 10000-1

ff.write(str(N)+"\n")
for i in range(N):
    for j in range(L):
        ff.write(chr(ord('a')+rand.randint(0, 25)))
    ff.write('\n')
ff.close()

