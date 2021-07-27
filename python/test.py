import random as rand

file = "out4.out"
ff = open(file, "w")
N = 10

V = rand.randint(N, 2*N)
E = rand.randint(N, 3*N)
ff.write(str(V)+' '), ff.write(str(E)+'\n')
for i in range(E):
    u = rand.randint(1, V)
    v = rand.randint(1, V)
    w = rand.randint(1, 5)
    cont = [str(u)+' ', str(v)+' ', str(w)+'\n']
    ff.writelines(cont)
Q = rand.randint(N/10, N/5)
ff.write(str(Q)+'\n')
for i in range(Q):
    u = rand.randint(1, V)
    v = rand.randint(1, V)
    cont = [str(u)+' ', str(v)+'\n']
    ff.writelines(cont)
ff.close()

