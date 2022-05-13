import random as rand

all, inside = 0, 0
N = 10000

def dist(x, y):
    return x*x + y*y

while True:
    x, y = rand.random(), rand.random()
    # print("x: ", x, "y: ", y)
    all += 1
    if (dist(x, y) < 1.0):
        inside += 1
    # print(inside, all)
    print("current pi: ", 4*inside/all, '\n')