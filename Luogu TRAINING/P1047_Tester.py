#coding=utf-8
from random import randint

n = randint(10000000, 99999999)
m = randint(5000, 10000)

with open("E:\\C learning\\P1047_data.in", 'w') as f:
    f.write(str(n)+' '+str(m)+'\n')
    for i in range(m):
        a = randint(0, n)
        b = randint(a, n)
        f.write(str(a)+' '+str(b)+'\n')
