c = 5 + 3j # complex
l = ['I', 'am', 'a', 'list']

t = ('I', 'am', 'a', 'tuple') # tuple: ordered, immutable
# ordered means that the elements always stay in their position
# (doesn't mean sorted !!!)

r = range(10)
dic = {'cat': 'cute', 'dog': 'cute, too'} # dictionary

s = {'I', 'am', 'a', 'set', 'set'} # set: unordered, mutable
# unordered meas that you cannot expect which permutation the elements
# will appear 

fs = frozenset({'WOW', 'Frozen!', 'WOW'}) # frozenset: ordered, immutable (tuple + set) 
b = True

# below: not clear yet
bt = b'Byte'
bt_arr = bytearray(5)
mv = memoryview(bytes(10))

L = [c, l, t, r, dic, s, fs, b, bt, bt_arr, mv]
for i in range(len(L)):
    print(L[i])
print(dic['cat'])
s.add()