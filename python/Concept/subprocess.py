from random import randint as rand
import subprocess

inp = open('./3.in', 'r')
out = open('./3.ans', 'w')
cmd = './sol.exe'
proc = subprocess.Popen(cmd, stdin=inp, stdout=out)
proc.wait()
out.flush()