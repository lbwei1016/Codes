import random
print(random.random()) # return a float [0, 1)
print(random.uniform(-2, 90)) # return a float [a, b)
print(random.randint(1, 10)) # return a int [a, b]
print(random.randrange(10, 100, 3)) # return a int [a, b) with step 3