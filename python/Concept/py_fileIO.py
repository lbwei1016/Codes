file = "hi.txt"

text = ['I ', 'am ', 'RRR']

f = open(file, "w")
for t in text:
    f.write(t) # once a word
f.close()

f = open(file, 'r')
for t in f.readline(): # once a line
    print(t)

f.close()

f = open(file, 'a') # append
f.writelines(text) # once a line
f.close()

with open(file, 'r') as f: #don't need f.close()
    print(f.read()) # read everything


