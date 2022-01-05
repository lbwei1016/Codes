import random as rand
import numpy as np

N, M, MAX = 6000, 100, 65535
arr = np.empty(N*M, dtype='i')
arr = arr.reshape(N, M)
file = "matrix.txt"
ff = open(file, 'w')

for i in range(N):
    for j in range(M):
        arr[i][j] = rand.randint(0, 200)
        ff.write(str(arr[i][j])+' ')
    ff.write('\n')
