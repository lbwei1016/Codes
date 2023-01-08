def add(a, b):
    return a + b
def nullfunc():
    pass
# arbitrary arguments
def multiadd(*vals):
    # "vals" is a "tuple"(data type)
    sum = 0
    # print(vals[0])
    print("Lenghth: %d" %(len(vals)))
    print(type(vals))
    for i in range(len(vals)):
        sum += vals[i]
    return sum
# default parameter value
def sayHi(name = "William"):
    print("Hi %s" %(name))
# arbitrary keyword arguments (**kwargs)
def sayHi_toAll(**names):
    print(names["A"])


a, b = 10, 20
print(add(a, b))
print(multiadd(a, b, 10, 5, 1))
sayHi()
sayHi(name = "Ruby")
sayHi_toAll(A="Wiwi", B="Dodo")
