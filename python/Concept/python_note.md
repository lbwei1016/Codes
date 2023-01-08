# Basics
## I/O
```py
# return a string
a = input("Say something: ")
print(a, "Hi there")
```
## Variables & Operations
```py
a = 10
b = 3
c = a // b # c = 3(int)
d = a / b # d = 3.3333....(float)
e = a ** b # e = 10 ^ 3

x = 1.25
y = 0.5
z = x % y # z = 0.25
```
### Walrus operator ( := )
```py
num = int(input)
print(num)

# the above codes is equivalent to:
print(num:=int(input()))
```

## String
```py
s1 = "Gaga"
print(s1 * 3) # "GagaGagaGaga"

s2 = """
I am Ken.
Nice to meet you!
See you later!
"""
```
## List
### Declaration & Operation
```py
names = ['William', 'Ruby', 'George', 'Amy']
person1 = names[0]

# empty
empty_list = []

#nested, with different types
name_age = [['William', 19], ['Ruby', 18], 343.0]

# to repeat
print(name * 3) 

# find elements in a list
find_name = "William" in names # return True
find_name = "William" in name_age # False
```
### Method
```py
names.append("Jush") # like "push_back"
len(names) # return 5
names.insert(2, "Martin")

# return the index of the first occurence of that element
# if it's not found, py throws an error
names.index("Ruby") 

string = "I am a good boy!"
# split the string when encountering a delimeter
# deli is ' '(space) by default
# deli will be discarded
sub = string.split([deli]) 

# range(i, j, interval):
    # An object containing an array of integers
    # in range [i, j)�F (de)increase by "interval"
a = range(10) # by default: [0, 10), increase by 1
b = list(range(1, 10, -3)) # convert to a list

# get ASCII or Unicode
a_ascii = ord('a') # 97
a_char = (chr)a_ascii # a
```
## if statement & Loops
```py
if 1.0 == 1 and 3 == 3:
# do something
elif True != False or not 2 > 4:
# do something
else:
#do something
```
```py
while a > b:
    # ...

animals = ["dog", "cat", "turtle"]
for ani in animals:
    print(ani + " cute!\n")
for i in range(10):
    print(i)
```
## Library
### random
```py
    import random as r

    print(r.random()) # return a float [0, 1)
    print(r.uniform(-2, 90)) # return a float [a, b)
    print(r.randint(1, 10)) # return a int [a, b]
    print(r.randrange(10, 100, 3)) # return a int [a, b) with step 3`
```

## ByteIO
```py
    fh = io.BytesIO()
    # write binary to file.txt
    with open("file.txt", 'wb') as ff:
        ff.write(fh.getbuffer())
```

## Others
```py
with RESOURCE as VAR:
    ...
# 將 RESOURCE 指定給 VAR，並在 block 執行結束後，釋放 RESOURCE (e.g. 關閉檔案)
with open("file.txt", 'w') as ff:
    # do sth
``` 