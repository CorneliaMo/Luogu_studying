#coding=utf-8
from random import randint

n = randint(10000000, 99999999)

with open("C:\\numbers.txt", 'w') as f:
    f.write(str(n)+'\n')
    for i in range(n):
        f.write(str(randint(0, 99999999))+'\n')
    
