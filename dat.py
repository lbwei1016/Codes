import random as rand

T, N = 1, 500
ff = open("inp.txt", "w")
ff.write(str(T)+'\n')
for t in range(T):
    ff.write(str(N)+'\n')
    for i in range(N):
        for j in range(N):
            pp = rand.randint(1, 10)
            if pp >= 5:
                ff.write("-1 ")
            else:
                ff.write(str(rand.randint(0, 1))+' ')
            # ff.write(str(rand.randint(-1, 1))+' ')
        ff.write("\n")

    for i in range(N):
        for j in range(N):
            ff.write(str(rand.randint(1, 10))+' ')
        ff.write("\n")
    for i in range(2):
        for j in range(N):
            ff.write(str(rand.randint(0, 1))+' ')
        ff.write("\n")