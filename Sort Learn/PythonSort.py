#coding=utf-8
from time import time

print()
with open("C:\\numbers.txt", 'r') as f:
    n = int(f.readline())
    print("Number of data : "+str(n)+'\n')
    print("Reading...")
    a = [0]*n
    start = time()
    for i in range(n):
        a[i] = int(f.readline())
    stop = time()
    print(f"Read {n} data using {int((stop-start)*1000)} ms\n")

print("Sorting...")
start = time()
a.sort()
stop = time()


print(f"Sort {n} data using {int((stop-start)*1000)} ms\n")
print("Checking data...");
state = True
start = time()
for i in range(1,n):
    if (a[i]<a[i-1]):
        print("Sort failed");
        state = False
        break
stop = time()
if (state):
    print("Check pass");
print(f"Check {n} data using {int((stop-start)*1000)} ms")