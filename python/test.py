import random as rand

file = "in.in"
ff = open(file, "w")
N = rand.randint(3, 23)
#ff.write(str(N)+'\n')
for i in range(N):
    L = rand.randint(5, 21)
    for j in range(L):
        r = rand.randint(0, 1)
        if r & 1:
            ff.write(chr(rand.randint(0, 25)+ord('A')))
        else :
            ff.write(str(rand.randint(1, 9)))
    ff.write('\n')
ff.close()

