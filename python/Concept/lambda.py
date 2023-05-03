# lambda {paramaters}: {expression}
print(lambda x, y: x + y) # return a object
print((lambda x, y: x + y)(4, 5)) # return value

ls = [1, 2, 3, 4, 5]
print(list(map(lambda x: x + 1, ls)))