import random as rand

file = "in.in"
ff = open(file, "w")

N = 30
ff.write(str(N)+" 1000000009\n")
for i in range(N):
    ff.write(str(rand.randint(-1000, 10000))+' ')
ff.write("\n")
ff.close()