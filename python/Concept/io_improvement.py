from sys import stdin
from sys import stdout

# read everything from stdin and then split it by '\n'
# input buffer
inbuf = stdin.read().split('\n')
# counter of inbuf
incnt = 0
# assign read value to n and q
n, q = int(inbuf[incnt]), int(inbuf[incnt + 1])
incnt += 2 

# output buffer; assign sufficient large space
outbuf, outcnt = [0] * q, 0
for i in range(q):
    data = inbuf[incnt]
    incnt += 1
    # do sth
    # something is to be output
    outbuf[outcnt] = data
    outbuf += 1
stdout.write('\n'.join(outbuf))
# If elements in outbuf are not "str", use below format 
# stdout.write('\n'.join(map(str, outbuf)))