#coding=utf-8
from random import randint

#n = randint(1, 99999999)
n = 100000

with open("numbers.txt", 'w') as f:
    f.write(str(n)+'\n')
    for i in range(n):
        f.write(str(randint(0, 1000000000))+'\n')
    
