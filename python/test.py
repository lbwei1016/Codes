v = eval("9*2")
print(v)
s = "abcdefghi"
s2 = ""
for i in range(len(s)):
    if(i+1 & 1):
        s2 += s[i]
    else:
        s2 += s[i].upper()

print(s2)