import random as rand

file = "in.in"
ff = open(file, "w")

N = 110
X = 1000
for i in range(N):
    ff.write(str(X+i)+' 0\n')
ff.close()

