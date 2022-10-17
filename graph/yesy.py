from random import randint as rand

N = 18
ff = open('in.txt', 'w')
ff.write(str(N) + '\n')
for i in range(N):
    le = rand(1, 20)
    s = ""
    for j in range(le):
        s += (chr)(ord('a') + rand(0, 25))
    ff.write(s + '\n')
