#coding=utf-8
from random import randint

n = randint(1000000, 9999999)

with open("./numbers.txt", 'w') as f:
    f.write(str(n)+'\n')
    for i in range(n):
        f.write(str(randint(0, 99999999))+'\n')
    
