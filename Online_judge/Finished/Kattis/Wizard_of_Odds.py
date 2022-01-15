import math 
inp = input()
spl = inp.split()
n, k = int(spl[0]), int(spl[1])
res = math.ceil(math.log2(n))

if k >= res: 
    print("Your wish is granted!")
else: 
    print("You will become a flying monkey!")